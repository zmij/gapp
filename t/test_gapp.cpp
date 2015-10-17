/**
 * @file gapp_test.cpp
 *
 *  Created on: 23.07.2013
 *      @author: Sergei A. Fedorov (sergei.a.fedorov at gmail dot com)
 */

#include "test_config.hpp"

#define BOOST_TEST_MODULE TestGapp

#include <boost/test/unit_test.hpp>

#include <boost/asio/ip/host_name.hpp>
#include <boost/functional/hash.hpp>

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
	gapp::tracker defaults(gapp_test::TRACK_ID);

	BOOST_REQUIRE_EQUAL(defaults.track_id(), gapp_test::TRACK_ID);
	BOOST_REQUIRE_EQUAL(defaults.user_agent(), gapp::LIB_STRING);
	BOOST_REQUIRE_EQUAL(defaults.post_url(), gapp::DEFAULT_POST_URL);

	gapp::tracker track(
			gapp_test::TRACK_ID,
			gapp_test::LIB_STRING,
			gapp_test::MOCK_URL
	);

	BOOST_REQUIRE_EQUAL(track.track_id(), gapp_test::TRACK_ID);
	BOOST_REQUIRE_EQUAL(track.user_agent(), gapp_test::LIB_STRING);
	BOOST_REQUIRE_EQUAL(track.post_url(), gapp_test::MOCK_URL);

	BOOST_REQUIRE_THROW( gapp::tracker(""), std::runtime_error );
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

	tracker track(
			gapp_test::TRACK_ID,
			gapp_test::LIB_STRING,
			gapp_test::MOCK_URL
	);

	track.application_info() = appInfo;

	std::string hostName = boost::asio::ip::host_name();
	boost::hash< std::string > string_hash;

	std::ostringstream id_str;
	id_str << string_hash(hostName);
	std::string clientId = id_str.str();
	
	std::cerr << "Hostname " << hostName << " client id " << clientId << "\n";

	Hit pageView;
	pageView.client_id = clientId;
	pageView.hit_type = HIT_APPVIEW;
	pageView.content_info = contentInfo;

	track.track(pageView);

	tracker.track(pageView);

	Event evt;
	evt.client_id = clientId;
	evt.hit_type = HIT_EVENT;

	evt.content_info = contentInfo;

	evt.event_category = "Test";
	evt.event_label = "Run library test";

	for (int i = 0; i < 10; ++i)
	{
		evt.event_action = "test start";

		tracker.track(evt);

		evt.event_action = "test stop";
		tracker.track(evt);
	}
	//pageView.session_control = "end";
	tracker.track(pageView);
	evt.event_action = "test finish";
	tracker.track(evt);
}
