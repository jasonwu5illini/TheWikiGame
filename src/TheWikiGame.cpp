#include "TheWikiGame.h"
#include <queue>

TheWikiGame::TheWikiGame(std::string titleFile, std::string linksFile) {
    //if constructor is not working properly, copy and paste the contents of the two files into new files and use them
    ifstream wordsFile(titleFile);
    std::string word;
    int count = 1;  //arbitrary id assigned to each article
    if (wordsFile.is_open()) {
        while (getline(wordsFile, word)) { //get each title, one title per line
            std::string url = "https://en.wikipedia.org/wiki/"; 
            std::string uword = ""; //convert title to url
            for (char ch : word) { 
                if (ch == ' ') {
                    uword.push_back('_');
                } else { 
                    uword.push_back(ch);
                }
            }
            url = url+uword; 
            linkToId[url] = count; //populate data structures
            idToLink[count] = url;
            count++;     // change the id
        }
    }
    ifstream wordsFile1(linksFile);
    std::string line;
    bool odd = true; 
    std::string curword = "";
    if (wordsFile1.is_open()) {
        while (getline(wordsFile1, line)) { 
            if(odd) { //the file is formatted with titles on odd lines and links on even lines, use boolean to switch between the two
                if (line != "\n") {
                    curword = line; 
                    std::string url = "https://en.wikipedia.org/wiki/";
                    std::string uword = "";
                    for (char ch : curword) { 
                        if (ch == ' ') {
                            uword.push_back('_');
                        } else { 
                            uword.push_back(ch);
                        }
                    }
                    curword = url+uword; // convert title to url
                    odd = false;                     
                }
            } else { 
                if (line != "\n") {
                    std::vector<int> tempvect; 
                    std::string process = "";
                    for (char c : line) { 
                        if (c == ',') { 
                            if (linkToId.count(process) == 1) { //if the url is a part of the subset, push it back to the vector of links associated with current article
                                tempvect.push_back(linkToId[process]); 
                            }
                            process = ""; 
                        } else {
                            process.push_back(c);  //append characters to form url
                        }
                    }
                    if (linkToId.count(process) == 1) {
                        tempvect.push_back(linkToId[process]);  //push last url back if valid
                    }
                    odd = true; 
                    
                    int curwordint = linkToId[curword]; //get the id associated with current article


                    if (curwordint != 0) { 
                        directedAdjacencyList[curwordint] = tempvect; //if this id is valid, map the article and associated links
                    }                    
                }
            }               
        }
    }
}


std::string TheWikiGame::getLinkByID(int id) {
    if (idToLink.count(id) == 0) {
        return "ID not valid";
    } else { 
        return idToLink[id];
    }
}
int TheWikiGame::getIDByLink(std::string url) {
    if (linkToId.count(url) == 0) {
        return -1;
    } else { 
        return linkToId[url];
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
