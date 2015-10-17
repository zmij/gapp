/**
 * @file asio_config.hpp
 *
 *  Created on: 17.10.2015
 *      @author: Sergei A. Fedorov (sergei.a.fedorov at gmail dot com)
 */

#ifndef GAPP_ASIO_CONFIG_HPP_HPP
#define GAPP_ASIO_CONFIG_HPP_HPP

#ifdef STANDALONE_ASIO
#include <asio.hpp>
#else
#include <boost/asio.hpp>
#endif

namespace gapp {

#ifdef STANDALONE_ASIO
    namespace asio = ::asio;
    typedef asio::system_error system_error;
    typedef asio::error_code error_code;
#else
    namespace asio = ::boost::asio;
    typedef ::boost::system::system_error system_error;
    typedef ::boost::system::error_code error_code;
#endif


} // namespace gapp

#endif //GAPP_ASIO_CONFIG_HPP_HPP
