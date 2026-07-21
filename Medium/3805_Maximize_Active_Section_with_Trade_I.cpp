/*
 * Problem: Maximize Active Section with Trade I
 * Problem ID: 3805
 * Difficulty: Medium
 * Language: C++
 * Runtime: 122 ms
 * Memory: 105.2 MB
 * Synced From: LeetCode
 * Date: 2026-07-21
 */

class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int activeCount = 0;
        for(char c : s)
            if(c == '1') activeCount++;

        // Augment with 1's
        s = "1" + s + "1";

        int n = s.size();
        vector<int> inactiveBlocks;

        int i = 0;
        while(i < n) {
            if(s[i] == '0') {
                int start = i;
                while(i < n && s[i] == '0')
                    i++;
                inactiveBlocks.push_back(i - start);
            } else {
                i++;
            }
        }

        int maxPairSum = 0;
        for(int i = 1; i < inactiveBlocks.size(); i++) {
            maxPairSum = max(maxPairSum,
                             inactiveBlocks[i] + inactiveBlocks[i - 1]);
        }

        return activeCount + maxPairSum;
    }
};