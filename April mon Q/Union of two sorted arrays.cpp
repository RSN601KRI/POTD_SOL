class Solution{
    public:
    //arr1,arr2 : the arrays
    // n, m: size of arrays
    //Function to return a list containing the union of the two arrays. 
    vector<int> findUnion(int arr1[], int arr2[], int n, int m)
    {
        //Your code here
        //return vector with correct order of elements
        // Create a set to store unique elements
        std::set<int> unionSet;

        // Insert elements of arr1 into the set
        for (int i = 0; i < n; ++i) {
            unionSet.insert(arr1[i]);
        }

        // Insert elements of arr2 into the set
        for (int i = 0; i < m; ++i) {
            unionSet.insert(arr2[i]);
        }

        // Convert set to vector
        std::vector<int> result(unionSet.begin(), unionSet.end());

        // Return the vector
        return result;
    