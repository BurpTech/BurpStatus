#include "Status.hpp"

namespace BurpStatus {
  namespace Internal {

    void Status::set(Level level, Code code) {
      _level = level;
      _code = code;
    }

    const Status::Level Status::getLevel() const {
      return _level;
    }

    const Status::Code Status::getCode() const {
      return _code;
    }

    #define C_STR_LABEL "BurpStatus::Status"
    #define C_STR_CASE(CODE) BURP_STATUS_C_STR_CASE(C_STR_LABEL, CODE)
    #define C_STR_DEFAULT BURP_STATUS_C_STR_DEFAULT(C_STR_LABEL)
    const char * Status::c_str() const {
      switch (getCode()) {
        C_STR_CASE(ok);
        C_STR_DEFAULT;
      }
    }

  }
}
