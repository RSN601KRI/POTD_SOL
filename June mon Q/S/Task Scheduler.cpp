class Solution {
  public:
    int leastInterval(int N, int K, vector<char> &tasks) {
        
         vector<int> frequency(26, 0);  
    
        for (char task : tasks)
            frequency[task - 'A']++;
    
        int maxFreq = 0;
        for (int freq : frequency)
            maxFreq = max(maxFreq, freq);
    
        int maxFreqCount = 0;
        for (int freq : frequency) {
            if (freq == maxFreq)
                maxFreqCount++;
        }
        
        int intervalsForMaxFreqTasks = (maxFreq - 1) * (K + 1) + maxFreqCount;
    
        int minimumIntervals = max(int(tasks.size()), intervalsForMaxFreqTasks);
    
        return minimumIntervals;
    }
};