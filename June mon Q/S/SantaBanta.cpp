#This is a function problem. The input is already taken care of by the driver code. You only need to complete the function helpSanta() that takes a number of girls (n), a number of connections (m), a 2-D array of girls connections (g), and return the Kth prime no if there are no connections then return -1. The driver code takes care of the printing.

class Solution{
public:
    vector<int> primes,is_prime;
    void precompute(){
        int N = 2000000;
        is_prime.resize(N);
        primes.clear();
        for(int i=0;i<N;i++)
            is_prime[i]=1;
        is_prime[1]=0;
        for(int i=2;i*i<N;i++){
            if(is_prime[i]){
                for(int j=i*i;j<N;j+=i){
                    is_prime[j]=0;
                }
            }
        }
        for(int i=0;i<N;i++){
            if(is_prime[i])
                primes.push_back(i);
        }
    }
    int helpSanta(int n, int m, vector<vector<int>> &graph){
        if(m==0)
            return -1;
        vector<int> vis(n+1);
        int ans=0;
        for(int i=1;i<=n;i++){
            if(!vis[i]){
                int count=0;
                queue<int> q;
                q.push(i);
                vis[i]=1;
                while(!q.empty()){
                    int node=q.front();
                    q.pop();
                    count++;
                    for(int it: graph[node]){
                        if(!vis[it]){
                            vis[it]=1;
                            q.push(it);
                        }
                    }
                }
                ans=max(ans,count);
            }
        }
        return primes[ans];
    }
};