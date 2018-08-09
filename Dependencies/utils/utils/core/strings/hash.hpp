#ifndef UTILS_UTILS_CORE_STRINGS_HASH_H
#define UTILS_UTILS_CORE_STRINGS_HASH_H
#include <utils/core/strings/constants.hpp>
#include <utils/core/hash.hpp>
#include <iomanip>

namespace utils {
namespace core {
namespace strings {    
template<typename CharT, typename T>
inline std::basic_string<CharT> hash(T& body) {
    using utils::core::strings::constants::c_zero;
    std::basic_ostringstream<CharT> ss;
    for (auto b : utils::core::hash<T>(body)) {
        ss << std::setw(2) << std::setfill(c_zero<CharT>()) << std::hex << static_cast<unsigned int>(b);
    }
    return ss.str();
}
template<typename CharT, typename T>
inline std::basic_string<CharT> hash(T& body, size_t size) {
    using utils::core::strings::constants::c_zero;
    std::basic_ostringstream<CharT> ss;
    for (auto b : utils::core::hash<T>(body, size)) {
        ss << std::setw(2) << std::setfill(c_zero<CharT>()) << std::hex << static_cast<unsigned int>(b);
    }
    return ss.str();
}

template<typename CharT, typename T, size_t size>
inline std::basic_string<CharT> hash(const T(&arr)[size]) {
    using utils::core::strings::constants::c_zero;
    std::basic_ostringstream<CharT> ss;
    for (auto b : utils::core::hash<T, size>(arr)) {
        ss << std::setw(2) << std::setfill(c_zero<CharT>()) << std::hex << static_cast<unsigned int>(b);
    }
    return ss.str();
}
}
}
}

#endif//UTILS_UTILS_CORE_STRINGS_HASH_H