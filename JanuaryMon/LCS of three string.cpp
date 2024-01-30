#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int LCSof3(string A, string B, string C, int n1, int n2, int n3)
    {
        vector<vector<vector<int>>> dp(n1 + 1, vector<vector<int>>(n2 + 1, vector<int>(n3 + 1, 0)));

        for (int i = 1; i <= n1; ++i)
        {
            for (int j = 1; j <= n2; ++j)
            {
                for (int k = 1; k <= n3; ++k)
                {
                    if (A[i - 1] == B[j - 1] && B[j - 1] == C[k - 1])
                        dp[i][j][k] = dp[i - 1][j - 1][k - 1] + 1;
                    else
                        dp[i][j][k] = max({dp[i - 1][j][k], dp[i][j - 1][k], dp[i][j][k - 1]});
                }
            }
        }

        return dp[n1][n2][n3];
    }
};

int main()
{
    Solution s;

    // Example 1
    string A1 = "geeks";
    string B1 = "geeksfor";
    string C1 = "geeksforgeeks";
    int n1 = A1.length();
    int n2 = B1.length();
    int n3 = C1.length();
    cout << "Example 1: " << s.LCSof3(A1, B1, C1, n1, n2, n3) << endl;

    // Example 2
    string A2 = "abcd";
    string B2 = "efgh";
    string C2 = "ijkl";
    int n4 = A2.length();
    int n5 = B2.length();
  
}
