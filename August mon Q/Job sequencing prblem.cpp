/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code here
        sort(arr, arr + n, [](Job a, Job b) {
            return a.profit > b.profit;
        });
        
        // Step 2: Initialize variables
        int maxDeadline = 0;
        for (int i = 0; i < n; i++) {
            maxDeadline = max(maxDeadline, arr[i].dead);
        }
        
        // Step 3: Initialize the slot availability array
        vector<bool> slot(maxDeadline + 1, false);
        
        int jobCount = 0;
        int totalProfit = 0;
        
        // Step 4: Iterate through all jobs
        for (int i = 0; i < n; i++) {
            // Find a free slot for this job (starting from the last possible slot)
            for (int j = arr[i].dead; j > 0; j--) {
                if (!slot[j]) {
                    slot[j] = true;
                    jobCount++;
                    totalProfit += arr[i].profit;
                    break;
                }
            }
        }
        
        // Step 5: Return the result as a vector
        return {jobCount, totalProfit};
    } 
};