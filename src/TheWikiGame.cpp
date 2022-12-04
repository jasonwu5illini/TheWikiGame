#include "TheWikiGame.h"
#include <queue>

TheWikiGame::TheWikiGame(std::string titleFile, std::string linksFile) {
    //if constructor is not working properly, copy and paste the contents of the two files into new files and use them
    ifstream wordsFile(titleFile);
    std::string word;
    int count = 1; 
    if (wordsFile.is_open()) {
        //std::cout << "file open" << std::endl;
        while (getline(wordsFile, word)) {
            //std::cout << word << " " << count << std::endl;
            std::string url = "https://en.wikipedia.org/wiki/";
            std::string uword = "";
            for (char ch : word) { 
                if (ch == ' ') {
                    uword.push_back('_');
                } else { 
                    uword.push_back(ch);
                }
            }
            url = url+uword;
            linkToId[url] = count;
            idToLink[count] = url;
            count++;      
        }
    }
    std::cout << "Bushism id: " << linkToId["https://en.wikipedia.org/wiki/Bushism"] << std::endl;
    std::cout << "This should be Bushism: " << idToLink[1663] << std::endl;
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
                    std::string url = "https://en.wikipedia.org/wiki/";
                    std::string uword = "";
                    for (char ch : curword) { 
                        if (ch == ' ') {
                            uword.push_back('_');
                        } else { 
                            uword.push_back(ch);
                        }
                    }
                    curword = url+uword;
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
                    //std::cout<<curword<<std::endl;
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
    for (int i = 0; i < directedAdjacencyList[1].size(); i++) {
        std::cout << idToLink[directedAdjacencyList[1].at(i)] << std::endl;
    }
}

std::vector<std::string> TheWikiGame::bfs(std::string startLocation, std::string endLocation) {

    if(linkToId.count(startLocation) == 0 || linkToId.count(endLocation) == 0){
        std::cout<<"Starting or ending location is invalid"<<std::endl;
        return std::vector<string>();
    }

    std::vector<string> shortestPath;
    std::queue<int>bfsQueue;
    int startId = linkToId[startLocation];
    int endId = linkToId[endLocation];
    
    bfsQueue.push(startId);
    int dist = 0;
    bool foundPath = false;
    bool visited[idToLink.size()];
    int distances[idToLink.size()];
    int prev[idToLink.size()];

    for(int i = 0; i < idToLink.size(); i++){
        visited[i] = false;
        distances[i] = 100000;
        prev[i] = -1;
    }

    visited[startId] = true;
    distances[startId] = 0;

    while(!foundPath && !bfsQueue.empty()){
        int degreeSize = bfsQueue.size();
        for(int j = 0; j < degreeSize; j++){
            int currentId = bfsQueue.front();
            bfsQueue.pop();
            std::vector<int>linksToOtherPages = directedAdjacencyList[currentId];
            for(int k = 0; k < linksToOtherPages.size(); k++){
                int adjacentId = linksToOtherPages[k];
                if(!visited[adjacentId]){
                    bfsQueue.push(adjacentId);
                    visited[adjacentId] = true;
                    distances[adjacentId] = distances[currentId]+1;
                    prev[adjacentId] = currentId;
                    if(adjacentId == endId){
                        foundPath = true;
                    }
                }
            }
        }
        dist++;
    }
    if(!foundPath){
        std::cout<<"No paths were found between "<<startLocation<< " and " <<endLocation<<std::endl;
        return std::vector<string>();
    }
    else{
        int backtrack = endId;
        shortestPath.push_back(idToLink[endId]);
        while(prev[backtrack] != -1){
            shortestPath.push_back(idToLink[prev[backtrack]]);
            backtrack = prev[backtrack];
        }
        std::cout<<"The shortest path between "<<startLocation<< " and " <<endLocation<<" is " << dist<< " steps"<<std::endl;
        return shortestPath;
    }
}

std::vector<std::vector<string>> TheWikiGame::djikstra(std::string startLocation, std::string endLocation) {
    return std::vector<std::vector<string>>();
}

int TheWikiGame::test(){
    return 1;
}