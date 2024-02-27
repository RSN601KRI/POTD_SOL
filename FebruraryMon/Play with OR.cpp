int* game_with_number(int arr[], int n)
{
    
    // Complete the function
    int *result = new int[n]; // Allocate memory for the result array
    
    for (int i = 0; i < n - 1; i++) {
        // Perform bitwise OR operation between consecutive elements
        result[i] = arr[i] | arr[i + 1];
    }
    result[n - 1] = arr[n - 1]; // Last element remains the same
    
    return result;
    
}
