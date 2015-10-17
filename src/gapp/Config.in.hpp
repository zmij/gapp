/**
 * @file Config.in.hpp
 *
 *  Created on: 23.07.2013
 *      @author: Sergei A. Fedorov (sergei.a.fedorov at gmail dot com)
 */

#ifndef ZMIJ_GAPP_CONFIG_IN_HPP_
#define ZMIJ_GAPP_CONFIG_IN_HPP_

#include <string>

namespace gapp {

const std::string DEFAULT_POST_URL = "@GOOGLE_POST_URL@";
const std::string LIB_STRING = "@PROJECT_NAME@/@PROJECT_VERSION@ "
		"(@CMAKE_SYSTEM@; @CMAKE_SYSTEM_PROCESSOR@) "
		"boost::asio/@Boost_VERSION@ (Raw async sockets)";

const std::string LIB_VERSION = "@PROJECT_VERSION@";

} // namespace gapp

#endif /* ZMIJ_GAPP_CONFIG_IN_HPP_ */
