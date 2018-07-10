#pragma once

#include <stdint.h>
#include <ostream>
#include <array>
#include <limits>

namespace colorpipe {
  /// A variable bit-depth RGB pixel structure
  ///
  /// @tparam cc_t The datatype to store the value of a Color Channel
  template<typename cc_t=uint_fast8_t >
  struct RGB {
    static constexpr cc_t MAX_VALUE = std::numeric_limits<cc_t>::max();
    using colorchannel_type = cc_t;

    union {
      struct {
        cc_t red;
        cc_t green;
        cc_t blue;
      };
      ::std::array<cc_t, 3> raw;
    };

    RGB() : red(0), green(0), blue(0) {}

    RGB(const RGB<cc_t>& o) : raw(o.raw) {}

    RGB(cc_t red, cc_t green, cc_t blue) : red(red), green(green), blue(blue) {}

    bool operator ==(const RGB<cc_t> &b) const {
      return raw == b.raw;
    }

    bool operator !=(const RGB<cc_t> &b) const {
      return raw != b.raw;
    }
  };

  using RGB8 = RGB<uint8_t>;
  using RGB16 = RGB<uint16_t>;
}