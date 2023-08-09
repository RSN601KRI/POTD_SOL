class Solution{
public: 
    long long int largestPrimeFactor(int N){
    long long ans = 0;
    for(long long i = 2 ; i * i <= N ; i++) {
        if(N % i == 0) {
            ans = max(ans , i);
            while(N % i == 0) {
                N = N / i;
            }
        }
    }
    ans = max(ans , (long long)N);
    return ans;
    }
};
