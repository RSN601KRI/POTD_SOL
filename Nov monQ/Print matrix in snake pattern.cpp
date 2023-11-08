#include <vector>

class Solution {
public:
    // Function to return a list of integers visited in a snake pattern in the matrix.
    vector<int> snakePattern(vector<vector<int>>& matrix) {
        vector<int> result;
        int rows = matrix.size();
        int cols = matrix[0].size();
        
        for (int i = 0; i < rows; i++) {
            if (i % 2 == 0) {
                // Go from left to right in even rows.
                for (int j = 0; j < cols; j++) {
                    result.push_back(matrix[i][j]);
                }
            } else {
                // Go from right to left in odd rows.
                for (int j = cols - 1; j >= 0; j--) {
                    result.push_back(matrix[i][j]);
                }
            }
        }
        
        return result;
    }
};
