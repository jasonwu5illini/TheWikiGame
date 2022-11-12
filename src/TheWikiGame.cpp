#include "TheWikiGame.h"
#include <queue>

std::vector<std::vector<string>> TheWikiGame::bfs(std::string startLocation, std::string endLocation) {
    /*
    std::queue<int>bfSQueue;
    int startId = linkToId[startLocation];
    bfSQueue.push(startId);
<<<<<<< Updated upstream
    for(int i = 0; i <= 6; i++){
        int degreeSize = bfSQueue.size(); 
=======
    int dist = 0;
    bool foundPath = false;
    while(dist < 6 && !foundPath){
        int degreeSize = bfSQueue.size();
>>>>>>> Stashed changes
        for(int j = 0; j < degreeSize; j++){
            int currentPage = bfsQueue.front();
            bfsQueue.pop();
            vector<int>linksToOtherPages = directedAdjacencyList[currentPage];
            for(int k = 0; k < linksToOtherPages.size(); k++){
                int adjacentId = linksToOtherPages[k];
                string s = idToLink[adjacentId];
                if(s == endLocation){
                    foundPath = true;
                }
            }
        }
<<<<<<< Updated upstream
    } **/
=======
        dist++;
    }

    std::cout<<dist<<std::endl;
>>>>>>> Stashed changes
    return std::vector<std::vector<string>>();
}

std::vector<std::vector<string>> TheWikiGame::djikstra(std::string startLocation, std::string endLocation) {
    return std::vector<std::vector<string>>();
}