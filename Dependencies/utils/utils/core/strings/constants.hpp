#ifndef UTILS_UTILS_CORE_STRINGS_CONSTANTS_H
#define UTILS_UTILS_CORE_STRINGS_CONSTANTS_H

#include <string>

#define __L(c)  L##c
#define CONST_STRING(func_name, str) \
    template<typename CharT> std::basic_string<CharT> func_name();\
    template<> std::basic_string<char> func_name(){return std::string(str); }\
    template<> std::basic_string<wchar_t> func_name(){return std::wstring(__L(str)); }
#define CONST_CHAR(func_name, c) \
    template<typename CharT> CharT func_name();\
    template<> char func_name(){return c; }\
    template<> wchar_t func_name(){return c; }

namespace utils {
namespace core {
namespace strings {
namespace constants {
    CONST_CHAR(c_zero, '0');
}
}
}
}

#undef __L
#undef CONST_STRING
#undef CONST_CHAR

#endif//UTILS_UTILS_CORE_STRINGS_CONSTANTS_H