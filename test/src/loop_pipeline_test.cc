#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "pipeline_stage_mock.h"

#include <colorpipe/loop_stage.h>
#include <colorpipe/pixels.h>
#include <memory>

namespace {
  using ::colorpipe::LoopStage;
  using ::colorpipe::RGB8;

  TEST(LoopStage, Times) {
    using ::testing::Pointee;
    using ::testing::Ref;
    using ::std::shared_ptr;
    using ::std::make_shared;
    using ::testing::Sequence;

    auto looped = make_shared<const PipelineStageMock<RGB8>>();
    LoopStage<RGB8> looper(looped, 10);

    RGB8 v;
    EXPECT_CALL(*looped, process(Ref(v)))
      .Times(10);
    looper.process(v);
  }
}
