#ifndef REPO_CHANGE_SNAPSHOTMANAGER_H
#define REPO_CHANGE_SNAPSHOTMANAGER_H

#include <repo/change/snapshot.hpp>

namespace repo {
namespace change {
;
enum class constant {
    BLOCK_MAX_SIZE = 1024
};
class snapshotmanager {
public:
    template<typename CharT>
    snapshotmanager(istream_t<CharT>& stream) {
        auto pos = stream.tellg();
        stream.seekg(std::ios::end, 0);
        auto size = stream.tellg();
        stream.seekg(std::ios::beg, pos);
        auto blocks = size / static_cast<decltype(size)>(constant::BLOCK_MAX_SIZE) +
            (size % static_cast<decltype(size)>(constant::BLOCK_MAX_SIZE) == 0 ? 0 : 1);
    }

private:
    std::vector<snapshot> snapshots_;
};

}
}

#endif//REPO_CHANGE_SNAPSHOTMANAGER_H