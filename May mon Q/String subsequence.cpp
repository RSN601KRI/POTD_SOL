class Solution {
  public:
    int solve(string &s1,string &s2,int i,int j,vector<vector<int>>&dp){
        if(j >= s2.size()) return 1;
        if(i >= s1.size()) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int pick=0 ,nopick =0;
        if(s1[i]== s2[j]){
            pick=solve(s1,s2,i+1,j+1,dp) + solve(s1,s2,i+1,j,dp);
        }
        else{
            nopick= solve(s1,s2,i+1,j,dp);
        }
        return dp[i][j]=(pick + nopick) % 1000000007;
    }
    int countWays(string s1, string s2) {
        vector<vector<int>>dp(s1.size(),vector<int>(s2.size(),-1));
        return solve(s1,s2,0,0,dp);
    }
};