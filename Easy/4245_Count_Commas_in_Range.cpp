/*
 * Problem: Count Commas in Range
 * Problem ID: 4245
 * Difficulty: Easy
 * Language: C++
 * Runtime: 6 ms
 * Memory: 8.5 MB
 * Synced From: LeetCode
 * Date: 2026-09-08
 */

class Solution {
public:
    int countCommas(int n) {
        int ans = 0;

        for (int i = 1; i <= n; i++) {
            int x = i;

            while (x >= 1000) {
                ans++;
                x /= 1000;
            }
        }

        return ans;
    }
};