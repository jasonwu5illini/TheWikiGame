#pragma once
#include <map>
#include <vector>
#include <iostream>

using namespace std;

class TheWikiGame{
    public:
        std::vector<vector<string>> bfs(std::string startLocation, std::string endLocation);
        std::vector<vector<string>> djikstra(std::string startLocation, std::string endLocation);
    private:
        std::map<std::string, int>linkToId;
        std::map<int, std::string>idToLink;
        std::map<int, vector<int>>directedAdjacencyList;
};