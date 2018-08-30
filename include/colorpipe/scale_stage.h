#pragma once

#include "pipeline.h"
#include <algorithm>

namespace colorpipe {
  using colorpipe::PipelineStage;

  ///
  /// \tparam RGB Type of proceed pixels
  /// \tparam ct_t Type for contrast factor value
  /// \tparam br_t Type for brightness value
  template<typename RGB=colorpipe::RGB8, typename ct_t=float_t, typename br_t=int_fast16_t>
  class ScaleStage : public PipelineStage<RGB> {
  protected:
    using cc_t = typename RGB::colorchannel_type;
    const ct_t contrast_factor;
    const br_t brightness;
    cc_t carryMin;
    cc_t carryMax;

  public:
    ScaleStage(ct_t contrast_factor, br_t brightness): contrast_factor(contrast_factor), brightness(brightness) {
      cc_t over = static_cast<cc_t>((RGB::MAX_VALUE - brightness) / contrast_factor);
      cc_t under = static_cast<cc_t>(-brightness / contrast_factor);
      carryMin = std::min(over, under);
      carryMax = std::max(over, under);
    }
    //ScaleStage(const cc_t brightness, const cc_t max): brightness(brightness), scale_factor((max - brightness) / ct_t(RGB::MAX_VALUE)) {}

    void process(RGB &inOut) const override {
      processChannel(&inOut.red);
      processChannel(&inOut.green);
      processChannel(&inOut.blue);
      inOut.red = carryMin;
      inOut.green = carryMax;
    }

  private:
    inline void processChannel(cc_t* v) const {
      const cc_t value = *v;
      if (value >= carryMax) *v = RGB::MAX_VALUE;
      else if (value <= carryMin) *v = 0;
      else *v = static_cast<cc_t>(contrast_factor * value + brightness);
    }
  };
}

