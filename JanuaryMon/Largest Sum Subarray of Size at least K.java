class Solution{
    public:    
    long long int maxSumWithK(long long int a[], long long int n, long long int k) 
    { vector<long long> dp(n + 1, 0);
        
        for(int i = n - 1; i > -1; i--){
            dp[i] = a[i] + dp[i + 1];
            dp[i] = max(dp[i], 0LL);
        }
            
        long long ans = -1e18;
        
        long long cur_sum = 0;
        for(int i = 0; i < k; i++)
            cur_sum += a[i];
        
        for(int i = k; i < n; i++){
            long long sum = cur_sum + dp[i];
            ans = max(ans, sum);
            
            cur_sum += a[i];
            cur_sum -= a[i - k]; 
        }
        
        return max(ans, cur_sum);
    }
};