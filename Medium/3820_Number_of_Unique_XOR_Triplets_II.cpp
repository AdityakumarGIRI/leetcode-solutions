/*
 * Problem: Number of Unique XOR Triplets II
 * Problem ID: 3820
 * Difficulty: Medium
 * Language: C++
 * Runtime: 1036 ms
 * Memory: 106.8 MB
 * Synced From: LeetCode
 * Date: 2026-07-24
 */

class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        const int MAXX = 2048;

        vector<bool> dp1(MAXX, false);
        vector<bool> dp2(MAXX, false);
        vector<bool> dp3(MAXX, false);

        for (int v : nums) {
            dp1[v] = true;

            vector<bool> cur1 = dp1;
            for (int x = 0; x < MAXX; x++) {
                if (cur1[x])
                    dp2[x ^ v] = true;
            }

            vector<bool> cur2 = dp2;
            for (int x = 0; x < MAXX; x++) {
                if (cur2[x])
                    dp3[x ^ v] = true;
            }
        }

        int ans = 0;
        for (bool b : dp3)
            ans += b;

        return ans;
    }
};