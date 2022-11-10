#pragma once
#include <map>
#include <vector>

using namespace std;

class TheWikiGame{
    public:

    private:
    std::map<std::string, int>linkToId;
    std::map<int, std::string>idToLink;
    std::map<int, vector<int>>adj
}