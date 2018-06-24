#pragma once

#include <stdint.h>
#include <ostream>
#include <array>

namespace colorpipe {
  /// A variable bit-depth RGB pixel structure
  ///
  /// @tparam BitDepth The datatype to store the value of a channel
  template<typename BitDepth=uint8_t>
  struct RGB {
    union {
      struct {
        BitDepth red;
        BitDepth green;
        BitDepth blue;
      };
      ::std::array<BitDepth, 3> raw;
    };

    RGB() : red(0), green(0), blue(0) {}

    RGB(const RGB<BitDepth>& o) : raw(o.raw) {}

    RGB(BitDepth red, BitDepth green, BitDepth blue) : red(red), green(green), blue(blue) {}

    bool operator ==(const RGB<BitDepth> &b) const {
      return raw == b.raw;
    }

    bool operator !=(const RGB<BitDepth> &b) const {
      return raw != b.raw;
    }
  };

  using RGB8 = RGB<uint8_t>;
  using RGB16 = RGB<uint16_t>;
}