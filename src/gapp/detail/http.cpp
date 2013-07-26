/**
 * @file http.cpp
 *
 *  Created on: 24.07.2013
 *      @author: Sergei A. Fedorov (sergei.a.fedorov at gmail dot com)
 */

#include "gapp/detail/http.hpp"
#include "gapp/detail/urlencode.hpp"

#include <boost/asio.hpp>
//#include <boost/thread.hpp>

#include <stdexcept>
#include <sstream>
#include <iomanip>

namespace gapp {
namespace detail {

namespace {

const int HTTP_OK = 200;

} // namespace

namespace asio = boost::asio;
using boost::asio::ip::tcp;

Uri::Uri(std::string const& u)
{
	typedef std::string::size_type pos_type;
	pos_type pos = u.find("://");
	if (pos == std::string::npos) {
		throw std::runtime_error("Failed to parse protocol");
	}
	protocol = u.substr(0, pos);

	auto p = u.begin() + pos + 3;
	for (; p != u.end(); ++p) {
		if (is_url_symbol(*p)) {
			server_name.push_back(*p);
		} else {
			if (*p == ':') {
				++p;
				// Parse port
				for (; p != u.end() && *p != '/'; ++p) {
					port.push_back(*p);
				}
			}
			if (p != u.end()) {
				path.push_back(*p);
				++p;
			}
			break;
		}
	}

	for (; p != u.end(); ++p) {
		path.push_back(*p);
	}

	if (path.empty()) {
		path.push_back('/');
	}
}

struct RequestSender::Impl {
	std::string				postUrl;
	Uri						postUri;
	std::string				userAgent;

	asio::io_service		io_service;
	tcp::resolver::iterator	endpoint_iterator;

	Impl(std::string const& postUrl, std::string const& userAgent) :
		postUrl(postUrl), postUri(postUrl), userAgent(userAgent)
	{
		tcp::resolver resolver(io_service);
		tcp::resolver::query query( postUri.server_name, postUri.protocol );
		endpoint_iterator = resolver.resolve(query);
	}

	void
	trackHit( integer_t v, text_t const& tid, Hit const& hit,
			application_info_opt_t const& app_info,
			system_info_opt_t const& sys_info )
	{
		try {
			tcp::socket socket(io_service);
			asio::connect(socket, endpoint_iterator);

			asio::streambuf req_body;
			std::ostream req_body_stream(&req_body);

			std::ostringstream tmp;

			req_body_stream
					<< "v=" << v << "&tid=" << tid
					<< hit;

			if (app_info.is_initialized()) {
				req_body_stream << app_info.get();
			}
			if (sys_info.is_initialized()) {
				req_body_stream << sys_info.get();
			}


			std::ostream::pos_type len = req_body.size();

			req_body_stream << "\r\n\r\n";

			asio::streambuf req_header;
			std::ostream req_header_stream(&req_header);

			req_header_stream
					<< "POST " << postUri.path << " HTTP/1.1\r\n"
					<< "Host: " << postUri.server_name << "\r\n"
					<< "User-Agent: " << userAgent << "\r\n"
					<< "Content-length: " << len << "\r\n"
					<< "Connection: close\r\n"
					<< "\r\n";


			// Send the request
			asio::write( socket, req_header );
			asio::write( socket, req_body );

			#ifdef CHECK_RESPONSE
			// Check the responce
			asio::streambuf response;
			asio::read_until( socket, response, "\r\n" );

			std::istream response_stream(&response);
			std::string http_version;
			response_stream >> http_version;
			unsigned int status_code;
			response_stream >> status_code;
			std::string status_message;
			std::getline(response_stream, status_message);

			if (!response_stream || http_version.find("HTTP/") != 0) {
				throw std::runtime_error("Invalid response");
			}

			if (status_code != HTTP_OK) {
				std::ostringstream err;
				err << "Response status " << status_code << " message "
						<< status_message;

				throw std::runtime_error(err.str());
			}
			#endif /* CHECK_RESPONSE */
		} catch (std::exception const& e) {
			std::cerr << "Exception while sending hit to Google Analytics: "
					<< e.what() << "\n";
			throw;
		} catch (...) {
			std::cerr << "Unexpected exception while sending hit to Google Analytics\n";
			throw;
		}
	}
};

RequestSender::RequestSender(std::string const& postUrl,
		std::string const& userAgent) :
		pimpl_(new Impl(postUrl, userAgent))
{
}

std::string const&
RequestSender::userAgent() const
{
	return pimpl_->userAgent;
}

std::string const&
RequestSender::postUrl() const
{
	return pimpl_->postUrl;
}

void
RequestSender::trackHit( integer_t v, text_t const& tid, Hit const& hit,
		application_info_opt_t const& appInfo,
		system_info_opt_t const& sysInfo )
{
	pimpl_->trackHit(v, tid, hit, appInfo, sysInfo);
}


} // namespace detail
} // namespace gapp
