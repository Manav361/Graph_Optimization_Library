# Ford-Fulkerson method
Let's define one more thing. A residual capacity of a directed edge is the capacity minus the flow. It should be noted that if there is a flow along some directed edge  
$(u, v)$ , then the reversed edge has capacity 0 and we can define the flow of it as  
$f((v, u)) = -f((u, v))$ . This also defines the residual capacity for all the reversed edges. We can create a residual network from all these edges, which is just a network with the same vertices and edges, but we use the residual capacities as capacities.

The Ford-Fulkerson method works as follows. First, we set the flow of each edge to zero. Then we look for an augmenting path from  
$s$  to  
$t$ . An augmenting path is a simple path in the residual graph, i.e. along the edges whose residual capacity is positive. If such a path is found, then we can increase the flow along these edges. We keep on searching for augmenting paths and increasing the flow. Once an augmenting path doesn't exist anymore, the flow is maximal.

Let us specify in more detail, what increasing the flow along an augmenting path means. Let  
$C$  be the smallest residual capacity of the edges in the path. Then we increase the flow in the following way: we update  
$f((u, v)) ~\text{+=}~ C$  and  
$f((v, u)) ~\text{-=}~ C$  for every edge  
$(u, v)$  in the path.

Here is an example to demonstrate the method. We use the same flow network as above. Initially we start with a flow of 0.

![image](https://github.com/Manav361/Graph_Optimization_Library/assets/116298483/aa1cd1b3-c32c-4eed-96ed-e82c57115f58)


Flow network
We can find the path  
$s - A - B - t$  with the residual capacities 7, 5, and 8. Their minimum is 5, therefore we can increase the flow along this path by 5. This gives a flow of 5 for the network.
![image](https://github.com/Manav361/Graph_Optimization_Library/assets/116298483/e542c4ac-9832-4277-882b-0860815a3cec)
![image](https://github.com/Manav361/Graph_Optimization_Library/assets/116298483/bedb2f1a-2535-4e92-a85b-96dd7d677cea)


First path Network after first path
Again we look for an augmenting path, this time we find  
$s - D - A - C - t$  with the residual capacities 4, 3, 3, and 5. Therefore we can increase the flow by 3 and we get a flow of 8 for the network.
![image](https://github.com/Manav361/Graph_Optimization_Library/assets/116298483/5f719b47-f087-4e99-b4e3-3ea7dee7d29e)
![image](https://github.com/Manav361/Graph_Optimization_Library/assets/116298483/802ae211-c76a-4e79-9a86-c2eafbb24407)

Second path Network after second path
This time we find the path  
$s - D - C - B - t$  with the residual capacities 1, 2, 3, and 3, and hence, we increase the flow by 1.
![image](https://github.com/Manav361/Graph_Optimization_Library/assets/116298483/3de1a475-7629-428b-9553-233812300951)
![image](https://github.com/Manav361/Graph_Optimization_Library/assets/116298483/4d8687f9-5dd3-4794-b428-3c94a553945b)

Third path Network after third path
This time we find the augmenting path  
$s - A - D - C - t$  with the residual capacities 2, 3, 1, and 2. We can increase the flow by 1. But this path is very interesting. It includes the reversed edge  
$(A, D)$ . In the original flow network, we are not allowed to send any flow from  
$A$  to  
$D$ . But because we already have a flow of 3 from  
$D$  to  
$A$ , this is possible. The intuition of it is the following: Instead of sending a flow of 3 from  
$D$  to  
$A$ , we only send 2 and compensate this by sending an additional flow of 1 from  
$s$  to  
$A$ , which allows us to send an additional flow of 1 along the path  
$D - C - t$ .
![image](https://github.com/Manav361/Graph_Optimization_Library/assets/116298483/e1891d29-2f18-41aa-94de-78ee5cd2eedf)![image](https://github.com/Manav361/Graph_Optimization_Library/assets/116298483/811378a3-c932-4cc8-bc67-e25024b2fd6c)


Fourth path Network after fourth path
Now, it is impossible to find an augmenting path between  
$s$  and  
$t$ , therefore this flow of  
$10$  is the maximal possible. We have found the maximal flow.

It should be noted, that the Ford-Fulkerson method doesn't specify a method of finding the augmenting path. Possible approaches are using DFS or BFS which both work in  
$O(E)$ . If all the capacities of the network are integers, then for each augmenting path the flow of the network increases by at least 1 (for more details see Integral flow theorem). Therefore, the complexity of Ford-Fulkerson is  
$O(E F)$ , where  
$F$  is the maximal flow of the network. In the case of rational capacities, the algorithm will also terminate, but the complexity is not bounded. In the case of irrational capacities, the algorithm might never terminate, and might not even converge to the maximal flow.
