class Solution {
  public:
  
    //Function to return the name of candidate that received maximum votes.
    vector<string> winner(string arr[],int n)
    {
        unordered_map<string, int> voteCount;

        // Count the votes for each candidate
        for (int i = 0; i < n; ++i) {
            voteCount[arr[i]]++;
        }

        // Find the candidate with the maximum votes
        int maxVotes = 0;
        string winner;
        for (auto& entry : voteCount) {
            if (entry.second > maxVotes || (entry.second == maxVotes && entry.first < winner)) {
                maxVotes = entry.second;
                winner = entry.first;
            }
        }

        // Return the result
        return {winner, to_string(maxVotes)};
    }
};