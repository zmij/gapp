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
#include <boost/shared_ptr.hpp>

#include <gapp/Hits.hpp>

namespace gapp {

/**
 * Class for sending tracking information to Google Analytics
 *
 * Synopsis:
 *
 * Tracker tracker("UA-XXXXXX-X");
 *
 * Event evt {...};
 * tracker.track(evt);
 */
class Tracker : boost::noncopyable {
public:
	Tracker( std::string const& trackId,
			std::string const& userAgent = std::string(),
			std::string const& postUrl = std::string(),
			integer_t version = 1 );

	void
	track(Hit const&);

	std::string const&
	trackId() const;

	std::string const&
	userAgent() const;

	std::string const&
	postUrl() const;

	system_info_opt_t&
	systemInfo();

	system_info_opt_t const&
	systemInfo() const;

	application_info_opt_t&
	applicationInfo();

	application_info_opt_t const&
	applicationInfo() const;
private:
	struct Impl;
	typedef boost::shared_ptr<Impl> PImpl;
private:
	PImpl pimpl_;
};

} // namespace gapp

#endif /* ZMIJ_GAPP_TRACKER_HPP_ */
