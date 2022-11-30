#include "TheWikiGame.h"
#include <queue>

TheWikiGame::TheWikiGame(std::string titleFile, std::string linksFile) {
    ifstream wordsFile(titleFile);
    std::string word;
    int count = 1; 
    if (wordsFile.is_open()) {
        //std::cout << "file open" << std::endl;
        while (getline(wordsFile, word)) {
            //std::cout << word << " " << count << std::endl;
            linkToId[word] = count;
            idToLink[count] = word;
            count++;      
        }
    }
    std::cout << "Bushism id: " << linkToId["Bushism"] << std::endl;
    std::cout << "This should be Bushism: " << idToLink[610] << std::endl;
    ifstream wordsFile1(linksFile);
    std::string line;
    bool odd = true; 
    std::string curword = "";
    if (wordsFile1.is_open()) {
        //std::cout << "wordsfile1 open" << std::endl;
        while (getline(wordsFile1, line)) { 
            if(odd) {
                if (line != "\n") {
                    curword = line; 
                    //std::cout << "curword: " << curword << std::endl;
                    if (curword.at(0) == ' ') {
                        curword.erase(0, 1); 
                    }
                    if (curword.at(curword.size() - 1) == ' ') {
                        curword.erase(curword.size() - 1, 1); 
                    }
                    odd = false;                     
                }
            } else { 
                if (line != "\n") {
                    std::vector<int> tempvect; 
                    std::string process = "";
                    for (char c : line) { 
                        if (c == ',') { 
                            if (linkToId.count(process) == 1) {
                            tempvect.push_back(linkToId[process]); 
                            }
                            process = ""; 
                        } else {
                            process.push_back(c); 
                        }
                    }
                    if (linkToId.count(process) == 1) {
                        tempvect.push_back(linkToId[process]); 
                    }
                    odd = true; 
                    int curwordint = linkToId[curword];
                    //std::cout << "curword int: " << curwordint << std::endl;
                    if (curwordint != 0) { 
                        directedAdjacencyList[curwordint] = tempvect; 
                    }                    
                }
            }               
        }
    }
    std::cout << "size of map: " << directedAdjacencyList.size() << std::endl;
    std::cout << "printing page ids of pages linked on Abraham Lincoln (page ID 1)." << std::endl;
    for (int i = 0; i < directedAdjacencyList[610].size(); i++) {
        std::cout << idToLink[directedAdjacencyList[610].at(i)] << std::endl;
    }
}

std::vector<std::vector<string>> TheWikiGame::bfs(std::string startLocation, std::string endLocation) {
    std::queue<int>bfsQueue;
    int startId = linkToId[startLocation];
    bfsQueue.push(startId);
    int dist = 0;
    bool foundPath = false;
    while(dist < 6 && !foundPath){
        int degreeSize = bfsQueue.size();
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
        dist++;
    }
    
    std::cout<<dist<<std::endl;
    return std::vector<std::vector<string>>();
}

std::vector<std::vector<string>> TheWikiGame::djikstra(std::string startLocation, std::string endLocation) {
    return std::vector<std::vector<string>>();
}

int TheWikiGame::test(){
    return 1;
}