/*
 * Problem: Number of Sets of K Non-Overlapping Line Segments
 * Problem ID: 1725
 * Difficulty: Medium
 * Language: C++
 * Runtime: 2 ms
 * Memory: 7.8 MB
 * Synced From: LeetCode
 * Date: 2026-09-16
 */

class Solution {
public:
    static const long long MOD = 1e9 + 7;

    long long power(long long a, long long b) {
        long long res = 1;

        while (b) {
            if (b & 1)
                res = res * a % MOD;

            a = a * a % MOD;
            b >>= 1;
        }

        return res;
    }

    int numberOfSets(int n, int k) {
        int N = n + k - 1;
        int R = 2 * k;

        long long num = 1;
        long long den = 1;

        for (int i = 1; i <= R; i++) {
            num = num * (N - R + i) % MOD;
            den = den * i % MOD;
        }

        // Modular inverse using Fermat's theorem
        return num * power(den, MOD - 2) % MOD;
    }
};