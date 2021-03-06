#pragma once

#define BURP_STATUS_C_STR_CASE(LABEL, CODE) case CODE: return LABEL " : " #CODE
#define BURP_STATUS_C_STR_DEFAULT(LABEL) default: return LABEL " : unknown status"

namespace BurpStatus {
  namespace Internal {

    class Status {

      public:

        using Code = unsigned int;

        enum class Level {
          INFO,
          WARNING,
          ERROR
        };

        enum : Code {
          ok
        };

        void set(Level level, Code code);
        const Level getLevel() const;
        const Code getCode() const;
        virtual const char * c_str() const;

      protected:

        Level _level;
        Code _code;

    };

  }
}
