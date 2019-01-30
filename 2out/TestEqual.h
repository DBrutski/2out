// Copyright (c) 2017-2019 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#pragma once
#include "Representation.h"
#include "Test.h"

namespace oout {

/// Equality test
class TestEqual final : public Test {
public:
	/// Secondary ctor from two string
	TestEqual(const std::string &a, const std::string &b);

	/// Secondary ctor from string and Repr
	TestEqual(const std::string &a, const std::shared_ptr<const Representation> &b);

	/// Secondary ctor from Repr and string
	TestEqual(const std::shared_ptr<const Representation> &a, const std::string &b);

	/// Primary ctor
	TestEqual(
		const std::shared_ptr<const Representation> &a,
		const std::shared_ptr<const Representation> &b
	);

	/// Get result
	std::unique_ptr<const Result> result() const override;
private:
	const std::shared_ptr<const Representation> a;
	const std::shared_ptr<const Representation> b;
};

}

