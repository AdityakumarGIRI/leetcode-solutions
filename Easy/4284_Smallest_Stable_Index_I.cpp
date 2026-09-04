/*
 * Problem: Smallest Stable Index I
 * Problem ID: 4284
 * Difficulty: Easy
 * Language: C++
 * Runtime: 0 ms
 * Memory: 31.1 MB
 * Synced From: LeetCode
 * Date: 2026-09-04
 */

class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        
        
        vector<int> suffixMin(n);
        suffixMin[n - 1] = nums[n - 1];
        
        for (int i = n - 2; i >= 0; i--) {
            suffixMin[i] = min(nums[i], suffixMin[i + 1]);
        }
        
        int prefixMax = nums[0];
        
        for (int i = 0; i < n; i++) {
            prefixMax = max(prefixMax, nums[i]);
            
            long long instability = 
                (long long)prefixMax - suffixMin[i];
            
            if (instability <= k) {
                return i;
            }
        }
        
        return -1;
        
    }
};