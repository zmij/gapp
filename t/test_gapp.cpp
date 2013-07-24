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
#include "gapp/detail/http.hpp"

BOOST_AUTO_TEST_CASE( CheckUrlParsing )
{
	{
		std::string url_str = "http://localhost:8080/test/path";

		BOOST_REQUIRE_NO_THROW( gapp::detail::Uri u(url_str) );

		gapp::detail::Uri url(url_str);

		BOOST_REQUIRE_EQUAL(url.protocol, "http");
		BOOST_REQUIRE_EQUAL(url.server_name, "localhost");
		BOOST_REQUIRE_EQUAL(url.port, "8080");
		BOOST_REQUIRE_EQUAL(url.path, "/test/path");
	}

	{
		std::string url_str = "http://localhost/test/path";

		BOOST_REQUIRE_NO_THROW( gapp::detail::Uri u(url_str) );

		gapp::detail::Uri url(url_str);

		BOOST_REQUIRE_EQUAL(url.protocol, "http");
		BOOST_REQUIRE_EQUAL(url.server_name, "localhost");
		BOOST_REQUIRE_MESSAGE(url.port.empty(), "Port must be empty");
		BOOST_REQUIRE_EQUAL(url.path, "/test/path");
	}

	{
		std::string url_str = "https://localhost";

		BOOST_REQUIRE_NO_THROW( gapp::detail::Uri u(url_str) );

		gapp::detail::Uri url(url_str);

		BOOST_REQUIRE_EQUAL(url.protocol, "https");
		BOOST_REQUIRE_EQUAL(url.server_name, "localhost");
		BOOST_REQUIRE_MESSAGE(url.port.empty(), "Port must be empty");
		BOOST_REQUIRE_EQUAL(url.path, "/");
	}

	{
		std::string url_str = "https://localhost:8080";

		BOOST_REQUIRE_NO_THROW( gapp::detail::Uri u(url_str) );

		gapp::detail::Uri url(url_str);

		BOOST_REQUIRE_EQUAL(url.protocol, "https");
		BOOST_REQUIRE_EQUAL(url.server_name, "localhost");
		BOOST_REQUIRE_EQUAL(url.port, "8080");
		BOOST_REQUIRE_EQUAL(url.path, "/");
	}

	{
		std::string url_str = "https:/localhost:8080";

		BOOST_REQUIRE_THROW( gapp::detail::Uri u(url_str), std::runtime_error);
	}

	{
		std::string url_str = "localhost:8080";

		BOOST_REQUIRE_THROW( gapp::detail::Uri u(url_str), std::runtime_error);
	}
}

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

	ApplicationInfo appInfo{
		std::string("test gapp"),
		gapp::LIB_VERSION
	};

	ContentInformation contentInfo {
		std::string( "https://github.com/zmij/gapp/" ),
        std::string( "github.com" ),
        std::string( "/zmij/gapp/" ),
        std::string( "GAPP Test" ),
        std::string( "Test Application Console" )
	};

	Tracker tracker(
			gapp_test::TRACK_ID,
			gapp_test::LIB_STRING,
			gapp_test::MOCK_URL
	);

	tracker.applicationInfo() = appInfo;

	boost::uuids::random_generator gen;
	std::ostringstream id_str;
	id_str << gen();

	Hit pageView;
	pageView.client_id = id_str.str();
	pageView.hit_type = HIT_APPVIEW;
	pageView.content_info = contentInfo;

	tracker.track(pageView);

//	std::cerr << "Sleep 10 seconds\n";
//	sleep(10);
	tracker.track(pageView);
//	std::cerr << "Sleep 10 seconds\n";
//	sleep(10);

	for (int i = 0; i < 10; ++i)
	{
		Event evt;
		evt.client_id = id_str.str();
		evt.hit_type = HIT_EVENT;

		evt.content_info = contentInfo;

		evt.event_category = "Test";
		evt.event_action = "test start";
		evt.event_label = "Run library test";

		tracker.track(evt);
//		std::cerr << "Sleep 1 second\n";
//		sleep(1);

		evt.event_action = "test stop";
		tracker.track(evt);
//		std::cerr << "Sleep 1 second\n";
//		sleep(1);
	}
	//pageView.session_control = "end";
	tracker.track(pageView);
}
