/**
 * @file urlencode.cpp
 *
 *  Created on: 24.07.2013
 *      @author: Sergei A. Fedorov (sergei.a.fedorov at gmail dot com)
 */

#include "gapp/detail/urlencode.hpp"
#include <iostream>
#include <algorithm>

namespace gapp {
namespace detail {

bool
is_url_symbol(char c)
{
	return ('0' <= c && c <= '9') ||
			('A' <= c && c <= 'Z') ||
			('a' <= c && c <= 'z') ||
			(c == '~' || c == '-' || c == '_' || c == '.');
}

inline void
output_hex(std::ostream& out, char c)
{
	char d1 = (c & 0xf0) >> 4;
	char d2 = c & 0x0f;

	if (0 <= d1 && d1 <= 9) d1 += '0';
	else if (10 <= d1 && d1 <= 15) d1 += 'A';

	if (0 <= d2 && d2 <= 9) d2 += '0';
	else if (10 <= d2 && d2 <= 15) d2 += 'A';

	out << '%' << d1 << d2;
}

std::ostream&
urlencode(std::ostream& out, std::string const& str, std::string const& ignore)
{
	for (auto p = str.begin(); p != str.end(); ++p) {
		if ( is_url_symbol(*p) || ignore.find(*p) != std::string::npos ) {
			out << *p;
		} else {
			output_hex(out, *p);
		}
	}
	return out;
}

} // namespace detail
} // namespace gapp

