class Solution{
    public:
    bool isMaxHeap(int arr[], int n)
    {
        // Your code goes here
        int j = 1;
        for(int i=0;i<n;i++){
            if(j<n and arr[j]>arr[i])return false;
            if(j+1<n and arr[j+1]>arr[i])return false;
            j+=2;
        }
        return true;
    }
};