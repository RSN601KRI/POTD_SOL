class Solution {
  public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    int maxMeetings(int n, int start[], int end[]) {
        // Your code here
         std::vector<std::pair<int, int>> meetings;
        
        // Populate the vector with start and end times
        for (int i = 0; i < n; ++i) {
            meetings.push_back({end[i], start[i]});
        }
        
        // Sort meetings based on end times
        std::sort(meetings.begin(), meetings.end());
        
        int count = 0; // To count the maximum number of meetings
        int last_end_time = 0; // To track the end time of the last selected meeting
        
        // Iterate through sorted meetings
        for (const auto& meeting : meetings) {
            if (meeting.second > last_end_time) {
                // If current meeting starts after the last meeting ends, select it
                ++count;
                last_end_time = meeting.first;
            }
        }
        
        return count;
    }
};