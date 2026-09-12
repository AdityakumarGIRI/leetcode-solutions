/*
 * Problem: Maximum Score of Non-overlapping Intervals
 * Problem ID: 3562
 * Difficulty: Hard
 * Language: C++
 * Runtime: 932 ms
 * Memory: 349.3 MB
 * Synced From: LeetCode
 * Date: 2026-09-12
 */

class Solution {
public:
    
    struct Node {
        long long score;
        vector<int> idx;
    };
    
    bool better(Node a, Node b) {
        if (a.score != b.score)
            return a.score > b.score;
        
        return a.idx < b.idx;
    }
    
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        
        int n = intervals.size();
        
        // {left, right, weight, original index}
        vector<array<long long, 4>> a;
        
        for (int i = 0; i < n; i++) {
            a.push_back({
                intervals[i][0],
                intervals[i][1],
                intervals[i][2],
                i
            });
        }
        
        // Sort according to ending point
        sort(a.begin(), a.end(), [](auto &x, auto &y) {
            return x[1] < y[1];
        });
        
        // Store ending points
        vector<long long> end(n + 1);
        
        for (int i = 1; i <= n; i++) {
            end[i] = a[i - 1][1];
        }
        
        // p[i] = last interval compatible with i
        vector<int> p(n + 1);
        
        for (int i = 1; i <= n; i++) {
            
            long long left = a[i - 1][0];
            
            // Need end[j] < left
            int pos = lower_bound(
                end.begin() + 1,
                end.begin() + i,
                left
            ) - end.begin();
            
            p[i] = pos - 1;
        }
        
        // dp[i][k] = best answer using first i intervals
        // and choosing exactly k intervals
        vector<vector<Node>> dp(
            n + 1,
            vector<Node>(5, {LLONG_MIN, {}})
        );
        
        // Choosing 0 intervals
        for (int i = 0; i <= n; i++) {
            dp[i][0] = {0, {}};
        }
        
        // DP
        for (int i = 1; i <= n; i++) {
            
            for (int k = 1; k <= 4; k++) {
                
                // Don't choose current interval
                dp[i][k] = dp[i - 1][k];
                
                // Choose current interval
                if (dp[p[i]][k - 1].score != LLONG_MIN) {
                    
                    Node take = dp[p[i]][k - 1];
                    
                    take.score += a[i - 1][2];
                    
                    take.idx.push_back(a[i - 1][3]);
                    
                    sort(take.idx.begin(), take.idx.end());
                    
                    if (better(take, dp[i][k])) {
                        dp[i][k] = take;
                    }
                }
            }
        }
        
        // We can choose AT MOST 4 intervals
        Node ans = {0, {}};
        
        for (int k = 1; k <= 4; k++) {
            if (better(dp[n][k], ans)) {
                ans = dp[n][k];
            }
        }
        
        return ans.idx;
    }
};