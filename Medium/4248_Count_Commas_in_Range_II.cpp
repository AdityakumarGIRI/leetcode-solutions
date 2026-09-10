/*
 * Problem: Count Commas in Range II
 * Problem ID: 4248
 * Difficulty: Medium
 * Language: C++
 * Runtime: 0 ms
 * Memory: 9 MB
 * Synced From: LeetCode
 * Date: 2026-09-10
 */

class Solution {
public:
    long long countCommas(long long n) {
        long long ans = 0;

    
        long long start = 1000;


        for (int k = 1; start <= n; k++) {
            long long end = min(n, start * 1000 - 1);

            ans += (end - start + 1) * k;

            start *= 1000;
        }

        return ans;
    }
};