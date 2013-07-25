/**
 * @file Tracker.cpp
 *
 *  Created on: 23.07.2013
 *      @author: Sergei A. Fedorov (sergei.a.fedorov at gmail dot com)
 */

#include "gapp/Tracker.hpp"
#include "gapp/Config.hpp"

#include "gapp/detail/http.hpp"

#include <stdexcept>
#include <iostream>
#include <sstream>

namespace gapp {

namespace {

const std::string DEFAULT_USER_AGENT = LIB_STRING;

} // namespace

struct Tracker::Impl {
	detail::RequestSender	requestSender;

	std::string				trackId;
	integer_t				version;

	application_info_opt_t	appInfo;
	system_info_opt_t		sysInfo;

	Impl(std::string const& 	tId,
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

Tracker::Tracker( std::string const& tId,
		std::string const& uAgent,
		std::string const& pUrl,
		integer_t v ) :
				pimpl_( new Impl(tId, uAgent, pUrl, v) )
{
}

void
Tracker::track(Hit const& hit) const
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
	return pimpl_->requestSender.userAgent();
}

std::string const&
Tracker::postUrl() const
{
	return pimpl_->requestSender.postUrl();
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

application_info_opt_t&
Tracker::applicationInfo()
{
	return pimpl_->appInfo;
}

application_info_opt_t const&
Tracker::applicationInfo() const
{
	return pimpl_->appInfo;
}


} // namespace gapp
