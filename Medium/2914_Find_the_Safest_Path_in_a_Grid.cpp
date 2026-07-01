/*
 * Problem: Find the Safest Path in a Grid
 * Problem ID: 2914
 * Difficulty: Medium
 * Language: C++
 * Runtime: 324 ms
 * Memory: 147.3 MB
 * Synced From: LeetCode
 * Date: 2026-07-01
 */

class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {

        int n = grid.size();

        vector<vector<int>> arr(n, vector<int>(n, INT_MAX));
        vector<vector<int>> vis(n, vector<int>(n, -1));

        queue<pair<int,int>> q;

    
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                {
                    arr[i][j]=0;
                    vis[i][j]=1;
                    q.push({i,j});
                }
            }
        }

        vector<int> da = {0,0,-1,1};
        vector<int> db = {1,-1,0,0};
        while(!q.empty())
        {
            auto it = q.front();
            q.pop();

            for(int t=0;t<4;t++)
            {
                int ni = it.first + da[t];
                int nj = it.second + db[t];
                if(ni>=0 && nj>=0 && ni<n && nj<n &&
                   vis[ni][nj]==-1)
                {
                    vis[ni][nj]=1;
                    arr[ni][nj]=arr[it.first][it.second]+1;
                    q.push({ni,nj});
                }
            }
        }

        priority_queue<pair<int,pair<int,int>>> pq;
        vector<vector<int>> dist(n, vector<int>(n,-1));
        dist[0][0] = arr[0][0];
        pq.push({arr[0][0], {0,0}});
        while(!pq.empty())
        {
            auto cur = pq.top();
            pq.pop();
            int safe = cur.first;
            int x = cur.second.first;
            int y = cur.second.second;
            if(x==n-1 && y==n-1)
                return safe;
            for(int t=0;t<4;t++)
            {
                int nx = x + da[t];
                int ny = y + db[t];
                if(nx>=0 && ny>=0 && nx<n && ny<n)
                {
                    int newSafe = min(safe, arr[nx][ny]);

                    if(newSafe > dist[nx][ny])
                    {
                        dist[nx][ny] = newSafe;
                        pq.push({newSafe,{nx,ny}});
                    }
                }
            }
        }

        return 0;
    }
};