class Solution{   
public:
    //Function to partition the array around the range such 
    //that array is divided into three parts.
    void threeWayPartition(vector<int>& array,int a, int b)
    {
        // code here 
        int n = array.size();
        int start = 0, end = n - 1;
        
        // Traverse the array and move elements less than 'a' to the beginning.
        for (int i = 0; i <= end;) {
            if (array[i] < a) {
                swap(array[i], array[start]);
                start++;
                i++;
            } else if (array[i] > b) {
                swap(array[i], array[end]);
                end--;
            } else {
                i++;
            }
        }
    }