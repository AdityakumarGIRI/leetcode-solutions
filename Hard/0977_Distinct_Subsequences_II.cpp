/*
 * Problem: Distinct Subsequences II
 * Problem ID: 977
 * Difficulty: Hard
 * Language: C++
 * Runtime: 0 ms
 * Memory: 8.9 MB
 * Synced From: LeetCode
 * Date: 2026-09-08
 */

class Solution {
public:
    int distinctSubseqII(string s) {
        const long long MOD = 1e9 + 7;

        long long dp = 1;  // includes empty subsequence

        vector<long long> last(26, 0);

        for (char c : s) {
            int x = c - 'a';

            long long newDp = (2 * dp % MOD - last[x] + MOD) % MOD;

            last[x] = dp;
            dp = newDp;
        }

        // Remove empty subsequence
        return (dp - 1 + MOD) % MOD;
    }
};