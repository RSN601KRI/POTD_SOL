class Solution {
  public:
    // Function to return the adjacency list for each vertex.
    vector<vector<int>> printGraph(int V, vector<pair<int,int>>edges) {
        vector<vector<int>> adjList(V);
        
        // Iterate through the edges and add them to the adjacency list.
        for (const auto& edge : edges) {
            int u = edge.first;
            int v = edge.second;
            
            // Add v to the adjacency list of u, and u to the adjacency list of v.
            adjList[u].push_back(v);
            adjList[v].push_back(u); // Remove this line if the graph is directed.
        }
        
        return adjList;
    }
};