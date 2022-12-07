
#include "catch.hpp"
#include <map>
#include <vector>
#include <iostream>
#include <fstream>
#include <set>
#include <queue>
#include "/workspaces/cs225/TheWikiGame/src/TheWikiGame.h"


TEST_CASE("Constructor test") {
    TheWikiGame test = TheWikiGame("/workspaces/cs225/TheWikiGame/ArticleTJason.txt", "/workspaces/cs225/TheWikiGame/ArticleLinksJason.txt");
    REQUIRE(test.getIDByLink("https://en.wikipedia.org/wiki/Abraham_Lincoln") == 1);
    REQUIRE(test.getLinkByID(1) == "https://en.wikipedia.org/wiki/Abraham_Lincoln");
    REQUIRE(test.getIDByLink("https://en.wikipedia.org/wiki/Bushism") == 111);
    REQUIRE(test.getLinkByID(111) == "https://en.wikipedia.org/wiki/Bushism");
    REQUIRE(test.getLinkByID(17321) == "ID not valid");
    REQUIRE(test.getIDByLink("dasasda") == -1);
}