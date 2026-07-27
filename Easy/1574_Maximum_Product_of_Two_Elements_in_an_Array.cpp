/*
 * Problem: Maximum Product of Two Elements in an Array
 * Problem ID: 1574
 * Difficulty: Easy
 * Language: C++
 * Runtime: 0 ms
 * Memory: 13.4 MB
 * Synced From: LeetCode
 * Date: 2026-07-27
 */

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max1 = 0, max2 = 0;

        for (int num : nums) {
            if (num > max1) {
                max2 = max1;
                max1 = num;
            } else if (num > max2) {
                max2 = num;
            }
        }

        return (max1 - 1) * (max2 - 1);
    }
};