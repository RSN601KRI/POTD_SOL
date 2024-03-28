class Solution {
  public:
    int findCity(int n, int m, vector<vector<int>>& edges, int distanceThreshold) {
        // Initialize adjacency matrix with maximum distance
        std::vector<std::vector<int>> dist(n, std::vector<int>(n, INT_MAX / 2));
        
        // Update distances based on given edges
        for (const auto& edge : edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            dist[u][v] = dist[v][u] = w;
        }
        
        // Floyd-Warshall algorithm to find shortest paths
        for (int k = 0; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    dist[i][j] = std::min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
        
        int minNeighbours = n, city = -1;
        
        // Check each city for the number of neighboring cities within distanceThreshold
        for (int i = 0; i < n; ++i) {
            int neighbours = 0;
            for (int j = 0; j < n; ++j) {
                if (i != j && dist[i][j] <= distanceThreshold) {
                    ++neighbours;
                }
            }
            if (neighbours <= minNeighbours) {
                minNeighbours = neighbours;
                city = i;
            }
        }
        
        return city;
    }
};