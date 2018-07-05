#pragma once

#include "pixels.h"
#include "pipeline.h"

#include <memory>
#include <cstdint>

namespace colorpipe {
  using ::std::shared_ptr;
  using ::std::make_shared;

  /// Dumb PipelineStage which repeat C times a given Pipeline
  /// May be usefull for benchmark a pipeline efficiency
  template<typename T>
  class LoopStage : public PipelineStage<T> {
  protected:
    const shared_ptr<const PipelineStage<T>> looped;
    const std::size_t loopCount;

  public:
    LoopStage(const shared_ptr<const PipelineStage<T>> looped) : looped(looped), loopCount(65536){}
    LoopStage(const shared_ptr<const PipelineStage<T>> looped, std::size_t count) : looped(looped), loopCount(count){}
    void process(T &inOut) const override {
      for (auto i = 0; i < loopCount; ++i) {
        looped->process(inOut);
      }
    }
  };
}
