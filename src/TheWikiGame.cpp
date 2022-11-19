#include "TheWikiGame.h"
#include <queue>

TheWikiGame::TheWikiGame(){
    std::cout<<"Use this to fill in maps"<<std::endl;
}

std::vector<string> TheWikiGame::bfs(std::string startLocation, std::string endLocation) {
    std::queue<int>bfsQueue;
    std::vector<string>shortestPath;
    int prev [directedAdjacencyList.size()];
    bool visited [directedAdjacencyList.size()];

    //ID of starting page

    int startId = linkToId[startLocation];
    
    //ID of ending page

    int endId = linkToId[endLocation];
   
    int dist = 0;
    bool foundPath = false;

    for (int i = 0; i < directedAdjacencyList.size(); i++) {
        visited[i] = false;
        prev[i] = -1;
    }

    //Begin BFS
    bfsQueue.push(startId);
    visited[startId] = true;
    while(dist < 6 && !foundPath && !bfsQueue.empty()){
        int degreeSize = bfsQueue.size();
        for(int j = 0; j < degreeSize; j++){
            int currentPage = bfsQueue.front();
            bfsQueue.pop();
            vector<int>linksToOtherPages = directedAdjacencyList[currentPage];
            for(int k = 0; k < linksToOtherPages.size(); k++){
                int adjacentId = linksToOtherPages[k];
                if(!visited[adjacentId]){
                    visited[adjacentId] = true;
                    prev[adjacentId] = currentPage; //Keep track of ID's that lead to the end
                    if(adjacentId == endId){
                        foundPath = true;
                    }
                }
            }
        }
        dist++;
    }

    int currId = endId;
    shortestPath.push_back(idToLink[currId]);

    while(prev[currId] != -1){
        std::string path = idToLink[prev[currId]];
        shortestPath.push_back(path);
        currId = prev[currId];
    }
    
    std::cout<<"The shortest distance is "<<dist<<std::endl;
    return shortestPath;
}

std::vector<std::vector<string>> TheWikiGame::djikstra(std::string startLocation, std::string endLocation) {
    return std::vector<std::vector<string>>();
}

int TheWikiGame::test(){
    return 1;
}