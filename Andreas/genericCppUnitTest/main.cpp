// #include <cppunit/ui/textTestRunner.h>
#include <exampleTest.h>
#include <TestSuite.h>
#include <TestResult.h>
#include <TestCaller.h>

int main(int argc, char* args[])
{
    CppUnit::TestSuite suite;
    CppUnit::TestResult result;
    suite.addTest( new CppUnit::TestCaller<ComplexNumberTest>(
                       "testEquality",
                       &ComplexNumberTest::testEquality ) );
    suite.addTest( new CppUnit::TestCaller<ComplexNumberTest>(
                       "testAddition",
                       &ComplexNumberTest::testAddition ) );
    suite.run( &result );
    return 0;
}
