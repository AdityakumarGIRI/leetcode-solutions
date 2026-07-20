/*
 * Problem: Shift 2D Grid
 * Problem ID: 1386
 * Difficulty: Easy
 * Language: C++
 * Runtime: 0 ms
 * Memory: 18.1 MB
 * Synced From: LeetCode
 * Date: 2026-07-20
 */

class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        int total = n*m;
        k%=total;

        vector<vector<int>>ans(n,vector<int>(m));

        for(int i =0;i<n;i++){
            for(int j=0 ;j<m ; j++ ){
                int oldindex = i*m +j;
                int newindex = (oldindex + k )% total;

                int newRow = newindex / m;
                int newCol = newindex % m;
                ans[newRow][newCol] = grid[i][j];
            }
        }
        return ans;

        
    }
};