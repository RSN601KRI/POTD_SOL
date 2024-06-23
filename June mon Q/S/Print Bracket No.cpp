class Solution {
  public:

    vector<int> bracketNumbers(string str) {
        // Your code goes here
         vector<int> result;
        stack<int> s;
        int counter = 1;

        for (char ch : str) {
            if (ch == '(') {
                s.push(counter);
                result.push_back(counter);
                counter++;
            } else if (ch == ')') {
                if (!s.empty()) {
                    result.push_back(s.top());
                    s.pop();
                }
            }
        }

        return result;
    }
};