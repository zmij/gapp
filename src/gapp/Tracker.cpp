/**
 * @file Tracker.cpp
 *
 *  Created on: 23.07.2013
 *      @author: Sergei A. Fedorov (sergei.a.fedorov at gmail dot com)
 */

#include "gapp/Tracker.hpp"
#include "gapp/Config.hpp"

#include <stdexcept>
#include <iostream>
#include <sstream>

namespace gapp {

namespace {

const std::string DEFAULT_USER_AGENT = LIB_STRING;

} // namespace

struct Tracker::Impl {
	std::string			userAgent;
	std::string			postUrl;

	std::string			trackId;
	integer_t			version;

	system_info_opt_t	sysInfo;

	Impl(std::string const& 	tId,
		std::string const& 		uAgent,
		std::string const& 		pUrl,
		integer_t 				v) :
		userAgent( uAgent.empty() ? DEFAULT_USER_AGENT : uAgent ),
		postUrl( pUrl.empty() ? DEFAULT_POST_URL : pUrl),
		trackId( tId ),
		version( v )
	{
		if (tId.empty()) {
			throw std::runtime_error("No track id specified");
		}
		if (version < 1) {
			throw std::runtime_error("Invalid protocol version");
		}
	}

	void
	track(Hit const& hit)
	{
		// Create request and send it to the collector
		std::ostringstream req;
		req << "User-Agent: " << userAgent << "\n"
			<< "POST " << postUrl << "\n"
			<< "v=" << version << "&tid=" << trackId
			<< hit;

		if (sysInfo.is_initialized()) {
			req << sysInfo.get();
		}

		std::cerr << "Tracking request:\n" << req.str() << "\n";
	}
};

Tracker::Tracker( std::string const& tId,
		std::string const& uAgent,
		std::string const& pUrl,
		integer_t v ) :
				pimpl_( new Impl(tId, uAgent, pUrl, v) )
{
}

void
Tracker::track(Hit const& hit)
{
	pimpl_->track(hit);
}

std::string const&
Tracker::trackId() const
{
	return pimpl_->trackId;
}

std::string const&
Tracker::userAgent() const
{
	return pimpl_->userAgent;
}

std::string const&
Tracker::postUrl() const
{
	return pimpl_->postUrl;
}

system_info_opt_t&
Tracker::systemInfo()
{
	return pimpl_->sysInfo;
}

system_info_opt_t const&
Tracker::systemInfo() const
{
	return pimpl_->sysInfo;
}


} // namespace gapp
