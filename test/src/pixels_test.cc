#include <gtest/gtest.h>

#include <colorpipe/pixels.h>

namespace {
  using ::testing::Test;
  using ::colorpipe::RGB8;
  using ::colorpipe::RGB16;

  template<typename Pixel, uintmax_t MaxValue>
  class PixelTypeValueParameter {
  public:
    typedef Pixel T;
    static const uintmax_t max = MaxValue;
  };
  
  template< typename MyTypeValueParam >
  class PixelTest : public Test {

  };
  TYPED_TEST_CASE_P(PixelTest);


  TYPED_TEST_P(PixelTest, DefaultConstructor) {
    typename TypeParam::T pixel;
    EXPECT_EQ(pixel.red, 0);
    EXPECT_EQ(pixel.green, 0);
    EXPECT_EQ(pixel.blue, 0);
    EXPECT_EQ(pixel.raw[0], 0);
    EXPECT_EQ(pixel.raw[1], 0);
    EXPECT_EQ(pixel.raw[2], 0);
  }

  TYPED_TEST_P(PixelTest, SetOnTheFlyConstructor) {
    typename TypeParam::T pixel(TypeParam::max, 0, 72);
    const uintmax_t max = TypeParam::max;
    EXPECT_EQ(pixel.red, max);
    EXPECT_EQ(pixel.green, 0);
    EXPECT_EQ(pixel.blue, 72);
    EXPECT_EQ(pixel.raw[0], max);
    EXPECT_EQ(pixel.raw[1], 0);
    EXPECT_EQ(pixel.raw[2], 72);
  }

  TYPED_TEST_P(PixelTest, EqualOperator) {
    typename TypeParam::T a1(TypeParam::max, 0, 72);
    typename TypeParam::T a2(TypeParam::max, 0, 72);
    typename TypeParam::T b1(TypeParam::max, TypeParam::max, 72);

    ASSERT_TRUE(a1 == a1);
    ASSERT_TRUE(a2 == a2);
    ASSERT_TRUE(b1 == b1);

    EXPECT_TRUE(a1 == a2);
    EXPECT_TRUE(a2 == a1);

    EXPECT_FALSE(a1 == b1);
    EXPECT_FALSE(b1 == a1);
    EXPECT_FALSE(a2 == b1);
    EXPECT_FALSE(b1 == a2);
  }

  TYPED_TEST_P(PixelTest, NotEqualOperator) {
    typename TypeParam::T a(TypeParam::max, 0, 72);
    typename TypeParam::T b(TypeParam::max, TypeParam::max, 72);

    ASSERT_FALSE(a != a);
    ASSERT_FALSE(b != b);
    EXPECT_TRUE(a != b);
    EXPECT_TRUE(b != a);
  }

  REGISTER_TYPED_TEST_CASE_P(PixelTest,
                             DefaultConstructor,
                             SetOnTheFlyConstructor,
                             EqualOperator,
                             NotEqualOperator);

  typedef ::testing::Types<
      PixelTypeValueParameter<RGB8, UINT8_MAX>,
      PixelTypeValueParameter<RGB16, UINT16_MAX> > RGBTestTypes;
  INSTANTIATE_TYPED_TEST_CASE_P(PixelTest, PixelTest, RGBTestTypes);



}
