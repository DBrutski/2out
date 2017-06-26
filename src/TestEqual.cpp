// Copyright (c) 2017 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include <TestEqual.h>
#include <sstream>
#include <algorithm>
#include <AssertionResult.h>
#include <Success.h>
#include <Failure.h>
#include <ResSimple.h>

using namespace std;
using namespace oout;

// @todo #181:15min ReprString should be shared
class ReprString final : public Representation {
public:
	explicit ReprString(const string &value)
		: value(value)
	{
	}

	string asString() const override
	{
		return value;
	}
public:
	string value;
};

TestEqual::TestEqual(const shared_ptr<const Representation> &a, const string &b)
	: TestEqual(a, make_shared<ReprString>(b))
{
}

TestEqual::TestEqual(const shared_ptr<const Representation> &a, const shared_ptr<const Representation> &b)
	: a(a), b(b)
{
}

shared_ptr<const Result> TestEqual::result() const
{
	shared_ptr<const AssertionResult> assertion_result;
	if (a->asString() == b->asString()) {
		assertion_result = make_shared<Success>();
	} else {
		assertion_result = make_shared<Failure>();
	}

	ostringstream name_stream;
	name_stream << a->asString().substr(0, 16) << " == " << b->asString().substr(0, 16);

	const auto raw_name = name_stream.str();
	string name;
	remove_copy_if(raw_name.begin(), raw_name.end(), back_inserter(name),
		[](const string::value_type &c){
			return string("<>'").find(c) != string::npos;
		}
	);

	return make_shared<ResSimple>(name, assertion_result);
}