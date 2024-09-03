class Solution{
	public:
	int minOperations(string str1, string str2) 
	{ 
	    // Your code goes here
	    int n = str1.length(), m = str2.length();
	    int dp[n+1][m+1];
	    for(int i=0;i<=n;i++)dp[i][0]=0;
	    for(int j=0;j<=m;j++)dp[0][j]=0;
	    for(int i=1;i<=n;i++){
	        for(int j=1;j<=m;j++){
	            dp[i][j] = str1[i-1]==str2[j-1]?1+dp[i-1][j-1]:max(dp[i-1][j],dp[i][j-1]);
	        }
	    }
	    return n+m-2*dp[n][m];
	} 
};