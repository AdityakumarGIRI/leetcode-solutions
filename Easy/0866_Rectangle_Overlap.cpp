/*
 * Problem: Rectangle Overlap
 * Problem ID: 866
 * Difficulty: Easy
 * Language: C++
 * Runtime: 0 ms
 * Memory: 9.7 MB
 * Synced From: LeetCode
 * Date: 2026-09-14
 */

class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        // rec1 is completely to the left of rec2
        if (rec1[2] <= rec2[0])
            return false;

        // rec2 is completely to the left of rec1
        if (rec2[2] <= rec1[0])
            return false;

        // rec1 is completely below rec2
        if (rec1[3] <= rec2[1])
            return false;

        // rec2 is completely below rec1
        if (rec2[3] <= rec1[1])
            return false;

        return true;
    }
};