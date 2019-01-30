// Copyright (c) 2017-2019 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "TestTimed.h"
#include <chrono>
#include "ResTimed.h"

using namespace std;
using namespace oout;

TestTimed::TestTimed(const shared_ptr<const Test> &test)
	: test(test)
{
}

unique_ptr<const Result> TestTimed::result() const
{
	const auto begin = chrono::high_resolution_clock::now();
	const shared_ptr<const Result> result = test->result();
	const auto end = chrono::high_resolution_clock::now();
	return make_unique<const ResTimed>(result, end - begin);
}
