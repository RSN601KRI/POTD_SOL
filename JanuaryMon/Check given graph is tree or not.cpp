class Solution {
  public:
    int isTree(int n, int m, vector<vector<int>> &edge) {
        if(m != n - 1)
            return 0;
            
        vector<int> vis(n, 0);
        vector<vector<int>> g(n);
        
        for(int i = 0; i < m; i++){
            g[edge[i][0]].push_back(edge[i][1]);
            g[edge[i][1]].push_back(edge[i][0]);
        }
        
        function<bool(int, int)> dfs = [&](int node, int parent) -> bool {
            bool ans = 1;
            vis[node] = 1;
            
            for(auto child : g[node]){
                if(!vis[child])
                    ans = ans and dfs(child, node);
                else if(child != parent)
                    return 0;
            }
            
            return ans;
        };
        
        bool ans = 1;
        int cc = 0;
        
        for(int i = 0; i < n; i++){
            if(!vis[i]){
                ans = ans and dfs(i, -1);
                ++cc;   
            }
        }
        
        return ans and cc == 1;
    }
};


