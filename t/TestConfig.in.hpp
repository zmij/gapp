/**
 * @file TestConfig.in.hpp
 *
 *  Created on: 23.07.2013
 *      @author: Sergei A. Fedorov (sergei.a.fedorov at gmail dot com)
 */

#ifndef ZMIJ_GAPP_TESTCONFIG_IN_HPP_
#define ZMIJ_GAPP_TESTCONFIG_IN_HPP_

#include <string>

namespace gapp_test {

const std::string TRACK_ID = "@TRACK_ID@";

const std::string MOCK_URL = "@MOCK_URL@";

const std::string LIB_STRING = "test-@PROJECT_NAME@/@PROJECT_VERSION@ "
		"(@CMAKE_SYSTEM@; @CMAKE_SYSTEM_PROCESSOR@) "
		"boost::asio/@Boost_VERSION@ (Raw async sockets)";


} // namespace gapp_test

#endif /* ZMIJ_GAPP_TESTCONFIG_IN_HPP_ */
