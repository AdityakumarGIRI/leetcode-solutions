/*
 * Problem: Remove Covered Intervals
 * Problem ID: 1222
 * Difficulty: Medium
 * Language: C++
 * Runtime: 2 ms
 * Memory: 15.1 MB
 * Synced From: LeetCode
 * Date: 2026-07-07
 */

class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(),[](const vector<int>& a, const vector<int>& b){
            if(a[0]==b[0]){
                return a[1]>b[1];

            }
            return a[0]<b[0];
            
        });
        int ans=1;
        int maxend = intervals[0][1];
        for(int i =0 ; i < intervals.size();i++){
            if(intervals[i][1]<=maxend){
                continue;

            }
            ans++;
            maxend = intervals[i][1];
        }
        return ans;
    }
};