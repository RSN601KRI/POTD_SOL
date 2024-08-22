class Solution{
    public:
    string findOrder(string dict[], int N, int K) {
        //code here
        vector<int> adj[K];
        vector<int> inDegree(K, 0);
        
        // Step 2: Build the graph from the dictionary
        for (int i = 0; i < N - 1; i++) {
            string word1 = dict[i];
            string word2 = dict[i + 1];
            int len = min(word1.size(), word2.size());
            
            for (int j = 0; j < len; j++) {
                if (word1[j] != word2[j]) {
                    adj[word1[j] - 'a'].push_back(word2[j] - 'a');
                    inDegree[word2[j] - 'a']++;
                    break;  // Only the first different character between the two words defines the order
                }
            }
        }
        // Step 3: Perform topological sort (Kahn's algorithm)
        queue<int> q;
        string order;
        
        // Add all characters with inDegree 0 to the queue
        for (int i = 0; i < K; i++) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }
        
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            order += (char)(node + 'a');
            
            for (int neighbor : adj[node]) {
                inDegree[neighbor]--;
                if (inDegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }
        // Step 4: Check if the order contains all the characters
        if (order.size() < K) {
            return ""; // There is a cycle in the graph, invalid order
        }
        
        return order;
    }
};