class Solution {
public:
    bool isPossible(const std::vector<std::vector<int>>& heights, int threshold) {
        int rows = heights.size();
        int columns = heights[0].size();
        
        std::vector<std::vector<bool>> visited(rows, std::vector<bool>(columns, false));
        
        return dfs(heights, 0, 0, rows, columns, threshold, visited);
    }
    
    bool dfs(const std::vector<std::vector<int>>& heights, int i, int j, int rows, int columns, int threshold, std::vector<std::vector<bool>>& visited) {
        if (i == rows - 1 && j == columns - 1)
            return true;
        
        visited[i][j] = true;
        
        int directions[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        
        for (const auto& dir : directions) {
            int ni = i + dir[0];
            int nj = j + dir[1];
            
            if (ni >= 0 && ni < rows && nj >= 0 && nj < columns && !visited[ni][nj]) {
                int diff = std::abs(heights[ni][nj] - heights[i][j]);
                if (diff <= threshold) {
                    if (dfs(heights, ni, nj, rows, columns, threshold, visited))
                        return true;
                }
            }
        }
        
        return false;
    }
    
    int MinimumEffort(int rows, int columns, std::vector<std::vector<int>>& heights) {
        int left = 0, right = 1e9;
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (isPossible(heights, mid))
                right = mid;
            else
                left = mid + 1;
        }
        
        return left;
    }
};