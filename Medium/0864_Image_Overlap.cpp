/*
 * Problem: Image Overlap
 * Problem ID: 864
 * Difficulty: Medium
 * Language: C++
 * Runtime: 64 ms
 * Memory: 12.8 MB
 * Synced From: LeetCode
 * Date: 2026-09-13
 */

class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, 
                       vector<vector<int>>& img2) {
        
        int n = img1.size();
        int ans = 0;

        // Try every possible row shift
        for (int dx = -(n - 1); dx <= n - 1; dx++) {
            
            // Try every possible column shift
            for (int dy = -(n - 1); dy <= n - 1; dy++) {
                
                int overlap = 0;

                // Check every cell of img1
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < n; j++) {
                        
                        if (img1[i][j] == 1) {
                            
                            int ni = i + dx;
                            int nj = j + dy;

                            // Check if translated position is inside matrix
                            if (ni >= 0 && ni < n &&
                                nj >= 0 && nj < n) {
                                
                                if (img2[ni][nj] == 1) {
                                    overlap++;
                                }
                            }
                        }
                    }
                }

                ans = max(ans, overlap);
            }
        }

        return ans;
    }
};