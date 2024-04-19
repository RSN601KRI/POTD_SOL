class Solution{
	
	
	public:
	vector<int> findMissing(int a[], int b[], int n, int m) 
	{ 
	    // Your code goes here
	    vector<int> result;
        unordered_set<int> bSet;

        // Store all elements of array b in a hash set
        for (int i = 0; i < m; ++i) {
            bSet.insert(b[i]);
        }

        // Iterate through array a and check if each element exists in the hash set
        for (int i = 0; i < n; ++i) {
            if (bSet.find(a[i]) == bSet.end()) {
                result.push_back(a[i]);
            }
        }

        return result;
	} 
};