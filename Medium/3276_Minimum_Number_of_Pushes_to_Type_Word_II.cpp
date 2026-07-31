/*
 * Problem: Minimum Number of Pushes to Type Word II
 * Problem ID: 3276
 * Difficulty: Medium
 * Language: C++
 * Runtime: 0 ms
 * Memory: 25.3 MB
 * Synced From: LeetCode
 * Date: 2026-07-31
 */

class Solution {
public:
    int minimumPushes(string word) {
        vector<int> freq(26, 0);

        for (char c : word)
            freq[c - 'a']++;

        sort(freq.begin(), freq.end(), greater<int>());

        int ans = 0;

        for (int i = 0; i < 26; i++) {
            if (freq[i] == 0) break;
            ans += freq[i] * (i / 8 + 1);
        }

        return ans;
    }
};