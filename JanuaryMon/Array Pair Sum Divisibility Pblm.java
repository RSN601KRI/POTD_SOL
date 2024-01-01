package JanuaryMon;

#include<vector>#include<unordered_map>

class Solution {
public:
    bool canPair(std::vector<int> nums, int k) {
        if (nums.size() % 2 != 0) {
            // If the number of elements is odd, it's not possible to form pairs.
            return false;
        }

        // Create a hash map to store remainders and their frequencies.
        std::unordered_map<int, int> remainderCount;

        // Count the remainders when dividing each element by k.
        for (int num : nums) {
            int remainder = (num % k + k) % k; // Ensure remainder is non-negative.
            remainderCount[remainder]++;
        }

        // Check if each remainder can be paired with another remainder to sum up to a multiple of k.
        for (int i = 0; i < nums.size(); i++) {
            int remainder = (nums[i] % k + k) % k; // Ensure remainder is non-negative.

            // Check if the current remainder can be paired with another remainder.
            if (remainderCount[remainder] > 0) {
                int targetRemainder = (k - remainder) % k;
                if (remainder == targetRemainder) {
                    // If the remainder is 0, it should have an even count.
                    if (remainderCount[remainder] % 2 != 0) {
                        return false;
                    }
                } else {
                    // Check if the target remainder is present and has the same count.
                    if (remainderCount[targetRemainder] != remainderCount[remainder]) {
                        return false;
                    }
                }

                // Reduce the count of both remainders.
                remainderCount[remainder] = 0;
                remainderCount[targetRemainder] = 0;
            }
        }

        return true;
    }
};

int main() {
    Solution solution;

    // Example 1
    std::vector<int> nums1 = {9, 5, 7, 3};
    int k1 = 6;
    bool result1 = solution.canPair(nums1, k1);
    std::cout << "Output 1: " << (result1 ? "True" : "False") << std::endl;

    // Example 2
    std::vector<int> nums2 = {4, 4, 4};
    int k2 = 4;
    bool result2 = solution.canPair(nums2, k2);
    std::cout << "Output 2: " << (result2 ? "True" : "False") << std::endl;

    return 0;
}
