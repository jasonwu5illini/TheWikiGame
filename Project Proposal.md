## Leading Question 

- Wikipedia is a multilingual free online encyclopedia written and maintained by a community of volunteers through open collaboration and a wiki-based editing system. A fantastic way to entertain yourself when you’re bored is to play a game called the Wiki Game (more information can be found at https://www.thewikigame.com/group). The objective of the game is to traverse from one randomly generated Wikipedia page to another in either the shortest amount of time or the shortest number of clicks. However, due to the imperfection of the human mind, it is very unlikely that the user will be able to find the shortest path from one page to another. In our project, we will use graph algorithms and the current Wikipedia dataset to find the series of pages that takes the least amount of clicks and predict the series of pages that take the least amount of time.


## Dataset Acquisition

- We have chosen to use the dataset of all the articles on English Wikipedia as of August 1st, 2022. We have acquired the dataset through a publically available web page with data dumps from the Wikimedia foundation, the hosting platform of Wikipedia. 


## Data Format

- The dataset was acquired as the file enwiki-20220801-pages-articles-multistream.xml.bz2. It is a XML file compressed in the bz2 format. XML is a standardized markup language and file format used for storing and transmitting data. The compressed file is 19 gigabytes and the uncompressed file is over 86 gigabytes. We will have to use the entire dataset because all articles on English Wikipedia are fair game for the starting article. However, we plan to only search through a subset of the data based on the parameter given to us. In the constraints of the wikipedia game, we only need to be concerned about articles accessible from the starting wikipedia article. Therefore the subset is defined as all the articles accessible from the starting wikipedia article until the target article is located. 

## Data Correction

- To verify the integrity of downloaded files, we will use free tools available online to generate the md5 and/or sha1 checksums and compare them against the given ones. This will guard against the possibility of any corrupted files and the issue of missing entries should be corrected. Due to the nature of the dataset, issues such as values not physically possible or outliers can also be disregarded. 

## Data Storage

- We are storing the links in a map with the keys being the links (converted to string) and the values being ints. These integers are indices corresponding to each page (“link”). We create another map simultaneously with the keys and values reversed. This effectively creates a bidirectional map through which we can convert from index to string and string to index. We then have a third map which contains each index as a key and its value is a list of the other indices this page is connected to. We expect, if the number of pages is V and the number of edges is E, that the big O for storage will be proportional to O(V + E) at greatest.

## Algorithm 

##### Breadth First Search Traversal

- The inputs to all of our algorithms are the nodes (Wikipedia pages) and edges (which pages cite which other pages). To support our algorithms, we will create weighted directional graphs (directed edge arrays). We will write a BFS traversal, which allows us to traverse just the edges from each node, which is more optimized than a straight DFS which may go for a long time before it reaches a dead end or finishes a cycle of citations. The BFS traversal should output the shortest path(s) [counted in website clicks] from a starting page to an ending page. The graph will be a directed graph, as links to pages are one way, unless there is a link in the new page that goes back to the old page.

- A concern regarding this traversal is that the expansiveness of Wikipedia may make it difficult for BFS to find a path to a page before the width/queue of the BFS becomes way too large and we would need to sift through massive amounts of data. However, using the idea of “six degrees of separation” (https://en.wikipedia.org/wiki/Six_degrees_of_separation) and the size of the Wikipedia network, we will assume that every page will be within six degrees (may expand to seven degrees if we can run the program in time) of another page if a path exists. So, our BFS depth will go up to a depth of six and if no path is found, we will assume the path does not exist.

- The efficiency of our graph will be O(V+E), where V is the number of nodes (pages we visit), and E is the number of edges/connections within the graph. It’s important to note that V and E are only for the subset of pages that we visit through BFS, not the entire set of data, which is much more expansive. This means unconnected nodes and nodes further than six degrees away will not be included in our traverse space.

##### Djikstra’s Shortest Path

- The inputs to our Djikstra’s algorithm is the same as above. This time, we will assume that the edges of our graphs are weighed differently. When playing the Wiki Game, the links at the top of a page receive much more attention and much quicker attention compared to the links at the bottom of the page. We will simulate this by parsing through the webpage and weighing the earlier links smaller compared to the later links. Djikstra’s algorithm will then be used to traverse the links and the edges/connections are weighted by the amount of scrolling time it takes to reach each link on the current page (roughly estimated). 

- Similar to BFS, we will return the shortest time path(s) within the subset of data we’re sampling using the idea of six degrees of separation. The output will be the list of shortest paths that will be visualized using our graph visualization algorithm.

- Djikstra runs in O(E log V) time, where V is the number of nodes (pages we visit) in our subset and E is the number of connections between nodes. Again, the number of nodes and edges are only those that are within our subset, not within the entire Wikipedia page space.


##### Graph Visualization

- We will use draw a simple graph in a similar way to painting the canvas with mp_mazes. We will assign each vertex a center coordinate with a radius. So, each node will be drawn out as a circle with a certain radius. Then, we will connect the centers of these circles with lines, which will resemble the edges that connect the nodes to each other.

- This tool will draw out all the shortest paths, and show the series of pages as nodes that allow us to reach our final destination.


## Timeline

##### Data Acquisition: 11/5

This task consists of downloading the data, verifying its integrity, and getting a feel of the specific formatting.

##### Data Processing: 11/8

This task consists of assigning all the article links to a number and storing it into a map (the key being the article link as a string and the value being the assigned int). We will also make a map of the inverse so we can lookup article links with the corresponding int. Then we will make a map with the key theoretically being the article link and the value being a vector of all the articles linked to it on the key article (adjacency list). However, in practice it will be an int and a vector of ints to save on storage. 

##### BFS: 11/11

We will complete the BFS traverse algorithm that allows us to find the shortest click path(s) between two Wikipedia articles. This includes taking the input of the two randomly generated pages and returning the list of paths that work.

##### Djikstras: 11/18

This task consists of implementing an algorithm that allows us to find the path that prioritizes articles that show up earlier on the webpage than later. We will assign different weights to the edges based on how far up the page the link shows up at. The function will be similar to that of the BFS, which takes in two pages and returns the list of paths that work. 

##### Visualization: 11/25 
This task consists of writing code to write the shortest path(s) to files from which they are taken and displayed in a visual format using python. They will be organized in a special format/order for presentability using a C++ algorithm before being written into the file.

##### Final Presentation and Report: 12/4

For the last week of our project, we will finish up bugs and ensure that our project functions as expected. We will record our final presentation and write the final report, and making our final deadline four days before the actual due date will give us some additional to wrap up any loose ends.

