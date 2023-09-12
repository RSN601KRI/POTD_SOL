class Solution{
public:
    bool isLucky(int n) {
        int map = n,counter = 2;
        while(map>=counter){
            if(map%counter==0)return 0;
            map = (map/counter)*(counter-1) + map%counter; 
            counter++;
        }
        return true;
    }
};
