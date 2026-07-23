/*
 * Problem: Number of Unique XOR Triplets I
 * Problem ID: 3824
 * Difficulty: Medium
 * Language: C++
 * Runtime: 0 ms
 * Memory: 199 MB
 * Synced From: LeetCode
 * Date: 2026-07-23
 */

class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        if(n==1||n==2)
            return n;

        int ans = 1;
        while(ans<=n){
            ans*=2;
        }
        return ans;
    }
};