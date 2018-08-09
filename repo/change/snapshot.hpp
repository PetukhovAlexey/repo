#ifndef REPO_CHANGE_SNAPSHOT_H
#define REPO_CHANGE_SNAPSHOT_H

#include <utils.hpp>
#include <iostream>
#include <vector>

namespace repo {
namespace change{

typedef unsigned char byte_t;
typedef std::vector<byte_t> hash_t;
template<typename CharT>
using istream_t = std::basic_istream<CharT>;

class snapshot {
public:
    template<typename CharT>
    inline snapshot(istream_t<CharT>& stream, size_t start, size_t size) :
        start_(start),
        size_(size),
        hash_(get_hash<CharT>(stream, start,size)) {
    }

    template<typename CharT>
    inline bool check(istream_t<CharT>& stream) const {
        return hash_ == get_hash<CharT>(stream, start_, size_);
    }

    template<typename CharT>
    inline static hash_t get_hash(istream_t<CharT>& stream, size_t start, size_t size) {
        auto pos = stream.tellg();
        stream.seekg(start);
        hash_t hash = utils::core::hash<istream_t<CharT>>(stream, size);
        stream.seekg(pos);
        return hash;
    }

private:
    size_t start_;
    size_t size_;
    hash_t hash_;
};

}
}

#endif//REPO_CHANGE_SNAPSHOT_H