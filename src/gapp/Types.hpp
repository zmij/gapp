/**
 * @file Types.hpp
 *
 *  Created on: 23.07.2013
 *      @author: Sergei A. Fedorov (sergei.a.fedorov at gmail dot com)
 */

#ifndef ZMIJ_GAPP_TYPES_HPP_
#define ZMIJ_GAPP_TYPES_HPP_

#include <string>
#include <cinttypes>
#include <boost/optional.hpp>
#include <iosfwd>

namespace gapp {

//@{
/** @name Google Analytics supported datatypes */
/**
 * Text datatype
 * @see https://developers.google.com/analytics/devguides/collection/protocol/v1/reference#text
 */
typedef std::string						text_t;
typedef boost::optional< text_t >		text_opt_t;
/**
 * Currency datatype
 * @see https://developers.google.com/analytics/devguides/collection/protocol/v1/reference#currency
 */
typedef std::string						currency_t;
typedef boost::optional< currency_t >	currency_opt_t;
/**
 * Boolean datatype
 * @see https://developers.google.com/analytics/devguides/collection/protocol/v1/reference#bool
 */
typedef bool							boolean_t;
typedef boost::optional< boolean_t >	boolean_opt_t;
/**
 * Integer datatype
 * @see https://developers.google.com/analytics/devguides/collection/protocol/v1/reference#integer
 */
typedef int64_t							integer_t;
typedef boost::optional< integer_t >	integer_opt_t;
//@}

/**
 * Hit type
 */
enum hit_type_t {
	HIT_PAGEVIEW,   //!< HIT_PAGEVIEW
	HIT_APPVIEW,    //!< HIT_APPVIEW
	HIT_EVENT,      //!< HIT_EVENT
	HIT_TRANSACTION,//!< HIT_TRANSACTION
	HIT_ITEM,       //!< HIT_ITEM
	HIT_SOCIAL,     //!< HIT_SOCIAL
	HIT_EXCEPTION,  //!< HIT_EXCEPTION
	HIT_TIMING      //!< HIT_TIMING
};

std::ostream&
operator << (std::ostream& out, hit_type_t const& val);

} // namespace gapp

#endif /* ZMIJ_GAPP_TYPES_HPP_ */
