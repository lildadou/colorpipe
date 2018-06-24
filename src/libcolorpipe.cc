#include <stdint.h>
#include <ostream>

#include <colorpipe/pixels.h>

namespace colorpipe {
  std::ostream &operator<<(std::ostream &ostream, const RGB8 &o) {
    return ostream << "RGB8(" << unsigned(o.red) << ", " << unsigned(o.green) << ", " << unsigned(o.blue) << ")";
  }

  std::ostream &operator<<(std::ostream &ostream, const RGB16 &o) {
    return ostream << "RGB16(" << unsigned(o.red) << ", " << unsigned(o.green) << ", " << unsigned(o.blue) << ")";
  }
}
