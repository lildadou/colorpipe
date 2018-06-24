#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "pipeline_stage_mock.h"

#include <colorpipe/vector_pipeline.h>
#include <colorpipe/pixels.h>
#include <memory>

namespace {
  using ::colorpipe::VectorPipeline;
  using ::colorpipe::RGB8;


  TEST(VectorPipeline, DefaultConstructor) {
    VectorPipeline<RGB8> p();
  }

  TEST(VectorPipeline, ProcessingOrder) {
    using ::testing::Pointee;
    using ::testing::Ref;
    using ::std::shared_ptr;
    using ::std::make_shared;
    using ::testing::Sequence;

    VectorPipeline<RGB8> p(2);

    auto step1 = make_shared<const PipelineStageMock<RGB8>>();
    auto step2 = make_shared<const PipelineStageMock<RGB8>>();

    p.addStep(step1);
    p.addStep(step2);

    RGB8 v;
    Sequence s1;
    EXPECT_CALL(*step1, process(Ref(v)))
      .Times(1)
      .InSequence(s1);
    EXPECT_CALL(*step2, process(Ref(v)))
      .Times(1)
      .InSequence(s1);
    p.process(v);
  }
}
