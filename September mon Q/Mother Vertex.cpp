class Solution {
public:
    // Helper function to perform DFS and mark visited vertices
    void dfs(int node, vector<int> adj[], vector<bool>& visited) {
        visited[node] = true;
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                dfs(neighbor, adj, visited);
            }
        }
    }

    // Function to find a Mother Vertex in the Graph.
    int findMotherVertex(int V, vector<int> adj[]) {
        vector<bool> visited(V, false);
        int motherVertex = -1;

        // Perform DFS to find the last visited vertex
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                dfs(i, adj, visited);
                motherVertex = i; // Update the potential mother vertex
            }
        }

        // Now, check if the found potential mother vertex is indeed a mother vertex
        fill(visited.begin(), visited.end(), false); // Reset visited array
        dfs(motherVertex, adj, visited);

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                return -1; // No mother vertex found
            }
        }

        return motherVertex;
    }
};