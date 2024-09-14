class Solution {
  public:

    void rearrange(vector<int> &arr) {
        // code here
        std::vector<int> pos, neg;
        
        // Separate positive and negative numbers
        for (int num : arr) {
            if (num >= 0) {
                pos.push_back(num);
            } else {
                neg.push_back(num);
            }
        }

        int i = 0, j = 0, k = 0;
        
        // Start interleaving positive and negative numbers
        while (i < pos.size() && j < neg.size()) {
            arr[k++] = pos[i++];
            arr[k++] = neg[j++];
        }
        
        // Append remaining positive numbers, if any
        while (i < pos.size()) {
            arr[k++] = pos[i++];
        }

        // Append remaining negative numbers, if any
        while (j < neg.size()) {
            arr[k++] = neg[j++];
        }
    }
};