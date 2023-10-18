class Solution {
public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        vector<int> result;
        vector<int> color(V, 0); // 0: unvisited, 1: visiting, 2: visited
        
        for (int i = 0; i < V; i++) {
            if (dfs(i, adj, color)) {
                result.push_back(i);
            }
        }
        
        return result;
    }
    
    bool dfs(int node, vector<int> adj[], vector<int>& color) {
        if (color[node] == 1) {
            return false; // Cycle detected, not safe
        }
        if (color[node] == 2) {
            return true; // Already visited and confirmed safe
        }
        
        color[node] = 1; // Mark as visiting
        
        for (int neighbor : adj[node]) {
            if (!dfs(neighbor, adj, color)) {
                return false;
            }
        }
        
        color[node] = 2; // Mark as visited and safe
        return true;
    }
};
