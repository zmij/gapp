/**
 * @file urlencode.hpp
 *
 *  Created on: 24.07.2013
 *      @author: Sergei A. Fedorov (sergei.a.fedorov at gmail dot com)
 */

#ifndef ZMIJ_GAPP_DETAIL_URLENCODE_HPP_
#define ZMIJ_GAPP_DETAIL_URLENCODE_HPP_

#include <iosfwd>
#include <string>

namespace gapp {
namespace detail {

std::ostream&
urlencode(std::ostream&, std::string const&);

bool
is_url_symbol(char c);

} // namespace detail
} // namespace gapp

#endif /* ZMIJ_GAPP_DETAIL_URLENCODE_HPP_ */
