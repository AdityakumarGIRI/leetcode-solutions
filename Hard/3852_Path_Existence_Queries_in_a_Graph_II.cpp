/*
 * Problem: Path Existence Queries in a Graph II
 * Problem ID: 3852
 * Difficulty: Hard
 * Language: C++
 * Runtime: 157 ms
 * Memory: 359 MB
 * Synced From: LeetCode
 * Date: 2026-07-10
 */

class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {

        vector<pair<int,int>> a;
        for (int i = 0; i < n; i++)
            a.push_back({nums[i], i});

        sort(a.begin(), a.end());

        vector<int> sortedVal(n), pos(n), comp(n);
        for (int i = 0; i < n; i++) {
            sortedVal[i] = a[i].first;
            pos[a[i].second] = i;
        }

        comp[0] = 0;
        for (int i = 1; i < n; i++) {
            comp[i] = comp[i - 1];
            if (sortedVal[i] - sortedVal[i - 1] > maxDiff)
                comp[i]++;
        }

        vector<int> nxt(n);
        int j = 0;
        for (int i = 0; i < n; i++) {
            if (j < i) j = i;
            while (j + 1 < n && sortedVal[j + 1] - sortedVal[i] <= maxDiff)
                j++;
            nxt[i] = j;
        }

        int LOG = 1;
        while ((1 << LOG) <= n) LOG++;

        vector<vector<int>> up(LOG, vector<int>(n));
        up[0] = nxt;

        for (int k = 1; k < LOG; k++)
            for (int i = 0; i < n; i++)
                up[k][i] = up[k - 1][up[k - 1][i]];

        vector<int> ans;

        for (auto &q : queries) {
            int l = pos[q[0]];
            int r = pos[q[1]];

            if (l == r) {
                ans.push_back(0);
                continue;
            }

            if (l > r) swap(l, r);

            if (comp[l] != comp[r]) {
                ans.push_back(-1);
                continue;
            }

            int cur = l;
            int steps = 0;

            for (int k = LOG - 1; k >= 0; k--) {
                if (up[k][cur] < r) {
                    cur = up[k][cur];
                    steps += 1 << k;
                }
            }

            ans.push_back(steps + 1);
        }

        return ans;
    }
};