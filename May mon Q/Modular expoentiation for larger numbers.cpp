class Solution
{
	public:
		long long int PowMod(long long int x,long long int n,long long int M)
		{
		    // Code here
		    if (M == 1) return 0; // Modulo 1 will always be 0

            long long int result = 1;  // Initialize result
            x = x % M;  // Update x if it is more than or equal to M

            while (n > 0)
            {
                // If n is odd, multiply x with result
                if (n % 2 == 1)
                    result = (result * x) % M;

                // n must be even now
                n = n >> 1;  // n = n/2
                x = (x * x) % M;  // Change x to x^2
            }
            return result;
		}
};