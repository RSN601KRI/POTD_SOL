//User function Template for Java
class Solution {

	public int[] shortestPath(int N,int M, int[][] edges) {
        // Initialize the distance array with infinity
        int[] shortestPath = new int[N];
        Arrays.fill(shortestPath, Integer.MAX_VALUE);
        shortestPath[0] = 0;

        // Relax all the edges
        for (int i = 0; i < N - 1; i++) {
            for (int j = 0; j < M; j++) {
                int u = edges[j][0];
                int v = edges[j][1];
                int weight = edges[j][2];

                if (shortestPath[u] != Integer.MAX_VALUE && shortestPath[u] + weight < shortestPath[v]) {
                    shortestPath[v] = shortestPath[u] + weight;
                }
            }
        }

        // Check for negative cycles
        for (int i = 0; i < M; i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int weight = edges[i][2];

            if (shortestPath[u] != Integer.MAX_VALUE && shortestPath[u] + weight < shortestPath[v]) {
                shortestPath[v] = -1;
            }
        }

        // Convert -1 to infinity for unreachable nodes
        for (int i = 0; i < N; i++) {
            if (shortestPath[i] == Integer.MAX_VALUE) {
                shortestPath[i] = -1;
            }
        }

        return shortestPath;
    }
}