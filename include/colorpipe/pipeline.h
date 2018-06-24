#pragma once

#include <vector>
#include "pixels.h"

namespace colorpipe {
  /// Interface for a pipeline stage
  template<typename T>
  class PipelineStage {
  public:
    virtual ~PipelineStage() {}

    /// Apply an arbitrary transformation into the pixel
    /// @param inOut The pixel to transform
    virtual void process(T& inOut) const = 0;
  };

  /// Pipeline is a Pipeline Stage plus composition features
  template<typename T>
  class Pipeline : public PipelineStage<T> {
  public:
    virtual ~Pipeline() {}

    virtual void process(T& inOut) const = 0;

    virtual void addStage(PipelineStage<T> const newStep) const = 0;
  };
}