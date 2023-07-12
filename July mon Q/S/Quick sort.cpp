class Solution
{
    public:
    
    void quickSort(int arr[], int low, int high)
    {
        
        if (low < high) 
        {
            int pIndex = partition(arr, low, high);
            quickSort(arr, low, pIndex - 1);
            quickSort(arr, pIndex + 1, high);
        }
    }
    
    public:
    int partition (int arr[], int low, int high)
    {
        int pivot = arr[low];
        int i = low;
        int j = high;
    
        while (i < j) 
        {
            while (arr[i] <= pivot && i <= high - 1) 
            {
                i++;
            }
    
            while (arr[j] > pivot && j >= low + 1) 
            {
                j--;
            }
            
            if (i < j) 
                swap(arr[i], arr[j]);
        }
        swap(arr[low], arr[j]);
        return j;
    }
};