// Copyright (c) 2017-2020 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include <memory>
#include <2out/Test.h>

class SuiteTestTest final : public oout::Test {
public:
	SuiteTestTest();
	std::unique_ptr<const oout::Result> result() const override;
private:
	const std::unique_ptr<const oout::Test> tests;
};
