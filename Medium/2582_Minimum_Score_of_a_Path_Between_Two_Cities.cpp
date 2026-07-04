/*
 * Problem: Minimum Score of a Path Between Two Cities
 * Problem ID: 2582
 * Difficulty: Medium
 * Language: C++
 * Runtime: 53 ms
 * Memory: 132.7 MB
 * Synced From: LeetCode
 * Date: 2026-07-04
 */

class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>>adj(n+1);
        for (auto& road:roads){
            int u= road[0];
            int v= road[1];
            int d= road[2];

            adj[u].push_back({v,d});
            adj[v].push_back({u,d});
        }
        queue<int>q;
        vector<bool> visited(n+1,false);
        q.push(1);
        visited[1] = true;
        int ans = INT_MAX;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto &it :adj[node]){
                int next = it.first;
                int dist = it.second;

                ans = min(ans,dist);

                if(!visited[next]){
                    visited[next] =true;
                    q.push(next);
                }
            }
        }
        return ans;


        
    }
};