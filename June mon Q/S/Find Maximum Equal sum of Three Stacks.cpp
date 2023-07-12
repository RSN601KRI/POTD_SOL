# find maximunequal sum of three stacks

class Solution{
public:
    using ll = long long;
    vector<ll> prefSum(vector<int> a){
        vector<ll> ans;
        reverse(a.begin(), a.end());
        int n = a.size();
        ans.resize(n, 0);
        ans[0] = a[0];
        for(int i = 1; i < n; i++){
            ans[i] = a[i] + ans[i-1];
        }
        return ans;
    }
    int maxEqualSum(int N1,int N2,int N3,vector<int> &s1,vector<int> &s2,vector<int> &s3){
        vector<ll> a = prefSum(s1);
        vector<ll> b = prefSum(s2);
        vector<ll> c = prefSum(s3);
        int i = 0, j = 0, k = 0;
        ll ans = 0;
        while( i < N1 &&  j < N2 && k < N3){
            while(j< N2 && b[j] < a[i])
                j++;
            while(k < N3 &&c[k] < a[i])
                k++;
            if(b[j] == c[k] && c[k] == a[i]){
                ans = max(ans,c[k]);
                i++, j++, k++;
            }
            else
                i++;
        }
        return ans;
    }
};