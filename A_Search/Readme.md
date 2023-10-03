# A* Search Algorithm
A* search algorithm is an algorithm that separates it from other traversal techniques. This makes A* smart and pushes it much ahead of conventional algorithms. 

Let’s try to understand Basic AI Concepts and comprehend how does A* algorithm work. Imagine a huge maze that is too big that it takes hours to reach the endpoint manually. Once you complete it on foot, you need to go for another one. This implies that you would end up investing a lot of time and effort to find the possible paths in this maze. Now, you want to make it less time-consuming. To make it easier, we will consider this maze as a search problem and will try to apply it to other possible mazes we might encounter in due course, provided they follow the same structure and rules.

As the first step to converting this maze into a search problem, we need to define these six things.

1) A set of prospective states we might be in
2) A beginning and end state
3) A way to decide if we’ve reached the endpoint
4) A set of actions in case of possible direction/path changes
5) A function that advises us about the result of an action 
6) A set of costs incurring in different states/paths of movement
To solve the problem, we need to map the intersections to the nodes (denoted by the red dots) and all the possible ways we can make movements towards the edges (denoted by the blue lines).
A denotes the starting point, and B denotes the endpoint. We define the starting and endpoints at nodes A and B, respectively.
If we use an uninformed search algorithm, it would be like finding a path that is blind, while an informed algorithm for a search problem would take the path that brings you closer to your destination. For instance, consider Rubik’s cube; it has many prospective states that you can be in, making the solution very difficult. This calls for the use of a guided search algorithm to find a solution. This explains the importance of A*.  
Unlike other algorithms, A* decides to take up a step only if it is convincingly sensible and reasonable as per its functions. This means it never considers any non-optimal steps. This is why A* is a popular choice for AI systems that replicate the real world – like video games and machine learning. 

## A* Search Algorithm Steps

Step 1: Add the beginning node to the open list
Step 2: Repeat the following step

In the open list, find the square with the lowest F cost, which denotes the current square. Now we move to the closed square.

Consider 8 squares adjacent to the current square and Ignore it if it is on the closed list or if it is not workable. Do the following if it is workable.

Check if it is on the open list; if not, add it. You need to make the current square as this square’s a parent. You will now record the different costs of the square, like the F, G, and H costs. 

If it is on the open list, use G cost to measure the better path. The lower the G cost, the better the path. If this path is better, make the current square as the parent square. Now you need to recalculate the other scores – the G and F scores of this square. 

– You’ll stop:

If you find the path, you need to check the closed list and add the target square to it.

There is no path if the open list is empty and you cannot find the target square.

Step 3. Now you can save the path and work backward, starting from the target square, going to the parent square from each square you go, till it takes you to the starting square. You’ve found your path now.  

