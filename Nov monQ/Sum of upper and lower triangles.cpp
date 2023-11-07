class Solution
{   
    public:
    //Function to return sum of upper and lower triangles of a matrix.
    vector<int> sumTriangles(const vector<vector<int> >& matrix, int n)
    {
        int upperSum = 0, lowerSum = 0;
        
        // Calculate the sum of the upper triangle
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                upperSum += matrix[i][j];
            }
        }
        
        // Calculate the sum of the lower triangle
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= i; j++) {
                lowerSum += matrix[i][j];
            }
        }
        
        return {upperSum, lowerSum};
    }
};