
class Solution {
  public:
    int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y) {
        if (A[0][0] == 0 || A[X][Y] == 0) {
            return -1; // Impossible to reach (X, Y)
        }

        vector<vector<int>> visited(N, vector<int>(M, 0));
        queue<pair<int, int>> q;
        q.push({0, 0});
        visited[0][0] = 1;

        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        int steps = 0;

        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();

                if (x == X && y == Y) {
                    return steps;
                }

                for (auto dir : directions) {
                    int newX = x + dir.first;
                    int newY = y + dir.second;
                    if (newX >= 0 && newX < N && newY >= 0 && newY < M && A[newX][newY] == 1 && !visited[newX][newY]) {
                        q.push({newX, newY});
                        visited[newX][newY] = 1;
                    }
                }
            }
            steps++;
        }

        return -1; // If (X, Y) is not reachable
    }
};
