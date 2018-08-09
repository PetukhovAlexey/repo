#ifndef UTILS_UTILS_CORE_HASH_H
#define UTILS_UTILS_CORE_HASH_H
#include <md5.hpp>
#include <limits.h>

namespace utils {
namespace core {
namespace internal {
typedef unsigned char byte;

enum class contants {
    READ_BUFFER_SIZE=20480
};

inline std::vector<byte> count_hash(const std::vector<byte>& body) {
    md5hash::MD5 obj(body);
    return obj.digest();
}

template <typename T>
struct hash;
template <typename T, size_t size>
struct array_hash;
    
template <typename CharT>
struct hash<std::basic_string<CharT>> {
    inline static std::vector<byte> count(const std::basic_string<CharT>& str) {
        return count_hash(std::vector<byte>(reinterpret_cast<const byte*>(str.data()), reinterpret_cast<const byte*>(str.data() + str.length())));
    }
};

template <typename CharT>
struct hash<std::basic_istream<CharT>> {
    inline static std::vector<byte> count(std::basic_istream<CharT>& str, size_t max_size = ULLONG_MAX) {

        md5hash::MD5 obj;
        std::vector<byte> buffer;
        do {
            buffer = read(str, std::min(static_cast<size_t>(contants::READ_BUFFER_SIZE), max_size));
            if (!buffer.empty()) {
                obj.update(buffer);
            }
            max_size -= buffer.size();
        } while (!buffer.empty() && (max_size > 0));

        obj.finalize();
        return obj.digest();
    }

    inline static std::vector<byte> read(std::basic_istream<CharT>& str, size_t size) {
        std::vector<CharT> buffer(size);
        return std::vector<byte>(
            reinterpret_cast<const byte*>(buffer.data()), 
            reinterpret_cast<const byte*>(buffer.data() + str.read(buffer.data(), size).gcount()));
    }
};

template <size_t size>
struct array_hash<char, size> {
    inline static std::vector<byte> count(const char (&str)[size]) {
        return hash<std::string>::count(std::string(str));
    }
};
template <size_t size>
struct array_hash<wchar_t, size> {
    inline static std::vector<byte> count(const wchar_t(&str)[size]) {
        return hash<std::wstring>::count(std::wstring(str));
    }
};
}

template<typename T>
inline std::vector<unsigned char> hash(const T& body) {
    return internal::hash<T>::count(body);
}

template<typename T>
inline std::vector<unsigned char> hash(T& body) {
    return internal::hash<T>::count(body);
}

template<typename T, size_t size>
inline std::vector<unsigned char> hash(const T(&arr)[size]) {
    return internal::array_hash<T, size>::count(arr);
}

template<typename T>
inline std::vector<unsigned char> hash(const T& body, size_t size) {
    return internal::hash<T>::count(body, size);
}

template<typename T>
inline std::vector<unsigned char> hash(T& body, size_t size) {
    return internal::hash<T>::count(body, size);
}

}
}

#endif//UTILS_UTILS_CORE_HASH_H