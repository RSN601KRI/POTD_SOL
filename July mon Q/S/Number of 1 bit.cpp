class Solution {
  public:
    int setBits(int N) 
        int c=0;
        while(N>0){
            if(N&1 == 1){
                c++;
            }
            N=N>>1;
        }
        return c;
    }
};