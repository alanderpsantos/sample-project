#include <gtest/gtest.h>
#include <gmock/gmock.h>

#if 0

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

struct S {
    int lhs;
    int rhs;
};

class BCMTestWithParamFixture: public ::testing::TestWithParam<S> {
public:
    BCMTestWithParamFixture()
    {
        _bcmlib_mock.reset(new ::testing::NiceMock<BCMLib_MOCK>());
    }

    ~BCMTestWithParamFixture()
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

std::unique_ptr<BCMLib_MOCK> BCMTestWithParamFixture::_bcmlib_mock;

[[nodiscard]] const int add(int const lhs, int const rhs)
{
    return BCMTestWithParamFixture::_bcmlib_mock->bcm_add(lhs, rhs);
}

[[nodiscard]] const int sub(int const lhs, int const rhs)
{
    return BCMTestWithParamFixture::_bcmlib_mock->bcm_sub(lhs, rhs);
}

TEST_P(BCMTestWithParamFixture, verify_with_param)
{
    auto param = GetParam();
    
    EXPECT_CALL(*_bcmlib_mock, bcm_add(_,_)).Times(1).WillOnce(Return(param.lhs+param.rhs));
    EXPECT_CALL(*_bcmlib_mock, bcm_sub(_,_)).Times(1).WillOnce(Return((param.lhs+param.rhs)-param.rhs));

    EXPECT_EQ(verify(param.lhs, param.rhs), param.lhs);
}

INSTANTIATE_TEST_SUITE_P(
    BCMUnitTestWithParam,
    BCMTestWithParamFixture,
    testing::Values(
        S{ 5, 5 },
        S{ 10, 10 },
        S{ 15, 15 },
        S{ 20, 20 },
        S{ 25, 25 }
    )
);

#endif