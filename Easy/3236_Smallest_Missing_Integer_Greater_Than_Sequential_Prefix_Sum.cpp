/*
 * Problem: Smallest Missing Integer Greater Than Sequential Prefix Sum
 * Problem ID: 3236
 * Difficulty: Easy
 * Language: C++
 * Runtime: 0 ms
 * Memory: 22.8 MB
 * Synced From: LeetCode
 * Date: 2026-08-11
 */

class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int sum = nums[0];

        // Find longest sequential prefix
        int i = 1;
        while (i < nums.size() && nums[i] == nums[i - 1] + 1) {
            sum += nums[i];
            i++;
        }

        unordered_set<int> st(nums.begin(), nums.end());

        // Find smallest missing integer >= sum
        while (st.count(sum))
            sum++;

        return sum;
    }
};