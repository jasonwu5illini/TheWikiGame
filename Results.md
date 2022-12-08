## General Setup

Before explaining how each of our algorithms were implemented, we will first describe how our class is setup. Our game class consists of three maps that allow us to create and optimize our algorithms. The first two maps are used for optimization purposes, allowing us to convert a Wikipedia link (string) to an article ID (integer) that we assign to each of the Wikipedia articles within our dataset. The two maps create a bijection between the links and the IDs, and because comparing integers is more efficient than comparing strings, we will convert our links to IDs before making comparisons within our algorithms. Finally, our third map is an adjacency list for each of our article IDs, with the key being the article ID and the value being a vector of article IDs. This vector will hold all the articles that you can get to through the page associated with the article ID.

## Breadth First Search

Our first/traversal algorithm uses BFS to find the leas
