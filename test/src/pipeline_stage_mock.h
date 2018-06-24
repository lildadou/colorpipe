#pragma once

#include <colorpipe/pipeline.h>
#include <colorpipe/pixels.h>
#include <gmock/gmock.h>

template <typename T=colorpipe::RGB8>
class PipelineStageMock : public colorpipe::PipelineStage<T> {
public:
  MOCK_CONST_METHOD1_T(process, void(T& inOut));
};
