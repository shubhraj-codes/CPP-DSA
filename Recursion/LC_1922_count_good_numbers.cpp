class Solution {
public:
    long long power(long long x, long long n)
    {
        long long MOD = 1000000007;
        if(n == 0) return 1;

        long long ans = power(x,n/2);

        ans = (ans * ans) % MOD;

        if(n % 2 == 1) ans = (ans * x) % MOD;

        return ans;
    }
    int countGoodNumbers(long long n) {
        long long MOD = 1000000007;

        long long even = (n+1)/2;
        long long odd = n/2;

        return (power(5, even) * power(4,odd)) % MOD; 
    }
};
