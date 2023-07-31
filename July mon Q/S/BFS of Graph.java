class Solution {
    // Function to return Breadth First Traversal of given graph.
    public ArrayList<Integer> bfsOfGraph(int V, ArrayList<ArrayList<Integer>> adj) {
        ArrayList<Integer> bfsTraversal = new ArrayList<>();
        boolean[] visited = new boolean[V];

        Queue<Integer> queue = new LinkedList<>();
        queue.add(0); // Start BFS from the first vertex (vertex 0)
        visited[0] = true;

        while (!queue.isEmpty()) {
            int currentNode = queue.poll();
            bfsTraversal.add(currentNode);

            // Visit all the adjacent nodes of the current node
            for (int neighbor : adj.get(currentNode)) {
                if (!visited[neighbor]) {
                    queue.add(neighbor);
                    visited[neighbor] = true;
                }
            }
        }

        return bfsTraversal;
    }
}
