#pragma once
#include <map>
#include <vector>
#include <iostream>
#include <fstream>
#include <set>
using namespace std;

class TheWikiGame{
    public:
        TheWikiGame(std::string titleFile, std::string linksFile); 
        std::vector<std::vector<std::string>> bfs(std::string startLocation, std::string endLocation);
        std::vector<std::vector<std::string>> djikstra(std::string startLocation, std::string endLocation);
        int test();
    private:
        std::map<std::string, int>linkToId;
        std::map<int, std::string>idToLink;
        std::map<int, std::vector<int>>directedAdjacencyList;
};