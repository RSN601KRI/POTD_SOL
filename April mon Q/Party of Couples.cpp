class Solution{
    public:
    int findSingle(int n, int arr[]){
        // code here
        int result = 0;
        for (int i = 0; i < n; ++i) {
            result ^= arr[i];
        }
        return result;
    }
};