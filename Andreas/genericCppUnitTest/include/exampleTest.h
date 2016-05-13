#ifndef EXAMPLETEST_H
#define EXAMPLETEST_H

#include <TestCase.h>
#include "Complex.h"

class ExampleTest : public CppUnit::TestFixture
{
    private:
        Complex *m10_1, *m_1_1, *m_11_2;
    public:
        void setUp()
        {
            m10_1 = new Complex(10,1);
            m_1_1 = new Complex(1,1);
            m_11_2 = new Complex(11,2);
        }

        void tearDown()
        {
            delete m10_1;
            delete m_1_1;
            delete m_11_2;
        }

        void testEquality()
        {
            CPPUNIT_ASSERT( *m10_1 == *m10_1);
            CPPUNIT_ASSERT( !(*m10_1 == *m_11_2) );
        }

        void testAddition()
        {
            // CPPUNIT_ASSERT( *m10_1 + *m_1_1 == *m_11_2 );
        }
};

#endif // EXAMPLETEST_H
