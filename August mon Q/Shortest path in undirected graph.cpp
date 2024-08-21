class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        // code here
        // Create an adjacency list to represent the graph
        vector<vector<int>> adj(N);
        for (int i = 0; i < M; i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        // Initialize distances with a large value, -1 is used here to signify unreachable nodes
        vector<int> dist(N, -1);
        
        // BFS initialization
        queue<int> q;
        q.push(src);
        dist[src] = 0;
        
        // BFS traversal
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            
            for (int neighbor : adj[node]) {
                if (dist[neighbor] == -1) { // If the neighbor hasn't been visited yet
                    dist[neighbor] = dist[node] + 1;
                    q.push(neighbor);
                }
            }
        }
        
        return dist;
    }
};