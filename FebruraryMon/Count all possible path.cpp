class Solution {
public:
	int isPossible(vector<vector<int>>paths){
	    // Code here
	    int n=paths.size();
	    for(int i=0;i<n;i++){
	        int temp=0;
	        for(int j=0;j<n;j++){
	            if(paths[i][j]==1)
	              temp++;
	        }
	        if(temp%2!=0)
	         return 0;
	    }
	    return 1;
	}

};