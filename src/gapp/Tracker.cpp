/**
 * @file Tracker.cpp
 *
 *  Created on: 23.07.2013
 *      @author: Sergei A. Fedorov (sergei.a.fedorov at gmail dot com)
 */

#include "tracker.hpp"
#include <gapp/config.hpp>

#include <gapp/detail/http.hpp>

#include <stdexcept>
#include <iostream>
#include <sstream>

namespace gapp {

namespace {

const std::string DEFAULT_USER_AGENT = LIB_STRING;

} // namespace

struct tracker::impl {
	detail::RequestSender	requestSender;

	std::string				trackId;
	integer_t				version;

	application_info_opt_t	appInfo;
	system_info_opt_t		sysInfo;

	impl(std::string const& 	tId,
		std::string const& 		uAgent,
		std::string const& 		pUrl,
		integer_t 				v) :
		requestSender( (pUrl.empty() ? DEFAULT_POST_URL : pUrl),
				(uAgent.empty() ? DEFAULT_USER_AGENT : uAgent)),
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
		requestSender.trackHit(version, trackId, hit, appInfo, sysInfo);
	}
};

tracker::tracker( std::string const& tId,
		std::string const& uAgent,
		std::string const& pUrl,
		integer_t v ) :
				pimpl_( new impl(tId, uAgent, pUrl, v) )
{
}

void
tracker::track(Hit const& hit)
{
	pimpl_->track(hit);
}

std::string const&
tracker::track_id() const
{
	return pimpl_->trackId;
}

std::string const&
tracker::user_agent() const
{
	return pimpl_->requestSender.userAgent();
}

std::string const&
tracker::post_url() const
{
	return pimpl_->requestSender.postUrl();
}

system_info_opt_t&
tracker::system_info()
{
	return pimpl_->sysInfo;
}

system_info_opt_t const&
tracker::system_info() const
{
	return pimpl_->sysInfo;
}

application_info_opt_t&
tracker::application_info()
{
	return pimpl_->appInfo;
}

application_info_opt_t const&
tracker::application_info() const
{
	return pimpl_->appInfo;
}


} // namespace gapp
