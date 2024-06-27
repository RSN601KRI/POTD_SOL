#include <vector>
using namespace std;

bool isToepliz(vector<vector<int>>& mat) {
    // code here
    int rows = mat.size();
    int cols = mat[0].size();
    
    for (int i = 0; i < rows - 1; ++i) {
        for (int j = 0; j < cols - 1; ++j) {
            if (mat[i][j] != mat[i + 1][j + 1]) {
                return false;
            }
        }
    }
    return true;
}