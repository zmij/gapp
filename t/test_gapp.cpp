/**
 * @file gapp_test.cpp
 *
 *  Created on: 23.07.2013
 *      @author: Sergei A. Fedorov (sergei.a.fedorov at gmail dot com)
 */

#include "TestConfig.hpp"

#define BOOST_TEST_MODULE TestGapp

#include <boost/test/unit_test.hpp>
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_io.hpp>
#include <boost/uuid/random_generator.hpp>

#include "gapp/Config.hpp"
#include "gapp/gapp.hpp"

BOOST_AUTO_TEST_CASE( CheckTrackerConstruction )
{
	gapp::Tracker defaults(gapp_test::TRACK_ID);

	BOOST_REQUIRE_EQUAL(defaults.trackId(), gapp_test::TRACK_ID);
	BOOST_REQUIRE_EQUAL(defaults.userAgent(), gapp::LIB_STRING);
	BOOST_REQUIRE_EQUAL(defaults.postUrl(), gapp::DEFAULT_POST_URL);

	gapp::Tracker tracker(
			gapp_test::TRACK_ID,
			gapp_test::LIB_STRING,
			gapp_test::MOCK_URL
	);

	BOOST_REQUIRE_EQUAL(tracker.trackId(), gapp_test::TRACK_ID);
	BOOST_REQUIRE_EQUAL(tracker.userAgent(), gapp_test::LIB_STRING);
	BOOST_REQUIRE_EQUAL(tracker.postUrl(), gapp_test::MOCK_URL);

	BOOST_REQUIRE_THROW( gapp::Tracker(""), std::runtime_error );
}

BOOST_AUTO_TEST_CASE( CheckTracking )
{
	using namespace gapp;

	Tracker tracker(
			gapp_test::TRACK_ID,
			gapp_test::LIB_STRING,
			gapp_test::MOCK_URL
	);

	boost::uuids::random_generator gen;
	std::ostringstream id_str;
	id_str << gen();

	Hit pageView;
	pageView.client_id = id_str.str();
	pageView.hit_type = HIT_PAGEVIEW;

	tracker.track(pageView);

	tracker.systemInfo() = SystemInfo{
		std::string{ "800x600" }
	};
	tracker.track(pageView);

	{
		Event evt;
		evt.client_id = id_str.str();
		evt.hit_type = HIT_EVENT;

		evt.event_category = "Quest";
		evt.event_action = "quest start";
		evt.event_label = "Very long quest (Find the Answer to the Ultimate Question of Life, the Universe, and Everything)";

		tracker.track(evt);

		evt.event_action = "quest stop (100%)";
		tracker.track(evt);
	}
}
