class Solution {
  public:
    bool lemonadeChange(int N, vector<int> &bills) {
        if(bills[0] != 5) return false;
        unordered_map<int, int> mp;
        for(int i=0; i<bills.size(); i++){
            mp[bills[i]]++;
            if(bills[i] == 10){
                if(mp[5]!=0){
                    mp[5]--;
                }
                else
                    return false;
            }
            if(bills[i] == 20){
                if(mp[10]!=0){
                    mp[10]--;
                    if(mp[5]!=0){
                        mp[5]--;
                    }
                    else
                        return false;
                }
                else{
                    if(mp[5]>=3){
                        mp[5] = mp[5] - 3;
                    }
                    else return false;
                }
            }
        }
        return true;
    }
};