class Solution {
  public:
    int largestSubsquare(int n, vector<vector<char>> a) {
        vector<vector<int>> left(n,vector<int>(n,0));
        vector<vector<int>> top(n,vector<int>(n,0));
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(a[i][j]=='X'){
                    if(j!=0){
                        left[i][j]=left[i][j-1]+1;
                    }
                    else left[i][j]=1;
                    if(i!=0){
                        top[i][j]=top[i-1][j]+1;
                    }
                    else top[i][j]=1;
                }
                int minX=min(top[i][j],left[i][j]);
                while(minX){
                    int k=i-minX+1;
                    int l=j-minX+1;
                    if(left[k][j]>=minX and top[i][l]>=minX){
                        ans=max(ans,minX);
                        break;
                    }
                    minX--;
                }
            }
        }
        return ans;
    }

};