/*
 * Problem: Concatenate Non-Zero Digits and Multiply by Sum II
 * Problem ID: 4136
 * Difficulty: Medium
 * Language: C++
 * Runtime: 34 ms
 * Memory: 165.9 MB
 * Synced From: LeetCode
 * Date: 2026-07-08
 */

class Solution {
public:
    static const int MOD = 1000000007;

    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.size();

        vector<int> cnt(n + 1, 0);
        vector<int> digits;

        for (int i = 0; i < n; i++) {
            cnt[i + 1] = cnt[i];
            if (s[i] != '0') {
                cnt[i + 1]++;
                digits.push_back(s[i] - '0');
            }
        }

        int m = digits.size();

        vector<long long> pow10(m + 1, 1);
        for (int i = 1; i <= m; i++)
            pow10[i] = (pow10[i - 1] * 10) % MOD;

        vector<long long> prefVal(m + 1, 0);
        vector<long long> prefSum(m + 1, 0);

        for (int i = 0; i < m; i++) {
            prefVal[i + 1] = (prefVal[i] * 10 + digits[i]) % MOD;
            prefSum[i + 1] = prefSum[i] + digits[i];
        }

        vector<int> ans;

        for (auto &q : queries) {
            int l = q[0], r = q[1];

            int L = cnt[l];
            int R = cnt[r + 1] - 1;

            if (L > R) {
                ans.push_back(0);
                continue;
            }

            int len = R - L + 1;

            long long x = (prefVal[R + 1] -
                           prefVal[L] * pow10[len] % MOD + MOD) % MOD;

            long long sum = prefSum[R + 1] - prefSum[L];

            ans.push_back((x * (sum % MOD)) % MOD);
        }

        return ans;
    }
};