#pragma once
#include <map>
#include <vector>
#include <iostream>

using namespace std;

class TheWikiGame{
    public:
        std::vector<std::vector<std::string>> bfs(std::string startLocation, std::string endLocation);
        std::vector<std::vector<std::string>> djikstra(std::string startLocation, std::string endLocation);
        int test();
    private:
        std::map<std::string, int>linkToId;
        std::map<int, std::string>idToLink;
        std::map<int, std::vector<int>>directedAdjacencyList;
};