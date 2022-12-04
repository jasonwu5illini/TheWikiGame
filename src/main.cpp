#include "TheWikiGame.h" 
#include <iostream>
int main() {
    //REMEMBER TO CHANGE PATHING EVERYTIME, IT IS DIFFERENT FOR EVERYONE
    //TheWikiGame test = TheWikiGame("/workspaces/cs225/TheWikiGame/ArticleT.txt", "/workspaces/cs225/TheWikiGame/ArticleLinks.txt");
    TheWikiGame test = TheWikiGame("/workspaces/cs225/TheWikiGame/ArticleTJason.txt", "/workspaces/cs225/TheWikiGame/ArticleLinksJason.txt");
    std::vector<std::string> path = test.bfs("https://en.wikipedia.org/wiki/Joe_Biden", "https://en.wikipedia.org/wiki/John_Wilkes_Booth");
    for(auto it = path.begin(); it != path.end(); it++){
        std::cout<<*it<<std::endl;
    }
    return 1;
} 