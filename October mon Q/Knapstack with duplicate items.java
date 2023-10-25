class Solution{
    static int solve(int ind, int w, int val[], int wt[], int dp[][]) {
        if(ind == 0) 
            return val[0] * (w / wt[0]);
        
        if(dp[ind][w] != -1)
            return dp[ind][w];
        
        int notTake = solve(ind - 1, w, val, wt, dp);
        int take = Integer.MIN_VALUE;
        
        if(wt[ind] <= w) 
            take = val[ind] + solve(ind, w - wt[ind], val, wt, dp);
        
        return dp[ind][w] = Math.max(take, notTake);
    }
    
    static int knapSack(int n, int w, int val[], int wt[]) {
        int [][]dp = new int[n][w + 1];
        for(int i = 0; i < n; i++)
            for(int j = 0; j <= w; j++)
                dp[i][j] = -1;
            
        return solve(n - 1, w, val, wt, dp);
    }
}