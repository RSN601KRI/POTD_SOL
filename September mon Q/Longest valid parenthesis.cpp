class Solution {
  public:
    int maxLength(string& str) {
        // code here
        stack<int> stk; // Stack to store the indices
        int maxLen = 0; // To store the maximum length of valid parentheses
        stk.push(-1);   // Initialize stack with -1 to handle edge cases

        for (int i = 0; i < str.length(); i++) {
            if (str[i] == '(') {
                stk.push(i); // Push the index of '('
            } else {
                stk.pop(); // Pop the top of the stack for a ')'
                
                if (stk.empty()) {
                    stk.push(i); // Push the index of ')' as a new base if the stack is empty
                } else {
                    maxLen = max(maxLen, i - stk.top()); // Calculate the valid length
                }
            }
        }

        return maxLen;
    }
};