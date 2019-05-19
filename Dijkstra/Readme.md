#Dijkstra

Dijkstra's algorithm is an algorithm for finding the shortest paths between nodes in a graph, which may represent, for example, road networks.

The algorithm exists in many variants; Dijkstra's original variant found the shortest path between two nodes but a more common variant fixes a single node as the "source" node and finds shortest paths from the source to all other nodes in the graph, producing a shortest-path tree.

In source code i used vector and priority_queue from stl to implement Dijkstra's algorithm . The main idea is to remove the node with lowest cost every time . To remove faster i used a data structure called heap whose insertion and deletion has a complexity of O(log N) . It's important to know that Dijkstra algorithm works on graphs with positive cost.
