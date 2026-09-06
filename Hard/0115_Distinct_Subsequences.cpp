/*
 * Problem: Distinct Subsequences
 * Problem ID: 115
 * Difficulty: Hard
 * Language: C++
 * Runtime: 7 ms
 * Memory: 8.9 MB
 * Synced From: LeetCode
 * Date: 2026-09-06
 */

class Solution {
public:
    int numDistinct(string s, string t) {

        int m = t.length();

        vector<long long> dp(m + 1, 0);


        dp[0] = 1;

        for (char c : s) {

           
            for (int j = m; j >= 1; j--) {

                if (c == t[j - 1]) {

                    if (dp[j - 1] > INT_MAX - dp[j]) {
                        dp[j] = INT_MAX;
                    } 
                    else {
                        dp[j] += dp[j - 1];
                    }
                }
            }
        }

        return dp[m];
    }
};