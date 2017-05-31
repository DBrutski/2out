// Copyright (c) 2017 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include <Result.h>
#include <Report.h>

using namespace std;
using namespace oout;

Result::Result(
	const string &tag,
	const map<string, string> &attributes,
	const list<shared_ptr<const Result>> &nodes
)
	: tag(tag), attributes(attributes), nodes(nodes)
{
}

void Result::print(Report *report) const
{
	report->begin(tag, attributes);
	for (const auto &r : nodes) {
		r->print(report);
	}
	report->end(tag);
}

size_t Result::failures() const
{
	return stoi(attributes.at("failures"));
}