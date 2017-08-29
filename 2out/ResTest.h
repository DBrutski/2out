// Copyright (c) 2017 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include <memory>
#include "Result.h"

namespace oout {

/// Result of simple test
class ResTest final : public Result {
public:
	/// Primary ctor from assertion result
	explicit ResTest(const std::shared_ptr<const Result> &result);

	/// Printer
	std::string print(const Format &format) const override;
private:
	const std::shared_ptr<const Result> result;
};

}
