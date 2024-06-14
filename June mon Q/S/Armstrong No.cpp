class Solution {
  public:
    string armstrongNumber(int n){
        // code here
        string numStr = to_string(n);
        int d = numStr.length();
        int sum = 0;
        
        // Calculate the sum of each digit raised to the power d
        for(char digit : numStr){
            int digitValue = digit - '0';
            sum += pow(digitValue, d);
        }
        
        // Check if the sum is equal to the original number
        if(sum == n){
            return "Yes";
        } else {
            return "No";
        }
    }
};