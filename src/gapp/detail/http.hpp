/**
 * @file http.hpp
 *
 *  Created on: 24.07.2013
 *      @author: Sergei A. Fedorov (sergei.a.fedorov at gmail dot com)
 */

#ifndef GAPP_DETAIL_HTTP_HPP_
#define GAPP_DETAIL_HTTP_HPP_

#include <string>
#include <memory>

#include <gapp/types.hpp>
#include <gapp/hits.hpp>

namespace gapp {
namespace detail {

struct Uri {
	std::string				protocol;
	std::string				server_name;
	std::string				port;
	std::string				path;

	Uri(std::string const& u);
};

class RequestSender {
public:
	RequestSender(std::string const& postUrl, std::string const& userAgent);

	std::string const&
	userAgent() const;

	std::string const&
	postUrl() const;

	void
	trackHit( integer_t v, text_t const& tid, Hit const& hit,
			application_info_opt_t const& appInfo,
			system_info_opt_t const& sysInfo );
private:
	struct impl;
	typedef std::shared_ptr<impl> pimpl;
private:
	pimpl pimpl_;
};

} // namespace detail
} // namespace gapp

#endif /* GAPP_DETAIL_HTTP_HPP_ */
