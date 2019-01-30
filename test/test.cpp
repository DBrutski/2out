// Copyright (c) 2017-2019 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include <iostream>
#include <list>
#include <memory>
#include <2out/CountError.h>
#include <2out/CountFailure.h>
#include <2out/JUnitXmlReport.h>
#include <2out/Result.h>
#include <2out/TestEqual.h>
#include <2out/TestSuite.h>
#include "CountErrorTest.h"
#include "CountFailureTest.h"
#include "CountTestTest.h"
#include "JUnitXmlReportTest.h"
#include "ReprPrintableTest.h"
#include "TestNamedTest.h"
#include "TestSkippedTest.h"
#include "TestStartsWithTest.h"
#include "TestSuiteTest.h"
#include "TextReportTest.h"

using namespace std;
using namespace oout;

int main(int, char **)
{
	const TestSuite tests(
		make_shared<CountErrorTest>(),
		make_shared<CountFailureTest>(),
		make_shared<CountTestTest>(),
		make_shared<JUnitXmlReportTest>(),
		make_shared<ReprPrintableTest>(),
		make_shared<TestNamedTest>(),
		make_shared<TestSkippedTest>(),
		make_shared<TestStartsWithTest>(),
		make_shared<TestSuiteTest>(),
		make_shared<TextReportTest>()
	);

	const shared_ptr<const Result> result = tests.result();

	cout << JUnitXmlReport(result).asString() << endl;

	return (
		CountFailure(result).count() == 0 &&
		CountError(result).count() == 0
	) ? 0 : -1;
}
