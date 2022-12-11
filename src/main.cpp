#include "TheWikiGame.h" 
#include <iostream>
int main() {
    //REMEMBER TO CHANGE PATHING EVERYTIME, IT IS DIFFERENT FOR EVERYONE
    //TheWikiGame test = TheWikiGame("/workspaces/cs225/TheWikiGame/ArticleT.txt", "/workspaces/cs225/TheWikiGame/ArticleLinks.txt");
    TheWikiGame test = TheWikiGame("/workspaces/CS225 Labs/TheWikiGame/ArticleTKevin.txt", "/workspaces/CS225 Labs/TheWikiGame/ArticleLinksKevin.txt");
    std::vector<std::string> path = test.bfs("https://en.wikipedia.org/wiki/Nanny_and_Nanko", "https://en.wikipedia.org/wiki/Lee_Harvey_Oswald");
    //TheWikiGame test = TheWikiGame("/workspaces/cs225/TheWikiGame/ArticleTJason.txt", "/workspaces/cs225/TheWikiGame/ArticleLinksJason.txt");
    //std::vector<std::string> path = test.bfs("https://en.wikipedia.org/wiki/Nanny_and_Nanko", "https://en.wikipedia.org/wiki/Nanny_and_Nanko");
    for(auto it = path.begin(); it != path.end(); it++){
        std::cout<<*it<<std::endl;
    }
    test.pageRank(0.85, 1000, 10);
    test.resetPageRank();
    test.pageRank(0.85, 5, 10);
    return 1;
} 