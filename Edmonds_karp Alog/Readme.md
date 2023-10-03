# Edmonds-Karp algorithm
The complexity can be given independently of the maximal flow. The algorithm runs in  
$O(V E^2)$  time, even for irrational capacities. The intuition is, that every time we find an augmenting path one of the edges becomes saturated, and the distance from the edge to  
$s$  will be longer if it appears later again in an augmenting path. The length of the simple paths is bounded by  
$V$ .

## Implementation
The matrix capacity stores the capacity for every pair of vertices. adj is the adjacency list of the undirected graph, since we have also to use the reversed of directed edges when we are looking for augmenting paths.

The function maxflow will return the value of the maximal flow. During the algorithm, the matrix capacity will actually store the residual capacity of the network. The value of the flow in each edge will actually not be stored, but it is easy to extend the implementation - by using an additional matrix - to also store the flow and return it.

