/*
 * Problem: Number of Substrings Containing All Three Characters
 * Problem ID: 1460
 * Difficulty: Medium
 * Language: C++
 * Runtime: 7 ms
 * Memory: 11 MB
 * Synced From: LeetCode
 * Date: 2026-07-01
 */

class Solution {
public:
    int numberOfSubstrings(string s) {
        int cnt[3] = {0};
        int left = 0, ans = 0;
        int n = s.size();

        for (int right = 0; right < n; right++) {
            cnt[s[right] - 'a']++;

            while (cnt[0] > 0 && cnt[1] > 0 && cnt[2] > 0) {
                ans += n - right;
                cnt[s[left] - 'a']--;
                left++;
            }
        }

        return ans;
    }
};