/**
 * @file urlencode.hpp
 *
 *  Created on: 24.07.2013
 *      @author: Sergei A. Fedorov (sergei.a.fedorov at gmail dot com)
 */

#ifndef ZMIJ_GAPP_URLENCODE_HPP_
#define ZMIJ_GAPP_URLENCODE_HPP_

#include <iosfwd>
#include <string>

namespace gapp {

std::ostream&
urlencode(std::ostream&, std::string const&);

} // namespace gapp

#endif /* ZMIJ_GAPP_URLENCODE_HPP_ */
