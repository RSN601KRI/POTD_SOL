class Solution
{
	public:
	//Function to find the level of node X.
	int nodeLevel(int V, vector<int> adj[], int X) 
	{
	    queue<pair<int,int>>q;
	    vector<int>vis(V,0);
	    q.push({0,0});
	    vis[0] = 1;
	    while(!q.empty()) {
	        pair<int,int>p = q.front();
	        q.pop();
	        int node = p.first;
	        int dist = p.second;
	        if(node == X) return dist;
	        for(auto it: adj[node]) {
	            if(!vis[it]) {
	                q.push({it,dist+1});
	                vis[it] = 1;
	            }
	        }
	    }
	    return -1;
	}
};