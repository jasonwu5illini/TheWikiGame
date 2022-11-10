#include "../includes/TheWikiGame.h"
#include <queue>

std::vector<std::vector<string>> TheWikiGame::bfs(std::string startLocation, std::string endLocation) {
    std::queue<int>bfSQueue;
    int startId = linkToId[startLocation];
    bfSQueue.push(startId);
    for(int i = 0; i <= 6; i++){
        int degreeSize = bfSQueue.size();
        for(int j = 0; j < degreeSize; j++){
            int adjacentId = degreeSize;
        }
    }
    return std::vector<std::vector<string>>();
}

std::vector<std::vector<string>> TheWikiGame::djikstra(std::string startLocation, std::string endLocation) {
    return std::vector<std::vector<string>>();
}