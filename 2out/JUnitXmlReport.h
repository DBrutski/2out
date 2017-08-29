// Copyright (c) 2017 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include <memory>
#include <string>
#include "Representation.h"

namespace oout {

class Result;

/// JUnit report formatter
class JUnitXmlReport final : public Representation {
public:
	/// Primary ctor
	explicit JUnitXmlReport(const std::shared_ptr<const Result> &result);

	/// Get report as string
	std::string asString() const override;
private:
	const std::shared_ptr<const Result> result;
};

}
