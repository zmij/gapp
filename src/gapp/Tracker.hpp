/**
 * @file Tracker.hpp
 *
 *  Created on: 23.07.2013
 *      @author: Sergei A. Fedorov (sergei.a.fedorov at gmail dot com)
 */

#ifndef ZMIJ_GAPP_TRACKER_HPP_
#define ZMIJ_GAPP_TRACKER_HPP_

#include <string>

#include <boost/noncopyable.hpp>
#include <memory>

#include <gapp/hits.hpp>

namespace gapp {

/**
 * Class for sending tracking information to Google Analytics
 *
 * Synopsis:
 *
 * tracker track("UA-XXXXXX-X");
 *
 * Event evt {...};
 * tracker.track(evt);
 */
class tracker : boost::noncopyable {
public:
	tracker( std::string const& trackId,
			std::string const& userAgent = std::string(),
			std::string const& postUrl = std::string(),
			integer_t version = 1 );

	void
	track(Hit const&) const;

	std::string const&
	track_id() const;

	std::string const&
	user_agent() const;

	std::string const&
	post_url() const;

	system_info_opt_t&
	system_info();

	system_info_opt_t const&
	system_info() const;

	application_info_opt_t&
	application_info();

	application_info_opt_t const&
	application_info() const;
private:
	struct impl;
	typedef std::shared_ptr<impl> pimpl;
private:
	pimpl pimpl_;
};

} // namespace gapp

#endif /* ZMIJ_GAPP_TRACKER_HPP_ */
