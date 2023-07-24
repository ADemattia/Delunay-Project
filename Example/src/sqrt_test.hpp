#ifndef __sqrt_test_HPP__
#define __sqrt_test_HPP__

#include "sqrt.hpp"
#include <gtest/gtest.h>
#include <gmock/gmock.h>

class MockPen : public IPen {
  public:
    MOCK_CONST_METHOD0(PenUp, void());
    MOCK_CONST_METHOD0(PenDown, void());
    MOCK_METHOD1(Forward, void(const unsigned int& distance));
    MOCK_METHOD1(Turn, void(const int& degrees));
    MOCK_CONST_METHOD2(GoTo, void(const int& x,
                                  const int& y));
    MOCK_CONST_METHOD0(GetX, int());
    MOCK_CONST_METHOD0(GetY, int());
};


TEST(PainterTest, CanDrawSomething) {
  MockPen pen;
  Painter painter(pen);

  ON_CALL(pen, GetX()).WillByDefault(testing::Return(1));
  EXPECT_CALL(pen, GetX()).Times(1);
  EXPECT_CALL(pen, GoTo(testing::_,testing::_)).Times(1);
  EXPECT_CALL(pen, PenDown()).Times(testing::AtLeast(1));
  EXPECT_CALL(pen, PenUp()).Times(testing::AtLeast(1));

  EXPECT_TRUE(painter.DrawCircle(0, 0, 10));
}

TEST(SquareRootTest, PositiveNos) 
{ 
  ASSERT_EQ(6, squareRoot(36.0));
  ASSERT_EQ(18.0, squareRoot(324.0));
  ASSERT_EQ(25.4, squareRoot(645.16));
  ASSERT_EQ(0, squareRoot(0.0));
}

TEST(SquareRootTest, NegativeNos) 
{
  ASSERT_EQ(-1.0, squareRoot(-15.0));
  ASSERT_EQ(-1.0, squareRoot(-0.2));
}

#endif // __sqrt_test_HPP__
