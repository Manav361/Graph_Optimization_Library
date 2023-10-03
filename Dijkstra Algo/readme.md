# Dijkstra Algorithm
You are given a directed or undirected weighted graph with n vertices and m edges. The weights of all edges are non-negative. You are also given a starting vertex s . This article discusses finding the lengths of the shortest paths from a starting vertex $s$  to all other vertices, and output the shortest paths themselves.

This problem is also called single-source shortest paths problem.

## Algorithm
Here is an algorithm described by the Dutch computer scientist Edsger W. Dijkstra in 1959.

Let's create an array d[] where for each vertex v we store the current length of the shortest path from s to v in d[v]. Initially d[s] = 0, and for all other vertices this length equals infinity. In the implementation a sufficiently large number (which is guaranteed to be greater than any possible path length) is chosen as infinity. $$d[v] = \infty,~ v \ne s$$ 
In addition, we maintain a Boolean array  u[]  which stores for each vertex v whether it's marked. Initially all vertices are unmarked:
$$u[v] = {\rm false}$$ The Dijkstra's algorithm runs for n iterations. At each iteration a vertex v is chosen as unmarked vertex which has the least value  d[v] :
Evidently, in the first iteration the starting vertex s will be selected.
The selected vertex  v is marked. Next, from vertex v relaxations are performed: all edges of the form $(v,\text{to})$  are considered, and for each vertex $\text{to}$  the algorithm tries to improve the value $d[\text{to}]$ . If the length of the current edge equals $len$ , the code for relaxation is:
$$d[\text{to}] = \min (d[\text{to}], d[v] + len)$$ After all such edges are considered, the current iteration ends. Finally, after $n$  iterations, all vertices will be marked, and the algorithm terminates. We claim that the found values $d[v]$  are the lengths of shortest paths from $s$  to all vertices $v$ .
Note that if some vertices are unreachable from the starting vertex $s$ , the values $d[v]$  for them will remain infinite. Obviously, the last few iterations of the algorithm will choose those vertices, but no useful work will be done for them. Therefore, the algorithm can be stopped as soon as the selected vertex has infinite distance to it.

Dijkstra's algorithm performs  
$n$  iterations. On each iteration it selects an unmarked vertex  
$v$  with the lowest value  
$d[v]$ , marks it and checks all the edges  
$(v, \text{to})$  attempting to improve the value  
$d[\text{to}]$ .

The running time of the algorithm consists of:

 
$n$  searches for a vertex with the smallest value  
$d[v]$  among  
$O(n)$  unmarked vertices
 
$m$  relaxation attempts
For the simplest implementation of these operations on each iteration vertex search requires  
$O(n)$  operations, and each relaxation can be performed in  
$O(1)$ . Hence, the resulting asymptotic behavior of the algorithm is:

 
$$O(n^2+m)$$ 
This complexity is optimal for dense graph, i.e. when  
$m \approx n^2$ . However in sparse graphs, when  
$m$  is much smaller than the maximal number of edges  
$n^2$ , the problem can be solved in  
$O(n \log n + m)$  complexity
