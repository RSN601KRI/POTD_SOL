class Solution {
public:
	vector<vector<int>>criticalConnections(int v, vector<int> adj[]){
	    // Code here
	     vector<bool> vis(v, 0);
	    vector<int> tin(v, 0), low(v, 0);
	    int timer = 0;
	    
	    vector<vector<int>> ans;
	    
	    function<void(int, int)> dfs = [&](int node, int parent) {
	        vis[node] = 1;
	        tin[node] = low[node] = timer++;
	        
	        for(auto child : adj[node]){
	            if(child == parent) continue;
	            
	            if(vis[child])
	                low[node] = min(low[node], tin[child]); // this is actually an ancestor
	            else{
	                dfs(child, node);
	                
    	            low[node] = min(low[node], low[child]);
    	            
                    if(low[child] > tin[node])
                        ans.push_back({min(node, child), max(node, child)});
	            }
	        }
	    };
	    
	    for(int i = 0; i < v; i++){
	        if(!vis[i])
	            dfs(i, -1);
	    }
	    
	    sort(ans.begin(), ans.end());
	    
	    return ans;
	}
};