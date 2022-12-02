#include "TheWikiGame.h" 
#include <iostream>
int main() {
    //TheWikiGame test = TheWikiGame("/workspaces/cs225/TheWikiGame/ArticleT.txt", "/workspaces/cs225/TheWikiGame/ArticleLinks.txt");
    TheWikiGame test = TheWikiGame("/workspaces/CS225 Labs/TheWikiGame/dank.txt", "/workspaces/CS225 Labs/TheWikiGame/dank2.txt");
    std::vector<std::string> path = test.bfs("Andrew Johnson", "Statue of Harry S. Truman");
    for(auto it = path.begin(); it != path.end(); it++){
        std::cout<<*it<<std::endl;
    }
    return 1;
} 