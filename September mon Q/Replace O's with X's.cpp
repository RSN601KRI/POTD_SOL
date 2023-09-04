class Solution {
public:
    void dfs(vector<vector<char>>& mat, int i, int j) {
        if (i < 0 || i >= mat.size() || j < 0 || j >= mat[0].size() || mat[i][j] != 'O') {
            return;
        }
        
        mat[i][j] = 'B'; // Mark 'O' as boundary-connected
        
        // Visit neighboring cells
        dfs(mat, i - 1, j);
        dfs(mat, i + 1, j);
        dfs(mat, i, j - 1);
        dfs(mat, i, j + 1);
    }

    vector<vector<char>> fill(int n, int m, vector<vector<char>>& mat) {
        if (n == 0 || m == 0) {
            return mat;
        }

        // Mark 'O' characters connected to the boundary
        for (int i = 0; i < n; ++i) {
            if (mat[i][0] == 'O') {
                dfs(mat, i, 0);
            }
            if (mat[i][m - 1] == 'O') {
                dfs(mat, i, m - 1);
            }
        }
        
        for (int j = 0; j < m; ++j) {
            if (mat[0][j] == 'O') {
                dfs(mat, 0, j);
            }
            if (mat[n - 1][j] == 'O') {
                dfs(mat, n - 1, j);
            }
        }

        // Replace 'O' with 'X' and 'B' with 'O'
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (mat[i][j] == 'O') {
                    mat[i][j] = 'X';
                } else if (mat[i][j] == 'B') {
                    mat[i][j] = 'O';
                }
            }
        }

        return mat;
    }
};
