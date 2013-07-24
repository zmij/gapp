/**
 * @file Hits.hpp
 *
 *  Created on: 23.07.2013
 *      @author: Sergei A. Fedorov (sergei.a.fedorov at gmail dot com)
 */

#ifndef ZMIJ_GAPP_HITS_HPP_
#define ZMIJ_GAPP_HITS_HPP_

#include <gapp/Types.hpp>

namespace gapp {

struct SystemInfo {
	/**
	 * Screen Resolution
	 *
	 * Optional.
	 *
	 * Specifies the screen resolution.
	 *
	 * Parameter	Value Type	Default Value	Max Length	Supported Hit Types
	 * sr			text		None			20 Bytes	all
	 *
	 * Example value: 800x600
	 * Example usage: sr=800x600
	 *
	 * @see https://developers.google.com/analytics/devguides/collection/protocol/v1/parameters#sr
	 */
	text_opt_t			screen_resolution;

	/**
	 * Viewport size
	 *
	 * Optional.
	 *
	 * Specifies the viewable area of the browser / device.
	 *
	 * Parameter	Value Type	Default Value	Max Length	Supported Hit Types
	 * vp			text		None			20 Bytes	all
	 *
	 * Example value: 123x456
	 * Example usage: vp=123x456
	 *
	 * @see https://developers.google.com/analytics/devguides/collection/protocol/v1/parameters#vp
	 */
	text_opt_t			viewport_size;

	/**
	 * Document Encoding
	 *
	 * Optional.
	 *
	 * Specifies the character set used to encode the page / document.
	 *
	 * Parameter	Value Type	Default Value	Max Length	Supported Hit Types
	 * de			text		UTF-8			20 Bytes	all
	 *
	 * Example value: UTF-8
	 * Example usage: de=UTF-8
	 *
	 * @see https://developers.google.com/analytics/devguides/collection/protocol/v1/parameters#de
	 * Max length 20 bytes
	 */
	text_opt_t			document_encoding;

	/**
	 * Screen Colors
	 *
	 * Optional.
	 *
	 * Specifies the screen color depth.
	 *
	 * Parameter	Value Type	Default Value	Max Length	Supported Hit Types
	 * sd			text		None			20 Bytes	all
	 *
	 * Example value: 24-bits
	 * Example usage: sd=24-bits
	 *
	 * @see https://developers.google.com/analytics/devguides/collection/protocol/v1/parameters#sd
	 */
	text_opt_t			screen_colors;

	/**
	 * 	User Language
	 *
	 * 	Optional.
	 *
	 * 	Specifies the language.
	 *
	 * 	Parameter	Value Type	Default Value	Max Length	Supported Hit Types
	 * 	ul			text		None			20 Bytes	all
	 *
	 * 	Example value: en-us
	 * 	Example usage: ul=en-us
	 *
	 * @see https://developers.google.com/analytics/devguides/collection/protocol/v1/parameters#ul
	 */
	text_opt_t			user_language;

	/**
	 * Java Enabled
	 *
	 * Optional.
	 *
	 * Specifies whether Java was enabled.
	 *
	 * Parameter	Value Type	Default Value	Max Length	Supported Hit Types
	 * je			boolean		None			None		all
	 *
	 * Example value: 1
	 * Example usage: je=1
	 *
	 * @see https://developers.google.com/analytics/devguides/collection/protocol/v1/parameters#je
	 */
	boolean_opt_t		java_enabled;

	/**
	 * Flash Version
	 *
	 * Optional.
	 *
	 * Specifies the flash version.
	 *
	 * Parameter	Value Type	Default Value	Max Length	Supported Hit Types
	 * fl			text		None			20 Bytes	all
	 *
	 * Example value: 10 1 r103
	 * Example usage: fl=10%201%20r103
	 *
	 * @see https://developers.google.com/analytics/devguides/collection/protocol/v1/parameters#fl
	 * Max length 20 bytes
	 */
	text_opt_t			flash_version;
};

std::ostream&
operator << (std::ostream& out, SystemInfo const& val);

typedef boost::optional< SystemInfo > system_info_opt_t;

struct TrafficSources {
	/**
	 * 	Document Referrer
	 *
	 * 	Optional.
	 *
	 * 	Specifies which referral source brought traffic to a website. This
	 * 	value is also used to compute the traffic source. The format of this
	 * 	value is a URL.
	 *
	 * 	Parameter	Value Type	Default Value	Max Length	Supported Hit Types
	 * 	dr			text		None			2048 Bytes	all
	 *
	 * 	Example value: http://example.com
	 * 	Example usage: dr=http%3A%2F%2Fexample.com
	 *
	 * @see https://developers.google.com/analytics/devguides/collection/protocol/v1/parameters#dr
	 */
	text_opt_t			document_referrer;

	/**
	 * Campaign Name
	 *
	 * Optional.
	 *
	 * Specifies the campaign name.
	 *
	 * Parameter	Value Type	Default Value	Max Length	Supported Hit Types
	 * cn			text		None			100 Bytes	all
	 *
	 * Example value: (direct)
	 * Example usage: cn=%28direct%29
	 *
	 * @see https://developers.google.com/analytics/devguides/collection/protocol/v1/parameters#cn
	 */
	text_opt_t			campaign_name;

	/**
	 * Campaign Source
	 *
	 * Optional.
	 *
	 * Specifies the campaign source.
	 *
	 * Parameter	Value Type	Default Value	Max Length	Supported Hit Types
	 * cs			text		None			100 Bytes	all
	 *
	 * Example value: (direct)
	 * Example usage: cs=%28direct%29
	 *
	 * @see https://developers.google.com/analytics/devguides/collection/protocol/v1/parameters#cs
	 */
	text_opt_t			campaign_source;

	/**
	 * Campaign Medium
	 *
	 * Optional.
	 *
	 * Specifies the campaign medium.
	 *
	 * Parameter	Value Type	Default Value	Max Length	Supported Hit Types
	 * cm			text		None			50 Bytes	all
	 *
	 * Example value: organic
	 * Example usage: cm=organic
	 *
	 * @see https://developers.google.com/analytics/devguides/collection/protocol/v1/parameters#cm
	 */
	text_opt_t			campaign_medium;

	/**
	 * Campaign Keyword
	 *
	 * Optional.
	 *
	 * Specifies the campaign keyword.
	 *
	 * Parameter	Value Type	Default Value	Max Length	Supported Hit Types
	 * ck			text		None			500 Bytes	all
	 *
	 * Example value: Blue Shoes
	 * Example usage: ck=Blue%20Shoes
	 *
	 * @see https://developers.google.com/analytics/devguides/collection/protocol/v1/parameters#ck
	 */
	text_opt_t			campaign_keyword;

	/**
	 * Campaign Content
	 *
	 * Optional.
	 *
	 * Specifies the campaign content.
	 *
	 * Parameter	Value Type	Default Value	Max Length	Supported Hit Types
	 * cc			text		None			500 Bytes	all
	 *
	 * Example value: content
	 * Example usage: cc=content
	 *
	 * @see https://developers.google.com/analytics/devguides/collection/protocol/v1/parameters#cc
	 */
	text_opt_t			campaign_content;

	/**
	 * Campaign ID
	 *
	 * Optional.
	 *
	 * Specifies the campaign ID.
	 *
	 * Parameter	Value Type	Default Value	Max Length	Supported Hit Types
	 * ci			text		None			100 Bytes	all
	 *
	 * Example value: ID
	 * Example usage: ci=ID
	 *
	 * @see https://developers.google.com/analytics/devguides/collection/protocol/v1/parameters#ci
	 */
	text_opt_t			campaign_id;

	/**
	 * Google AdWords ID
	 *
	 * Optional.
	 *
	 * Specifies the Google AdWords Id.
	 *
	 * Parameter	Value Type	Default Value	Max Length	Supported Hit Types
	 * gclid		text		None			None		all
	 *
	 * Example value: CL6Q-OXyqKUCFcgK2goddQuoHg
	 * Example usage: gclid=CL6Q-OXyqKUCFcgK2goddQuoHg
	 *
	 * @see https://developers.google.com/analytics/devguides/collection/protocol/v1/parameters#gclid
	 */
	text_opt_t			gclid;

	/**
	 * Google Display Ads ID
	 *
	 * Optional.
	 *
	 * Specifies the Google Display Ads Id.
	 *
	 * Parameter	Value Type	Default Value	Max Length	Supported Hit Types
	 * dclid		text		None			None		all
	 *
	 * Example value: d_click_id
	 * Example usage: dclid=d_click_id
	 *
	 * Google Display Ads ID
	 * @see  https://developers.google.com/analytics/devguides/collection/protocol/v1/parameters#dclid
	 */
	text_opt_t			dclid;
};

std::ostream&
operator << (std::ostream& out, TrafficSources const& val);

typedef boost::optional< TrafficSources > traffic_sources_opt_t;

struct ContentInformation {
	/**
	 * Document location URL
	 *
	 * Optional.
	 *
	 * Use this parameter to send the full URL (document location) of the page
	 * on which content resides. You can use the &dh and &dp parameters to
	 * override the hostname and path + query portions of the document location,
	 * accordingly. The JavaScript clients determine this parameter using the
	 * concatenation of the document.location.origin +
	 * document.location.pathname + document.location.search browser parameters.
	 * Be sure to remove any user authentication or other private information
	 * from the URL if present.
	 *
	 * Parameter	Value Type	Default Value	Max Length	Supported Hit Types
	 * dl			text		None			2048 Bytes	all
	 *
	 * Example value: http://foo.com/home?a=b
	 * Example usage: dl=http%3A%2F%2Ffoo.com%2Fhome%3Fa%3Db
	 *
	 * @see https://developers.google.com/analytics/devguides/collection/protocol/v1/parameters#dl
	 */
	text_opt_t			document_location_url;

	/**
	 * Document Host Name
	 *
	 * Optional.
	 *
	 * Specifies the hostname from which content was hosted.
	 *
	 * Parameter	Value Type	Default Value	Max Length	Supported Hit Types
	 * dh			text		None			100 Bytes	all
	 *
	 * Example value: foo.com
	 * Example usage: dh=foo.com
	 *
	 * @see https://developers.google.com/analytics/devguides/collection/protocol/v1/parameters#dh
	 */
	text_opt_t			document_host_name;

	/**
	 * Document Path
	 *
	 * Optional.
	 *
	 * The path portion of the page URL. Should begin with '/'.
	 *
	 * Parameter	Value Type	Default Value	Max Length	Supported Hit Types
	 * dp			text		None			2048 Bytes	all
	 *
	 * Example value: /foo
	 * Example usage: dp=%2Ffoo
	 *
	 * @see https://developers.google.com/analytics/devguides/collection/protocol/v1/parameters#dp
	 */
	text_opt_t			document_path;

	/**
	 * Document Title
	 *
	 * Optional.
	 *
	 * The title of the page / document.
	 *
	 * Parameter	Value Type	Default Value	Max Length	Supported Hit Types
	 * dt			text		None			1500 Bytes	all
	 *
	 * Example value: Settings
	 * Example usage: dt=Settings
	 *
	 * @see https://developers.google.com/analytics/devguides/collection/protocol/v1/parameters#dt
	 */
	text_opt_t			document_title;

	/**
	 * Content Description
	 *
	 * Optional.
	 *
	 * If not specified, this will default to the unique URL of the page by
	 * either using the &dl parameter as-is or assembling it from &dh and &dp.
	 * App tracking makes use of this for the 'Screen Name' of the appview hit.
	 *
	 * Parameter	Value Type	Default Value	Max Length	Supported Hit Types
	 * cd			text		None			2048 Bytes	all
	 * Example value: High Scores
	 * Example usage: cd=High%20Scores
	 *
	 * @see https://developers.google.com/analytics/devguides/collection/protocol/v1/parameters#cd
	 */
	text_opt_t			content_description;
};

std::ostream&
operator << (std::ostream& out, ContentInformation const& val);

typedef boost::optional< ContentInformation > content_info_opt_t;

struct ApplicationInfo {
	//@{
	/** @name App Tracking */
	/**
	 * @see https://developers.google.com/analytics/devguides/collection/protocol/v1/parameters#an
	 * Max length 100 bytes
	 */
	text_opt_t			application_name;
	/**
	 * @see https://developers.google.com/analytics/devguides/collection/protocol/v1/parameters#av
	 * Max length 100 bytes
	 */
	text_opt_t			application_version;
	//@}
};

std::ostream&
operator << (std::ostream& out, ApplicationInfo const& val);

typedef boost::optional< ApplicationInfo > application_info_opt_t;

/**
 * Base payload type.
 * Please note that Protocol version and Tracking ID / Web property ID
 * is filled by the tracker class
 */
struct Hit {
	virtual
	~Hit() {}

	//@{
	/** @name Required parameters */
	/**
	 * Client ID
	 *
	 * Required for all hit types.
	 * This anonymously identifies a particular user, device, or browser
	 * instance. For the web, this is generally stored as a first-party
	 * cookie with a two-year expiration. For mobile apps, this is randomly
	 * generated for each particular instance of an application install.
	 * The value of this field should be a random UUID (version 4) as
	 * described in http://www.ietf.org/rfc/rfc4122.txt
	 *
	 * Parameter	Value Type	Default Value	Max Length	Supported Hit Types
	 * cid			text		None			None		all
	 *
	 * Example value: 35009a79-1a05-49d7-b876-2b884d0f825b
	 * Example usage: cid=35009a79-1a05-49d7-b876-2b884d0f825b
	 *
	 * @see https://developers.google.com/analytics/devguides/collection/protocol/v1/parameters#cid
	 */
	text_t				client_id;
	//@{
	/** @name Hit */
	/**
	 * Hit type
	 *
	 * Required for all hit types.
	 *
	 * The type of hit. Must be one of 'pageview', 'appview', 'event',
	 * 'transaction', 'item', 'social', 'exception', 'timing'.
	 * Parameter	Value Type	Default Value	Max Length	Supported Hit Types
	 * t			text		None			None		all
	 *
	 * Example value: pageview
	 * Example usage: t=pageview
	 *
	 * @see https://developers.google.com/analytics/devguides/collection/protocol/v1/parameters#t
	 */
	hit_type_t			hit_type;
	//@}
	//@}

	//@{
	/** @name Optional parameters */
	//@{
	/** @name General */
	/**
	 * Anonymize IP
	 *
	 * When present, the IP address of the sender will be anonymized. For
	 * example, the IP will be anonymized if any of the following parameters
	 * are present in the payload: &aip=, &aip=0, or &aip=1
	 *
	 * Parameter	Value Type	Default Value	Max Length	Supported Hit Types
	 * aip			boolean		None			None		all
	 *
	 * Example value: 1
	 * Example usage: aip=1
	 *
	 * @see https://developers.google.com/analytics/devguides/collection/protocol/v1/parameters#aip
	 */
	boolean_opt_t		anonymize_ip;

	/**
	 * Queue Time
	 *
	 * Used to collect offline / latent hits. The value represents the time
	 * delta (in milliseconds) between when the hit being reported occurred
	 * and the time the hit was sent. The value must be greater than or equal
	 * to 0. Values greater than four hours may lead to hits not being
	 * processed.
	 *
	 * Parameter	Value Type	Default Value	Max Length	Supported Hit Types
	 * qt			integer		None			None		all
	 *
	 * Example value: 560
	 * Example usage: qt=560
	 *
	 * @see https://developers.google.com/analytics/devguides/collection/protocol/v1/parameters#qt
	 */
	integer_opt_t		queue_time;
	/**
	 * Cache Buster
	 *
	 * Used to send a random number in GET requests to ensure browsers and
	 * proxies don't cache hits. It should be sent as the final parameter of
	 * the request since we've seen some 3rd party internet filtering software
	 * add additional parameters to HTTP requests incorrectly. This value is
	 * not used in reporting.
	 *
	 * Parameter	Value Type	Default Value	Max Length	Supported Hit Types
	 * z	text	None	None	all
	 *
	 * Example value: 289372387623
	 * Example usage: z=289372387623
	 *
	 * @see https://developers.google.com/analytics/devguides/collection/protocol/v1/parameters#z
	 */
	text_opt_t			cache_buster;
	//@}
	//@{
	/** @name Session control */
	/**
	 * Session Control
	 *
	 * Optional.
	 *
	 * Used to control the session duration. A value of 'start' forces a new
	 * session to start with this hit and 'end' forces the current session to
	 * end with this hit. All other values are ignored.
	 *
	 * Parameter	Value Type	Default Value	Max Length	Supported Hit Types
	 * sc			text		None			None		all
	 *
	 * Example value: start
	 * Example usage: sc=start
	 *
	 * Example value: end
	 * Example usage: sc=end
	 *
	 * @see https://developers.google.com/analytics/devguides/collection/protocol/v1/parameters#sc
	 */
	text_opt_t			session_control;
	//@}
	//@{
	/** @name Traffic Sources */
	traffic_sources_opt_t	traffic_sources;

	//@}
	//@{
	/** @name Hit */
	/**
	 * Non-Interaction Hit
	 *
	 * Optional.
	 *
	 * Specifies that a hit be considered non-interactive.
	 *
	 * Parameter	Value Type	Default Value	Max Length	Supported Hit Types
	 * ni			boolean		None			None		all
	 *
	 * Example value: 1
	 * Example usage: ni=1
	 *
	 * @see https://developers.google.com/analytics/devguides/collection/protocol/v1/parameters#ni
	 */
	boolean_opt_t		non_interaction_hit;
	//@}
	//@{
	/** @name Content information */
	content_info_opt_t	content_info;
	//@}

	//@{
	/** @name Custom Dimensions / Metrics */
	// @TODO Define custom dimensions and metrics
	//@}
	//@}

	void
	write(std::ostream& out) const;
private:
	virtual void
	doWrite(std::ostream& out) const {}
};

std::ostream&
operator << (std::ostream& out, Hit const& val);

/**
 * Event payload data
 */
struct Event : Hit {
	virtual
	~Event() {}

	//@{
	/** @name Requred parameters */
	/**
	 * Event Category
	 *
	 * Specifies the event category. Must not be empty.
	 *
	 * Parameter	Value Type	Default Value	Max Length	Supported Hit Types
	 * ec			text		None			150 Bytes	event
	 *
	 * Example value: Category
	 * Example usage: ec=Category
	 *
	 * @see https://developers.google.com/analytics/devguides/collection/protocol/v1/parameters#ec
	 */
	text_t				event_category;

	/**
	 * Event Action
	 *
	 * Specifies the event action. Must not be empty.
	 *
	 * Parameter	Value Type	Default Value	Max Length	Supported Hit Types
	 * ea			text		None			500 Bytes	event
	 *
	 * Example value: Action
	 * Example usage: ea=Action
	 *
	 * @see https://developers.google.com/analytics/devguides/collection/protocol/v1/parameters#ea
	 */
	text_t				event_action;
	//@}

	//@{
	/** @name Optional parameters */
	/**
	 * Event Label
	 *
	 * Optional.
	 *
	 * Specifies the event label.
	 *
	 * Parameter	Value Type	Default Value	Max Length	Supported Hit Types
	 * el			text		None			500 Bytes	event
	 *
	 * Example value: Label
	 * Example usage: el=Label
	 *
	 * @see https://developers.google.com/analytics/devguides/collection/protocol/v1/parameters#el
	 */
	text_opt_t			event_label;
	/**
	 * Event Value
	 *
	 * Optional.
	 *
	 * Specifies the event value. Values must be non-negative.
	 *
	 * Parameter	Value Type	Default Value	Max Length	Supported Hit Types
	 * ev			integer		None			None		event
	 *
	 * Example value: 55
	 * Example usage: ev=55
	 *
	 * @see https://developers.google.com/analytics/devguides/collection/protocol/v1/parameters#ev
	 */
	integer_opt_t		event_value;
	//@}
private:
	virtual void
	doWrite( std::ostream& out ) const;
};

struct EcommerceHit : Hit {
	virtual
	~EcommerceHit() {}

	//@{
	/** @name Requred parameters */
	/**
	 * Transaction ID
	 *
	 * Required for transaction hit type.
	 * Required for item hit type.
	 *
	 * A unique identifier for the transaction. This value should be the same
	 * for both the Transaction hit and Items hits associated to the particular
	 * transaction.
	 *
	 * Parameter	Value Type	Default Value	Max Length	Supported Hit Types
	 * ti			text		None			500 Bytes	transaction, item
	 *
	 * Example value: OD564
	 * Example usage: ti=OD564
	 *
	 * @see https://developers.google.com/analytics/devguides/collection/protocol/v1/parameters#ti
	 */
	text_t				transaction_id;
	//@}

	//@{
	/** @name Optional parameters */
	/**
	 * @see https://developers.google.com/analytics/devguides/collection/protocol/v1/parameters#cu
	 * Max length 10 bytes, ISO 4217
	 */
	text_opt_t			currency_code;
	//@}
protected:
	virtual void
	doWrite( std::ostream& out ) const;
};

struct Transaction : EcommerceHit {
	virtual
	~Transaction() {}

	/**
	 * Transaction Affiliation
	 *
	 * Optional.
	 *
	 * Specifies the affiliation or store name.
	 *
	 * Parameter	Value Type	Default Value	Max Length	Supported Hit Types
	 * ta			text		None			500 Bytes	transaction
	 *
	 * Example value: Member
	 * Example usage: ta=Member
	 *
	 * @see https://developers.google.com/analytics/devguides/collection/protocol/v1/parameters#ta
	 */
	text_opt_t			transaction_affiliation;

	/**
	 * Transaction Revenue
	 *
	 * Optional.
	 *
	 * Specifies the total revenue associated with the transaction. This value
	 * should include any shipping or tax costs.
	 * Parameter	Value Type	Default Value	Max Length	Supported Hit Types
	 * tr			currency	0				None		transaction
	 *
	 * Example value: 15.47
	 * Example usage: tr=15.47
	 *
	 * @see https://developers.google.com/analytics/devguides/collection/protocol/v1/parameters#tr
	 */
	currency_opt_t		transaction_revenue;

	/**
	 * Transaction Shipping
	 *
	 * Optional.
	 *
	 * Specifies the total shipping cost of the transaction.
	 * Parameter	Value Type	Default Value	Max Length	Supported Hit Types
	 * ts			currency	0				None		transaction
	 *
	 * Example value: 3.50
	 * Example usage: ts=3.50
	 *
	 * @see https://developers.google.com/analytics/devguides/collection/protocol/v1/parameters#ts
	 */
	currency_opt_t		transaction_shipping;

	/**
	 * Transaction Tax
	 *
	 * Optional.
	 *
	 * Specifies the total tax of the transaction.
	 *
	 * Parameter	Value Type	Default Value	Max Length	Supported Hit Types
	 * tt			currency	0				None		transaction
	 *
	 * Example value: 11.20
	 * Example usage: tt=11.20
	 *
	 * @see https://developers.google.com/analytics/devguides/collection/protocol/v1/parameters#tt
	 */
	currency_opt_t		transaction_tax;
private:
	virtual void
	doWrite( std::ostream& out ) const;
};

struct Item : EcommerceHit {
	virtual
	~Item() {}

	/**
	 * Item Name
	 *
	 * Required for item hit type.
	 *
	 * Specifies the item name.
	 *
	 * Parameter	Value Type	Default Value	Max Length	Supported Hit Types
	 * in			text		None			500 Bytes	item
	 *
	 * Example value: Shoe
	 * Example usage: in=Shoe
	 *
	 * @see https://developers.google.com/analytics/devguides/collection/protocol/v1/parameters#in
	 */
	text_t				item_name;

	/**
	 * Item Price
	 *
	 * Optional.
	 *
	 * Specifies the price for a single item / unit.
	 *
	 * Parameter	Value Type	Default Value	Max Length	Supported Hit Types
	 * ip			currency	0				None		item
	 *
	 * Example value: 3.50
	 * Example usage: ip=3.50
	 *
	 * @see https://developers.google.com/analytics/devguides/collection/protocol/v1/parameters#ip
	 */
	currency_opt_t		item_price;

	/**
	 * Item Quantity
	 *
	 * Optional.
	 *
	 * Specifies the number of items purchased.
	 *
	 * Parameter	Value Type	Default Value	Max Length	Supported Hit Types
	 * iq			integer		0				None		item
	 *
	 * Example value: 4
	 * Example usage: iq=4
	 *
	 * @see https://developers.google.com/analytics/devguides/collection/protocol/v1/parameters#iq
	 */
	integer_opt_t		item_quantity;

	/**
	 * Item Code
	 *
	 * Optional.
	 *
	 * Specifies the SKU or item code.
	 *
	 * Parameter	Value Type	Default Value	Max Length	Supported Hit Types
	 * ic			text		None			500 Bytes	item
	 *
	 * Example value: SKU47
	 * Example usage: ic=SKU47
	 *
	 * @see https://developers.google.com/analytics/devguides/collection/protocol/v1/parameters#ic
	 */
	text_opt_t			item_code;

	/**
	 * Item Category
	 *
	 * Optional.
	 *
	 * Specifies the category that the item belongs to.
	 *
	 * Parameter	Value Type	Default Value	Max Length	Supported Hit Types
	 * iv			text		None			500 Bytes	item
	 *
	 * Example value: Blue
	 * Example usage: iv=Blue
	 *
	 * @see https://developers.google.com/analytics/devguides/collection/protocol/v1/parameters#iv
	 */
	text_opt_t			item_category;
private:
	virtual void
	doWrite( std::ostream& out ) const;
};

struct Social : Hit {
	virtual
	~Social() {}

	/**
	 * Social Network
	 *
	 * Required for social hit type.
	 *
	 * Specifies the social network, for example Facebook or Google Plus.
	 *
	 * Parameter	Value Type	Default Value	Max Length	Supported Hit Types
	 * sn			text		None			50 Bytes	social
	 *
	 * Example value: facebook
	 * Example usage: sn=facebook
	 *
	 * @see https://developers.google.com/analytics/devguides/collection/protocol/v1/parameters#sn
	 */
	text_t				social_network;

	/**
	 * Social Action
	 *
	 * Required for social hit type.
	 *
	 * Specifies the social interaction action. For example on Google Plus
	 * when a user clicks the +1 button, the social action is 'plus'.
	 *
	 * Parameter	Value Type	Default Value	Max Length	Supported Hit Types
	 * sa			text		None			50 Bytes	social
	 *
	 * Example value: like
	 * Example usage: sa=like
	 *
	 * @see https://developers.google.com/analytics/devguides/collection/protocol/v1/parameters#sa
	 */
	text_t				social_action;

	/**
	 *  Social Action Target
	 *
	 *  Required for social hit type.
	 *
	 *  Specifies the target of a social interaction. This value is typically
	 *  a URL but can be any text.
	 *
	 *  Parameter	Value Type	Default Value	Max Length	Supported Hit Types
	 *  st			text		None			2048 Bytes	social
	 *
	 *  Example value: http://foo.com
	 *  Example usage: st=http%3A%2F%2Ffoo.com
	 *
	 * @see https://developers.google.com/analytics/devguides/collection/protocol/v1/parameters#st
	 */
	text_t				social_action_target;
private:
	virtual void
	doWrite( std::ostream& out ) const;
};

struct Timing : Hit {
	virtual
	~Timing() {}

	/**
	 * User timing category
	 *
	 * Optional.
	 *
	 * Specifies the user timing category.
	 *
	 * Parameter	Value Type	Default Value	Max Length	Supported Hit Types
	 * utc			text		None			150 Bytes	timing
	 *
	 * Example value: category
	 * Example usage: utc=category
	 */
	text_opt_t			timing_category;

	/**
	 *  User timing variable name
	 *
	 *  Optional.
	 *
	 *  Specifies the user timing variable.
	 *
	 *  Parameter	Value Type	Default Value	Max Length	Supported Hit Types
	 *  utv			text		None			500 Bytes	timing
	 *
	 *  Example value: lookup
	 *  Example usage: utv=lookup
	 */
	text_opt_t			timing_variable_name;

	/**
	 *  User timing time
	 *
	 *  Optional.
	 *
	 *  Specifies the user timing value. The value is in milliseconds.
	 *
	 *  Parameter	Value Type	Default Value	Max Length	Supported Hit Types
	 *  utt			integer		None			None		timing
	 *
	 *  Example value: 123
	 *  Example usage: utt=123
	 */
	integer_opt_t		timing_time;

	/**
	 *  User timing label
	 *
	 *  Optional.
	 *
	 *  Specifies the user timing label.
	 *
	 *  Parameter	Value Type	Default Value	Max Length	Supported Hit Types
	 *  utl			text		None			500 Bytes	timing
	 *
	 *  Example value: label
	 *  Example usage: utl=label
	 */
	text_opt_t			timing_label;

	/**
	 *  Page Load Time
	 *
	 *  Optional.
	 *
	 *  Specifies the time it took for a page to load. The value is in milliseconds.
	 *
	 *  Parameter	Value Type	Default Value	Max Length	Supported Hit Types
	 *  plt			integer		None			None		timing
	 *
	 *  Example value: 3554
	 *  Example usage: plt=3554
	 */
	integer_opt_t		page_load_time;

	/**
	 * DNS Time
	 *
	 * Optional.
	 *
	 * Specifies the time it took to do a DNS lookup.The value is in milliseconds.
	 *
	 * Parameter	Value Type	Default Value	Max Length	Supported Hit Types
	 * dns			integer		None			None		timing
	 *
	 * Example value: 43
	 * Example usage: dns=43
	 */
	integer_opt_t		dns_time;

	/**
	 *  Page Download Time
	 *
	 *  Optional.
	 *
	 *  Specifies the time it took for the page to be downloaded. The value is
	 *  in milliseconds.
	 *
	 *  Parameter	Value Type	Default Value	Max Length	Supported Hit Types
	 *  pdt			integer		None			None		timing
	 *
	 *  Example value: 500
	 *  Example usage: pdt=500
	 */
	integer_opt_t		page_download_time;

	/**
	 * Redirect Response Time
	 *
	 * Optional.
	 *
	 * Specifies the time it took for any redirects to happen. The value is in
	 * milliseconds.
	 *
	 * Parameter	Value Type	Default Value	Max Length	Supported Hit Types
	 * rrt			integer		None			None		timing
	 *
	 * Example value: 500
	 * Example usage: rrt=500
	 */
	integer_opt_t		redirect_responce_time;

	/**
	 * TCP Connect Time
	 *
	 * Optional.
	 *
	 * Specifies the time it took for a TCP connection to be made. The value is
	 * in milliseconds.
	 *
	 * Parameter	Value Type	Default Value	Max Length	Supported Hit Types
	 * tcp			integer		None			None		timing
	 *
	 * Example value: 500
	 * Example usage: tcp=500
	 */
	integer_opt_t		tcp_connect_time;

	/**
	 * Server Response Time
	 *
	 * Optional.
	 *
	 * Specifies the time it took for the server to respond after the connect
	 * time. The value is in milliseconds.
	 *
	 * Parameter	Value Type	Default Value	Max Length	Supported Hit Types
	 * srt			integer		None			None		timing
	 *
	 * Example value: 500
	 * Example usage: srt=500
	 */
	integer_opt_t		server_responce_time;
private:
	virtual void
	doWrite( std::ostream& out ) const;
};

struct Exception : Hit {
	virtual
	~Exception() {}

	/**
	 * Exception Description
	 *
	 * Optional.
	 *
	 * Specifies the description of an exception.
	 *
	 * Parameter	Value Type	Default Value	Max Length	Supported Hit Types
	 * exd			text		None			150 Bytes	exception
	 *
	 * Example value: DatabaseError
	 * Example usage: exd=DatabaseError
	 */
	text_opt_t			exception_description;

	/**
	 * Is Exception Fatal?
	 *
	 * Optional.
	 *
	 * Specifies whether the exception was fatal.
	 *
	 * Parameter	Value Type	Default Value	Max Length	Supported Hit Types
	 * exf			boolean		1				None		exception
	 *
	 * Example value: 0
	 * Example usage: exf=0
	 */
	boolean_opt_t		is_fatal;
private:
	virtual void
	doWrite( std::ostream& out ) const;
};

} // namespace gapp

#endif /* ZMIJ_GAPP_HITS_HPP_ */
