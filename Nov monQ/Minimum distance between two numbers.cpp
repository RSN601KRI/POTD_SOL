class Solution{
  public:
    int minDist(int a[], int n, int x, int y) {
        int posX = -1;  // Last position of element x
        int posY = -1;  // Last position of element y
        int minDistance = INT_MAX;  // Initialize minDistance to a large value

        for (int i = 0; i < n; i++) {
            if (a[i] == x) {
                // Update the last position of x
                posX = i;
                // If y is found before x, update the minDistance
                if (posY != -1)
                    minDistance = min(minDistance, abs(posX - posY));
            } else if (a[i] == y) {
                // Update the last position of y
                posY = i;
                // If x is found before y, update the minDistance
                if (posX != -1)
                    minDistance = min(minDistance, abs(posY - posX));
            }
        }

        if (posX == -1 || posY == -1) {
            // If either x or y is not found in the array
            return -1;
        }

        return minDistance;
    }
};
