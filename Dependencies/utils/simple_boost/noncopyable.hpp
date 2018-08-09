#ifndef UTILS_SIMPLE_BOOST_NONCOPYABLE_H
#define UTILS_SIMPLE_BOOST_NONCOPYABLE_H

namespace boost {
    class noncopyable {
        noncopyable(const noncopyable&) = delete;
    public:
        noncopyable() = default;
    };
}

#endif//UTILS_SIMPLE_BOOST_NONCOPYABLE_H