class Solution{   
public:
    string printMinNumberForPattern(string S){
        int n = S.length();
        stack<int> stk;
        string result;

        int current = 1; // Current number to be pushed into the stack

        for (int i = 0; i <= n; ++i) {
            stk.push(current++);

            if (i == n || S[i] == 'I') {
                while (!stk.empty()) {
                    result += to_string(stk.top());
                    stk.pop();
                }
            }
        }

        return result;
    }
};