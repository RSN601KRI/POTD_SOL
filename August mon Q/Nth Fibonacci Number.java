
//User function Template for Java
class Solution {
    static int nthFibonacci(int n){
        int MOD = 1000000007;
        if (n <= 1) {
            return n;
        }
        
        int a = 0, b = 1, c = 0;
        for (int i = 2; i <= n; i++) {
            c = (a + b) % MOD;
            a = b;
            b = c;
        }
        return c;
    }

    public static void main(String[] args) {
        int n = 2;
        Solution sol = new Solution();
        System.out.println(sol.nthFibonacci(n)); // Output: 1
    }
}