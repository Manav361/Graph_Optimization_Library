Bellman-Ford Algorithm:

- Bellman-Ford is used to find the shortest path in a weighted graph with negative edge weights and detect negative cycles.
- Applications: It's used in network routing, particularly in situations where negative weights can occur.
- Implementation: Implementing it involves iterating through all edges and vertices, which can be done efficiently in most programming languages.

Complexity of Bellman Ford Algorithm
Time complexity O(V.E).

Based on the "Principle of Relaxation," more accurate values gradually recovered an approximation to the proper distance until finally reaching the optimum solution.
Negative weight edges can generate negative weight cycles, which reduce the total path distance by returning to the same point.

The Bellman-Ford algorithm works by grossly underestimating the length of the path from the starting vertex to all other vertices. The algorithm then iteratively relaxes those estimates by discovering new ways that are shorter than the previously overestimated paths.

We can ensure that the result is optimized by repeating this process for all vertices.
- Step 1: Make a list of all the graph's edges. This is simple if an adjacency list represents the graph.
- Step 2: "V - 1" is used to calculate the number of iterations. Because the shortest distance to an edge can be adjusted V - 1 time at most, the number of iterations will increase the same number of vertices.
- Step 3: Begin with an arbitrary vertex and a minimum distance of zero. Because We are exaggerating the actual distances, all other nodes should be assigned infinity. For each edge u-v, relax the path lengths for the vertices: If distance[v] is greater than distance[u] + edge weight uv, then distance[v] = distance[u] + edge weight uv
- Step 4:If the new distance is less than the previous one, update the distance for each Edge in each iteration. The distance to each node is the total distance from the starting node to this specific node.
- Step 5: To ensure that all possible paths are considered, We must consider alliterations. we will end up with the shortest distance if we do this.

