#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "pipeline_stage_mock.h"

#include <colorpipe/scale_stage.h>
#include <colorpipe/pixels.h>
#include <memory>

namespace {
  using ::colorpipe::ScaleStage;
  using ::colorpipe::RGB8;

  TEST(ScaleStage, Scale) {
    using ::testing::Pointee;
    using ::testing::Ref;
    using ::std::shared_ptr;
    using ::std::make_shared;
    using ::testing::Sequence;

    ScaleStage<RGB8> scaleStage(2.0f, static_cast<int_fast16_t >(50));
    RGB8 pixel(255, 32, 0);
    scaleStage.process(pixel);

    EXPECT_EQ(static_cast<uint_fast8_t >(-25.f), 0);
    EXPECT_EQ(pixel.red, 255);
    EXPECT_EQ(pixel.green, 32*2 + 50);
    EXPECT_EQ(pixel.blue, 50);
  }
}
