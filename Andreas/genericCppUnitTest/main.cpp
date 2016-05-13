#include <cppunit/ui/text/TestRunner.h>
#include <exampleTest.h>


int main(int argc, char* args[])
{
    CppUnit::TextUi::TestRunner runner;
    runner.addTest( ExampleTest::suite() );
    runner.run();
    return 0;
}
