#include <unordered_set>

class Solution {
public:
    int nextHappy(int N) {
        while (true) {
            N++;
            if (isHappy(N))
                return N;
        }
    }

private:
    bool isHappy(int num) {
        std::unordered_set<int> visited;

        while (num != 1) {
            int current = num;
            int sum = 0;

            while (current != 0) {
                int digit = current % 10;
                sum += digit * digit;
                current /= 10;
            }

            if (visited.find(sum) != visited.end())
                return false;

            visited.insert(sum);
            num = sum;
        }

        return true;
    }
};