// Copyright (c) 2017-2019 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include <memory>
#include <2out/Test.h>
#include <2out/TestSuite.h>

namespace oout {
namespace dirty {

class Test : public oout::Test {
public:
	explicit Test(const std::shared_ptr<const oout::Test> &tests);

	template<typename... T>
	Test(
		const std::shared_ptr<const oout::Test> &a,
		const std::shared_ptr<const oout::Test> &b,
		const T & ... tests
	) : Test(std::make_shared<oout::TestSuite>(a, b, tests...))
	{
	}

	std::unique_ptr<const Result> result() const override;
private:
	const std::shared_ptr<const oout::Test> tests;
};

}
}
