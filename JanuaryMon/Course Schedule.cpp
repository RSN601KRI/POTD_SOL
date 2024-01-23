class Solution
{
  public:
    vector<int> findOrder(int n, int m, vector<vector<int>> prerequisites) 
    {
        vector<int> result;
        vector<int> inDegree(n, 0);
        vector<vector<int>> graph(n, vector<int>());

        // Build the graph and calculate in-degrees
        for (const auto &prerequisite : prerequisites)
        {
            graph[prerequisite[1]].push_back(prerequisite[0]);
            inDegree[prerequisite[0]]++;
        }

        // Initialize a queue for BFS
        queue<int> q;
        for (int i = 0; i < n; i++)
        {
            if (inDegree[i] == 0)
            {
                q.push(i);
            }
        }

        // Perform BFS
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            result.push_back(node);

            for (int neighbor : graph[node])
            {
                inDegree[neighbor]--;
                if (inDegree[neighbor] == 0)
                {
                    q.push(neighbor);
                }
            }
        }

        // Check if all nodes are visited
        if (result.size() == n)
        {
            return result;
        }
        else
        {
            return {};
        }
    }
};