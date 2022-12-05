#include "TheWikiGame.h" 
#include <iostream>
int main() {
    //REMEMBER TO CHANGE PATHING EVERYTIME, IT IS DIFFERENT FOR EVERYONE
    //TheWikiGame test = TheWikiGame("/workspaces/cs225/TheWikiGame/ArticleT.txt", "/workspaces/cs225/TheWikiGame/ArticleLinks.txt");
    TheWikiGame test = TheWikiGame("/workspaces/CS225 Labs/TheWikiGame/ArticleTKevin.txt", "/workspaces/CS225 Labs/TheWikiGame/ArticleLinksKevin.txt");
    std::vector<std::string> path = test.bfs("https://en.wikipedia.org/wiki/Nanny_and_Nanko", "https://en.wikipedia.org/wiki/Abraham_Lincoln");
    for(auto it = path.begin(); it != path.end(); it++){
        std::cout<<*it<<std::endl;
    }
    return 1;
} 