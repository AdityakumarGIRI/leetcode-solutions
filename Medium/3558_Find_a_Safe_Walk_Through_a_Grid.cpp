/*
 * Problem: Find a Safe Walk Through a Grid
 * Problem ID: 3558
 * Difficulty: Medium
 * Language: C++
 * Runtime: 12 ms
 * Memory: 30.6 MB
 * Synced From: LeetCode
 * Date: 2026-07-02
 */

class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {

        int n = grid.size();
        int m = grid[0].size();

        vector<int> d = {0,1,0,-1,0};
        vector<vector<int>> cost(n, vector<int>(m, INT_MIN));

        cost[0][0] = health - grid[0][0];

        priority_queue<pair<int,pair<int,int>>> pq;
        pq.push({cost[0][0], {0,0}});

        while(!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            int curHealth = it.first;
            int x = it.second.first;
            int y = it.second.second;
            if(curHealth < 1)
                break;
            if(x == n-1 && y == m-1)
                return true;
            for(int k=0;k<4;k++) {
                int nx = x + d[k];
                int ny = y + d[k+1];
                if(nx>=0 && nx<n && ny>=0 && ny<m) {

                    int newHealth = curHealth - grid[nx][ny];                   
                    if(newHealth > cost[nx][ny]) {
                        cost[nx][ny] = newHealth;
                        pq.push({newHealth, {nx,ny}});
                    }
                }
            }
        }

        return false;
    }
};