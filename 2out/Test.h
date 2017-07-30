// Copyright (c) 2017 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include <memory>

namespace oout {

class Result;

class Test {
public:
	virtual ~Test() = default;
	virtual std::unique_ptr<const Result> result() const = 0;
};

}
