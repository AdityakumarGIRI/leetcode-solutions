/*
 * Problem: Construct Uniform Parity Array II
 * Problem ID: 4258
 * Difficulty: Medium
 * Language: C++
 * Runtime: 0 ms
 * Memory: 165.8 MB
 * Synced From: LeetCode
 * Date: 2026-09-03
 */

class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int mn = *min_element(nums1.begin(), nums1.end());

        
        if (mn % 2 == 1) {
            return true;
        }

       
        for (int x : nums1) {
            if (x % 2 != 0) return false;
        }

        return true;
    }
};