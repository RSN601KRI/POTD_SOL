class Solution {
  public:
    long long findNth(long long n) {
        // code here.
        long long start = n;
        string ans = "";
        while(start>0){
            int rem = start%9;
            ans += '0' + rem;
            start /= 9;
        }
        reverse(ans.begin(),ans.end());
        long long final = stoll(ans);
        return final;
    }
};