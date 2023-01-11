## General Setup

Before explaining how each of our algorithms were implemented, we will first describe how our class is setup. Our game class consists of three maps that allow us to create and optimize our algorithms. The first two maps are used for optimization purposes, allowing us to convert a Wikipedia link (string) to an article ID (integer) that we assign to each of the Wikipedia articles within our dataset. The two maps create a bijection between the links and the IDs, and because comparing integers is more efficient than comparing strings, we will convert our links to IDs before making comparisons within our algorithms. Finally, our third map is an adjacency list for each of our article IDs, with the key being the article ID and the value being a vector of article IDs. This vector will hold all the articles that you can get to through the page associated with the article ID. The graph generated will be a directed graph, as just because there is a link on page A that leads to page B, it does not necessarily mean there is a link on page B that leads back to page A.

## Breadth First Search

Our first/traversal algorithm uses BFS to find the shortest path between two articles. In this case, we define the shortest path as the least amount of clicks/page traversals required to get from the starting page to the ending page. We first check to make sure both our starting link and ending link are valid Wikipedia links within our dataset. We then need to keep track of pages that we've already visited so we don't get stuck in an endless loop and we need a boolean to determine whether we have found a path or not. Finally, to get the series of pages of our shortest path, we use a similar idea to union find where instead of keeping track of the parent node, we keep track of the previous page ID of our traversal so we can backtrack later. We then perform a typical BFS algorithm using a queue and the adjacency list map, and when the adjacent ID is found to be the same as our end ID, then we know we've found a valid path, and we update the found path boolean value to true to signify we have found a path. If the queue empties before we find a path, then we know that the path does not exist, so we keep our found boolean as false. If we could not find a path, then we let the user know that it is impossible to travel between the two pages. If there is a path, we use our union find array to trace the path from the end to the start and add each article to the final vector we return.