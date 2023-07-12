class Solution{
public:
       int nCr(int n,int r){
           int dp[n+1][r+1];
           int mod=1e9+7;
           for(int i=0;i<=n;i++){
               for(int j=0;j<=r;j++){
                   if(j==0 || i==j){
                       dp[i][j]=1;
                   }
                   else if(j>i){
                       dp[i][j]=0;
                   }
                   else{
                       dp[i][j]=(dp[i-1][j-1]+dp[i-1][j])%mod;
                   }
               }
           }
       return dp[n][r];
   }
};