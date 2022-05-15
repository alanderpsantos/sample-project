#include <gtest/gtest.h>
#include <gmock/gmock.h>

#if 1

extern "C"
{
#include "lib.h"
}

using namespace ::testing;
using ::testing::Return;

class BCMLib_MOCK {
public:
    virtual ~BCMLib_MOCK(){}

    MOCK_METHOD2(bcm_add, const int(int const, int const));
    MOCK_METHOD2(bcm_sub, const int(int const, int const));
};

class BCMTestFixture: public ::testing::Test {
public:
    BCMTestFixture()
    {
        _bcmlib_mock.reset(new ::testing::NiceMock<BCMLib_MOCK>());
    }

    ~BCMTestFixture()
    {
        _bcmlib_mock.reset();
    }

    void SetUp() override
    {
        // Code here will be called immediately after the constructor (right
        // before each test).
    }

    void TearDown() override
    {
        // Code here will be called immediately after each test (right
        // before the destructor)
    }
    static std::unique_ptr<BCMLib_MOCK> _bcmlib_mock;
};

std::unique_ptr<BCMLib_MOCK> BCMTestFixture::_bcmlib_mock;

[[nodiscard]] const int add(int const lhs, int const rhs)
{
    return BCMTestFixture::_bcmlib_mock->bcm_add(lhs, rhs);
}

[[nodiscard]] const int sub(int const lhs, int const rhs)
{
    return BCMTestFixture::_bcmlib_mock->bcm_sub(lhs, rhs);
}

class BCMUnitTest: public BCMTestFixture {
public:
    BCMUnitTest() {}
};

TEST_F(BCMUnitTest, verify_10_10)
{
    EXPECT_CALL(*_bcmlib_mock, bcm_add(10,10)).Times(1).WillOnce(Return(20));
    EXPECT_CALL(*_bcmlib_mock, bcm_sub(_,10)).Times(1).WillOnce(Return(10));

    EXPECT_EQ(verify(10,10), 10);
}

TEST_F(BCMUnitTest, verify_20_20)
{
    EXPECT_CALL(*_bcmlib_mock, bcm_add(_,_)).Times(1).WillOnce(Return(40));
    EXPECT_CALL(*_bcmlib_mock, bcm_sub(_,_)).Times(1).WillOnce(Return(20));

    EXPECT_EQ(verify(20,20), 20);
}

#endif


