class Solution{
    public
    int fact(int n){
        if(n==0) return 1;
        else return n*fact(n-1);
    }
    vector<string> permutation(string S)
    {
        vector<string> res;
        int n = S.size();
        long long m = fact(n);
        for(int i=0;i<m;i++){
            next_permutation(S.begin(),S.end());
            res.push_back(S);
        }
        sort(res.begin(),res.end());
        return res;
    }
};