// Copyright (c) 2017 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include "Result.h"

namespace oout {

class Success final : public Result {
public:
	explicit Success(const std::string &text = {});
	std::string print(const Format &format) const override;
private:
	const std::string text;
};

}
