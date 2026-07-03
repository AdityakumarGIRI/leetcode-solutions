/*
 * Problem: Network Recovery Pathways
 * Problem ID: 3919
 * Difficulty: Hard
 * Language: C++
 * Runtime: 150 ms
 * Memory: 314.9 MB
 * Synced From: LeetCode
 * Date: 2026-07-03
 */

class Solution {
public:
    long long INF = (1LL << 62);

    int findMaxPathScore(vector<vector<int>>& edges,
                         vector<bool>& online,
                         long long k) {

        int n = online.size();

        vector<vector<pair<int,int>>> adj(n);
        vector<int> indeg(n, 0);
        vector<int> vals;

        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];
            int c = e[2];

            adj[u].push_back({v, c});
            indeg[v]++;
            vals.push_back(c);
        }


        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (indeg[i] == 0) q.push(i);
        }

        vector<int> topo;

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            topo.push_back(u);

            for (auto &[v, c] : adj[u]) {
                indeg[v]--;
                if (indeg[v] == 0) q.push(v);
            }
        }

        sort(vals.begin(), vals.end());
        vals.erase(unique(vals.begin(), vals.end()), vals.end());

        auto possible = [&](int minEdge) {
            vector<long long> dist(n, INF);
            dist[0] = 0;

            for (int u : topo) {
                if (dist[u] == INF) continue;

                if (u != 0 && u != n - 1 && !online[u]) continue;

                for (auto &[v, cost] : adj[u]) {
                    if (cost < minEdge) continue;

                    if (v != n - 1 && !online[v]) continue;

                    dist[v] = min(dist[v], dist[u] + (long long)cost);
                }
            }

            return dist[n - 1] <= k;
        };

        int left = 0;
        int right = vals.size() - 1;
        int answer = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (possible(vals[mid])) {
                answer = vals[mid];
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return answer;
    }
};