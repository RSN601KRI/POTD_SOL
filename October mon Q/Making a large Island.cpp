class Solution
{
public:
    int largestIsland(vector<vector<int>>& grid) 
    {
        int m = grid.size();
        int n = grid[0].size();
        int maxIslandSize = 0;
        int islandId = 2; // Use 2 and onwards to label different islands.

        // A map to store the size of each island using islandId as the key.
        unordered_map<int, int> islandSizes;

        // Define the four possible directions (up, down, left, right).
        vector<int> dx = {0, 0, 1, -1};
        vector<int> dy = {1, -1, 0, 0};

        // DFS function to calculate the size of an island and label it.
        function<int(int, int, int)> dfs = [&](int x, int y, int currentIslandId) {
            if (x < 0 || x >= m || y < 0 || y >= n || grid[x][y] != 1)
                return 0;
            grid[x][y] = currentIslandId;
            int size = 1;
            for (int i = 0; i < 4; i++) {
                int newX = x + dx[i];
                int newY = y + dy[i];
                size += dfs(newX, newY, currentIslandId);
            }
            return size;
        };

        // Iterate through the grid to label and calculate sizes of islands.
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    int size = dfs(i, j, islandId);
                    islandSizes[islandId] = size;
                    maxIslandSize = max(maxIslandSize, size);
                    islandId++;
                }
            }
        }

        // Check if changing a 0 to 1 can connect two islands.
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    unordered_set<int> neighborIslands;
                    int newSize = 1;
                    for (int k = 0; k < 4; k++) {
                        int newX = i + dx[k];
                        int newY = j + dy[k];
                        if (newX >= 0 && newX < m && newY >= 0 && newY < n) {
                            int neighborId = grid[newX][newY];
                            if (neighborId > 1 && neighborIslands.count(neighborId) == 0) {
                                neighborIslands.insert(neighborId);
                                newSize += islandSizes[neighborId];
                            }
                        }
                    }
                    maxIslandSize = max(maxIslandSize, newSize);
                }
            }
        }

        return maxIslandSize;
    }
};