/**
 * @file Hits.cpp
 *
 *  Created on: 23.07.2013
 *      @author: Sergei A. Fedorov (sergei.a.fedorov at gmail dot com)
 */

#include "hits.hpp"
#include "gapp/detail/urlencode.hpp"

#include <iostream>

namespace gapp {

namespace {

const std::string IGNORE_IN_PATH = "/";

} // namespace

template < typename T >
void
output_val(std::ostream& out, T val)
{
	out << val;
}

void
output_val(std::ostream& out, bool val)
{
	out << (val ? 1 : 0);
}

void
output_val(std::ostream& out, std::string const& val)
{
	detail::urlencode(out, val);
}

template < typename T >
void
output_param(std::ostream& out, std::string const& name, T const& p)
{
	out << "&" << name << "=";
	output_val(out, p);
}

template < typename T >
void
output_param(std::ostream& out, std::string const& name, boost::optional< T > const& p)
{
	if (p.is_initialized()) {
		out << "&" << name << "=";
		output_val(out, p.get());
	}
}

void
output_param(std::ostream& out, std::string const& name, text_opt_t const& p,
		std::string const& ignore)
{
	if (p.is_initialized()) {
		out << "&" << name << "=";
		detail::urlencode(out, p.get(), ignore);
	}
}

std::ostream&
operator << (std::ostream& out, SystemInfo const& val)
{
	std::ostream::sentry s(out);
	if (s) {
		output_param(out, "sr", val.screen_resolution);
		output_param(out, "vp", val.viewport_size);
		output_param(out, "de", val.document_encoding);
		output_param(out, "sd", val.screen_colors);
		output_param(out, "ul", val.user_language);
		output_param(out, "je", val.java_enabled);
		output_param(out, "fl", val.flash_version);
	}
	return out;
}

std::ostream&
operator << (std::ostream& out, TrafficSources const& val)
{
	std::ostream::sentry s(out);
	if (s) {
		output_param(out, "dr", val.document_referrer);
		output_param(out, "cn", val.campaign_name);
		output_param(out, "cs", val.campaign_source);
		output_param(out, "cm", val.campaign_medium);
		output_param(out, "ck", val.campaign_keyword);
		output_param(out, "cc", val.campaign_content);
		output_param(out, "ci", val.campaign_id);
		output_param(out, "gclid", val.gclid);
		output_param(out, "dclid", val.dclid);
	}
	return out;
}

std::ostream&
operator << (std::ostream& out, ContentInformation const& val)
{
	std::ostream::sentry s(out);
	if (s) {
		output_param(out, "dl", val.document_location_url, IGNORE_IN_PATH);
		output_param(out, "dh", val.document_host_name);
		output_param(out, "dp", val.document_path, IGNORE_IN_PATH);
		output_param(out, "dt", val.document_title);
		output_param(out, "cd", val.content_description);

	}
	return out;
}

std::ostream&
operator << (std::ostream& out, ApplicationInfo const& val)
{
	std::ostream::sentry s(out);
	if (s) {
		output_param(out, "an", val.application_name);
		output_param(out, "av", val.application_version);
	}
	return out;
}

void
Hit::write(std::ostream& out) const
{
	output_param(out, "cid", client_id);
	output_param(out, "t", hit_type);

	output_param(out, "ai", anonymize_ip);
	output_param(out, "qt", queue_time);
	output_param(out, "z", cache_buster);

	output_param(out, "sc", session_control);

	if (traffic_sources.is_initialized()) {
		out << traffic_sources.get();
	}

	output_param(out, "ni", non_interaction_hit);

	if (content_info.is_initialized()) {
		out << content_info.get();
	}

	// TODO Custom metrics and dimensions

	doWrite(out);
}

std::ostream&
operator << (std::ostream& out, Hit const& val)
{
	std::ostream::sentry s(out);
	if (s) {
		val.write(out);
	}
	return out;
}

void
Event::doWrite(std::ostream& out) const
{
	output_param(out, "ec", event_category);
	output_param(out, "ea", event_action);
	output_param(out, "el", event_label);
	output_param(out, "ev", event_value);
}

void
EcommerceHit::doWrite(std::ostream& out) const
{
	output_param(out, "ti", transaction_id);
	output_param(out, "cu", currency_code);
}

void
Transaction::doWrite(std::ostream& out) const
{
	EcommerceHit::doWrite(out);
	output_param(out, "ta", transaction_affiliation);
	output_param(out, "tr", transaction_revenue);
	output_param(out, "ts", transaction_shipping);
	output_param(out, "tt", transaction_tax);
}

void
Item::doWrite(std::ostream& out) const
{
	EcommerceHit::doWrite(out);
	output_param(out, "in", item_name);
	output_param(out, "ip", item_price);
	output_param(out, "iq", item_quantity);
	output_param(out, "ic", item_code);
	output_param(out, "iv", item_category);
}

void
Social::doWrite(std::ostream& out) const
{
	output_param(out, "sn", social_network);
	output_param(out, "sa", social_action);
	output_param(out, "st", social_action_target);
}

void
Timing::doWrite(std::ostream& out) const
{
	output_param(out, "utc", timing_category);
	output_param(out, "utv", timing_variable_name);
	output_param(out, "utt", timing_time);
	output_param(out, "utl", timing_label);
	output_param(out, "plt", page_load_time);
	output_param(out, "dns", dns_time);
	output_param(out, "pdt", page_download_time);
	output_param(out, "rrt", redirect_responce_time);
	output_param(out, "tcp", tcp_connect_time);
	output_param(out, "srt", server_responce_time);
}

void
Exception::doWrite(std::ostream& out) const
{
	output_param(out, "exd", exception_description);
	output_param(out, "exf", is_fatal);
}

} // namespace gapp
