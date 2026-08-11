/*
 * Problem: Stone Game III
 * Problem ID: 1522
 * Difficulty: Hard
 * Language: C++
 * Runtime: 18 ms
 * Memory: 146.4 MB
 * Synced From: LeetCode
 * Date: 2026-08-11
 */

class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();

        vector<int> dp(n + 1, 0);

        for (int i = n - 1; i >= 0; i--) {
            int take = 0;
            dp[i] = INT_MIN;

            for (int k = 0; k < 3 && i + k < n; k++) {
                take += stoneValue[i + k];
                dp[i] = max(dp[i], take - dp[i + k + 1]);
            }
        }

        if (dp[0] > 0) return "Alice";
        if (dp[0] < 0) return "Bob";
        return "Tie";
    }
};