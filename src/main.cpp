#include <iostream>
#include <fstream>
#include <bson/bson.h>
#include <utils.hpp>
#include <repo/change.hpp>

int main() {

    std::stringstream ss("tmpstring");
    /*
    std::cout << "hahsh:" << utils::core::strings::hash<char, std::istream>(ss) << std::endl;
    std::cout << "hahsh:" << utils::core::strings::hash<char>("tmpstring") << std::endl;
    std::wcout << L"hahsh:" << utils::core::strings::hash<wchar_t>("tmpstring") << std::endl;
    std::cout << "hahsh:" << utils::core::strings::hash<char>(L"tmpstring") << std::endl;
    std::wcout << L"hahsh:" << utils::core::strings::hash<wchar_t>(L"tmpstring") << std::endl;*/

    repo::change::snapshot ss_snapshot(ss, 1, 8);

    std::cout << "state0:" << ss_snapshot.check(ss) << std::endl;
    ss << "1";
    std::cout << "state1:" << ss_snapshot.check(ss) << std::endl;
    ss.seekp(0);
    ss << "t";
    std::cout << "state2:" << ss_snapshot.check(ss) << std::endl;

    return 0;
}