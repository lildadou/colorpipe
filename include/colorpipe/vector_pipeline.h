#pragma once

#include "pixels.h"
#include "pipeline.h"

#include <vector>
#include <memory>

namespace colorpipe {
  using ::std::vector;
  using ::std::size_t;
  using ::std::shared_ptr;

  /// In accordance with composite pattern, this PipelineStage
  /// apply transformations of an arbitrary set of PipelineStages
  template<typename T>
  class VectorPipeline : public PipelineStage<T> {
  protected:
    vector<shared_ptr<const PipelineStage<T>>> body;

  public:
    VectorPipeline() {}

    VectorPipeline(size_t _size) {
      body.reserve(_size);
    }

    void process(T &inOut) const override {
      for (const shared_ptr<const PipelineStage<T>> step : body) {
        step->process(inOut);
      }
    }

    void addStep(shared_ptr<const PipelineStage<T>> newStep) {
      body.push_back(newStep);
    }
  };
}
