/*
 * Title : Count Good Numbers
 * Problem Link : https://leetcode.com/problems/count-good-numbers/
 * Submission Link : https://leetcode.com/problems/count-good-numbers/submissions/1047004541/
 */

class Solution {
public:
    const long long MOD = 1e9+7;
    
    int countGoodNumbers(long long n) {
        unordered_map<long long, long long> dp;
        long long ans = power20(n/2LL, dp);

        if (n & 1LL) {
            ans = ((ans%MOD) * 5LL)%MOD;
        }

        return (int)ans%MOD;
    }

    long long power20(long long n, unordered_map<long long, long long> &dp) {
        if(dp[n]!=0LL) {
            return dp[n];
        }

        if (n == 0LL) {
            return (dp[0LL] = 1LL);
        }
        if (n == 1LL) {
            return (dp[1LL] = 20LL);
        }

        long long ans = 1LL, comp = 1LL;
        while (comp) {
            if (n & comp) {
                ans = ((ans%MOD) * 20LL)%MOD;
                ans = ((ans%MOD) * (power20(comp - 1, dp)%MOD))%MOD;
            }
            comp = comp << 1;
        }

        return (dp[n] = (ans%MOD));
    }
};
