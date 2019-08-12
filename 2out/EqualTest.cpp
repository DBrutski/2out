// Copyright (c) 2017-2019 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "EqualTest.h"
#include <sstream>
#include <algorithm>
#include "Failure.h"
#include "ReprString.h"
#include "ResTest.h"
#include "Success.h"

using namespace std;
using namespace oout;

EqualTest::EqualTest(const string &a, const string &b)
	: EqualTest(make_shared<ReprString>(a), make_shared<ReprString>(b))
{
}

EqualTest::EqualTest(const string &a, const shared_ptr<const Text> &b)
	: EqualTest(make_shared<ReprString>(a), b)
{
}

EqualTest::EqualTest(const shared_ptr<const Text> &a, const string &b)
	: EqualTest(a, make_shared<ReprString>(b))
{
}

EqualTest::EqualTest(const shared_ptr<const Text> &a, const shared_ptr<const Text> &b)
	: a(a), b(b)
{
}

unique_ptr<const Result> EqualTest::result() const
{
	ostringstream text;
	text << "'" << a->asString() << "' is equal '" << b->asString() << "'";

	shared_ptr<const Result> assertion_result;
	if (a->asString() == b->asString()) {
		assertion_result = make_shared<Success>(text.str());
	} else {
		assertion_result = make_shared<Failure>(text.str());
	}
	return make_unique<ResTest>(assertion_result);
}
