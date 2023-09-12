class Solution {
  public:
    int isPerfectNumber(long long N) {
        if (N <= 1) {
            return 0; // Perfect numbers are positive integers greater than 1
        }

        long long sum_of_factors = 1; // 1 is always a factor of any number

        for (long long i = 2; i * i <= N; i++) {
            if (N % i == 0) {
                sum_of_factors += i;
                if (i != N / i) {
                    sum_of_factors += N / i;
                }
            }
        }

        return sum_of_factors == N ? 1 : 0;
    }
};