class Solution{
public: 
    long long int largestPrimeFactor(int N){
        long long int largestFactor = -1;
        
        // Divide N by 2 as long as it's divisible by 2
        while (N % 2 == 0) {
            largestFactor = 2;
            N /= 2;
        }
        
        // Now check for odd prime factors starting from 3
        for (int i = 3; i * i <= N; i += 2) {
            while (N % i == 0) {
                largestFactor = i;
                N /= i;
            }
        }
        
        // If N is still greater than 2, it's a prime factor itself
        if (N > 2) {
            largestFactor = N;
        }
        
        return largestFactor;
    }
};