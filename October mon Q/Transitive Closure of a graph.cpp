class Solution{
public:
    vector<vector<int>> transitiveClosure(int N, vector<vector<int>> graph)
    {
        // Initialize the result matrix with the given graph.
        vector<vector<int>> result = graph;

        // Perform the Floyd-Warshall algorithm.
        for (int k = 0; k < N; k++) {
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    // If there is a path from i to k and from k to j, mark i to j as reachable.
                    if (result[i][k] && result[k][j]) {
                        result[i][j] = 1;
                    }
                }
            }
        }

        return result;
    }
};