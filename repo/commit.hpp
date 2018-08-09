#ifndef REPO_COMMIT_H
#define REPO_COMMIT_H

#include <bson/bson.h>
#include <utils.h>
#include <vector>
#include <chrono>

namespace repo {

struct Idle {

};

class commit{
public:
    typedef std::vector<unsigned char> Id;
    typedef std::vector<Idle> Idles;
    typedef std::chrono::nanoseconds Timestamp;

private:
    struct _Internal {
        struct Data{
            Idles changes;
            Timestamp timestamp;
            Id prev;
        } data;
        Id selfId;
    };
};

}

#endif//REPO_COMMIT_H