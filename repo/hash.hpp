#ifndef REPO_CHANGE_HASH_H
#define REPO_CHANGE_HASH_H

#include <utils.hpp>
#include <vector>
#include <functional>
#include <algorithm>

namespace repo {
;
class hash {
public:
    inline hash() :
        data_()
    {}

    inline hash(const hash& h) :
        data_(h.data_)
    {}

    inline hash(hash&& h) :
        data_(std::move(h.data_))
    {}

    template<typename T>
    inline hash(T& obj) :
        data_(utils::core::hash(obj))
    {}

    template<typename T>
    inline hash(const T& obj) :
        data_(utils::core::hash(obj))
    {}

    template<typename T>
    inline hash(T& obj, size_t size) :
        data_(utils::core::hash(obj, size))
    {}

    inline operator unsigned int() const _NOEXCEPT {
        unsigned int res = 0;
        memcpy(&res, data_.data(), std::min(sizeof(res), data_.size()));
        return res;
    }

    inline operator unsigned long long int() const  _NOEXCEPT {
        unsigned long long int res = 0;
        memcpy(&res, data_.data(), std::min(sizeof(res), data_.size()));
        return res;
    }

    inline bool operator==(const hash& h) const  _NOEXCEPT {
        return data_ == h.data_;
    }

    inline bool operator!=(const hash& h) const  _NOEXCEPT {
        return !operator==(h);
    }

    inline hash& operator=(const hash& h) _NOEXCEPT {
        data_ = h.data_;
        return *this;
    }

    template<typename T>
    inline void count(const T& obj) _NOEXCEPT {
        data_ = utils::core::hash(obj);
    }

    template<typename T>
    inline void count(T& obj) _NOEXCEPT {
        data_ = utils::core::hash(obj);
    }

    template<typename T>
    inline void count(T& obj, size_t size) _NOEXCEPT {
        data_ = utils::core::hash(obj, size);
    }

private:
    std::vector<unsigned char> data_;
};

}

namespace std {
    template<>
    class hash<repo::hash> {
        size_t operator()(const repo::hash& h) const _NOEXCEPT
        {	// hash _Keyval to size_t value by pseudorandomizing transform
            return (size_t)h;	// map -0 to 0
        }
    };
}

#endif//REPO_CHANGE_HASH_H