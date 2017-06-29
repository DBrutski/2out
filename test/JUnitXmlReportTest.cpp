// Copyright (c) 2017 Andrey Valyaev <dron.valyaev@gmail.com>
//
// This software may be modified and distributed under the terms
// of the MIT license.  See the LICENSE file for details.

#include "JUnitXmlReportTest.h"
#include <list>
#include <Failure.h>
#include <JUnitXmlReport.h>
#include <ResSimple.h>
#include <TestContainText.h>
#include <TestNamed.h>
#include <TestSuite.h>
#include "ResFakes.h"

using namespace std;
using namespace oout;

JUnitXmlReportTest::JUnitXmlReportTest()
: tests(
	make_unique<TestNamed>(
		"JUnitXmlReportTest",
		list<shared_ptr<const Test>>{
			make_shared<TestContainText>(
				make_unique<JUnitXmlReport>(
					make_unique<ResErrorCase>()
				),
				"<error"
			),
			make_shared<TestContainText>(
				make_unique<JUnitXmlReport>(
					make_unique<ResErrorCase>()
				),
				"</error>"
			),
			make_shared<TestContainText>(
				make_unique<JUnitXmlReport>(
					make_unique<ResFailureCase>()
				),
				"<failure"
			),
			make_shared<TestNamed>(
				"Escaping in failure",
				make_shared<TestContainText>(
					make_unique<JUnitXmlReport>(
						make_unique<ResSimple>(
							make_unique<Failure>("<tag>")
						)
					),
					"failure><![CDATA[<tag>]]"
				)
			)
		}
	)
)
{
}

shared_ptr<const Result> JUnitXmlReportTest::result() const
{
	return tests->result();
}
