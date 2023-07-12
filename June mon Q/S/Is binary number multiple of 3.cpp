class Solution {
public:
    int isDivisible(string s) {
        int oddCount = 0;
        int evenCount = 0;
        int n = s.length();

        for (int i = n - 1; i >= 0; i--) {
            
            if (s[i] == '1') {
                
                if ((n - 1 - i) % 2 == 0)
                    evenCount++;
                else
                    oddCount++;
            }
        }

        if ((oddCount - evenCount) % 3 == 0)
            return 1;
        else
            return 0;
    }
};