/**
 * @file Types.cpp
 *
 *  Created on: 23.07.2013
 *      @author: Sergei A. Fedorov (sergei.a.fedorov at gmail dot com)
 */

#include "types.hpp"

#include <iostream>

namespace gapp {

std::ostream&
operator << (std::ostream& out, hit_type_t const& val)
{
	std::ostream::sentry s(out);
	if (s) {
		switch (val) {
		case HIT_PAGEVIEW:
			out << "pageview";
			break;
		case HIT_APPVIEW:
			out << "appview";
			break;
		case HIT_EVENT:
			out << "event";
			break;
		case HIT_TRANSACTION:
			out << "transaction";
			break;
		case HIT_ITEM:
			out << "item";
			break;
		case HIT_SOCIAL:
			out << "social";
			break;
		case HIT_EXCEPTION:
			out << "exception";
			break;
		case HIT_TIMING:
			out << "timing";
			break;
		default:
			out << "UNKNOWN " << (int)val;
			break;
		}
	}
	return out;
}


} // namespace gapp


