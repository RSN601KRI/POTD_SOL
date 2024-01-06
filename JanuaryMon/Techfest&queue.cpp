class Solution {
    public:
        int sumOfPowers(int a, int b){
            // Function to calculate prime factorization and sum of powers of primes
            auto primeFactorization = [](int num) {
                std::unordered_map<int, int> factors;
                for (int i = 2; i * i <= num; ++i) {
                    while (num % i == 0) {
                        factors[i]++;
                        num /= i;
                    }
                }
                if (num > 1) {
                    factors[num]++;
                }
                return factors;
            };
    
            // Function to calculate the sum of powers of primes in the given range
            auto sumOfPowersInRange = [&](int start, int end) {
                int sum = 0;
                for (int i = start; i <= end; ++i) {
                    auto factors = primeFactorization(i);
                    for (const auto& factor : factors) {
                        sum += factor.second;
                    }
                }
                return sum;
            };
    
            // Calculate the sum of powers of primes in the specified range [a, b]
            int result = sumOfPowersInRange(a, b);
            return result;
        }
    };
    