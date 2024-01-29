class Solution{
	public:
	int TotalCount(string str){
	    int n = str.size();
	    vector<int> suffix(n + 1, 0);
	    int MAX = 0;
	    
	    for(int i = n - 1; i > -1; i--)
	        suffix[i] = suffix[i + 1] + (str[i] - '0'), MAX += (str[i] - '0');
	   
	    vector<vector<int>> dp(n + 1, vector<int> (MAX + 1, 0));
	    
	    for(int i = 0; i < n; i++){
	        for(int j = suffix[0] - suffix[i + 1]; j < MAX + 1; j++)
	            dp[i][j] = 1;
	    }
	    
	    for(int end = 0; end < n; end++){
	        for(int sum = 0; sum < MAX + 1; sum++){
                int low = -1;
                int high = end + 1;
                
                while(low < high - 1){
                    int mid = low + (high - low) / 2;
                    
                    int cur_sum = suffix[mid] - suffix[end + 1];
                    
                    if(cur_sum <= sum)
                        high = mid;
                    else
                        low = mid;
                }
                
                for(int br = high; br < end + 1; br++){
                    int cur_sum = suffix[br] - suffix[end + 1];
                    
                    if(cur_sum <= sum)
                        dp[end][sum] += (br > 0 ? dp[br - 1][cur_sum] : 0);
                }
	        }
	    }
	    
	    
	    return dp[n - 1][MAX];
	}

};