/*
 * Problem: Minimum Moves to Clean the Classroom
 * Problem ID: 3870
 * Difficulty: Medium
 * Language: C++
 * Runtime: 242 ms
 * Memory: 153.1 MB
 * Synced From: LeetCode
 * Date: 2026-09-01
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size();
        int n = classroom[0].size();

        int sr = -1, sc = -1;
        int litterCount = 0;

        vector<vector<int>> id(m, vector<int>(n, -1));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (classroom[i][j] == 'S') {
                    sr = i;
                    sc = j;
                }
                else if (classroom[i][j] == 'L') {
                    id[i][j] = litterCount++;
                }
            }
        }

        if (litterCount == 0) return 0;

        int FULL = (1 << litterCount) - 1;

        /*
            best[mask][position] = maximum energy remaining
            with which we have reached this state.
        */
        vector<vector<int>> best(
            1 << litterCount,
            vector<int>(m * n, -1)
        );

        queue<array<int, 5>> q;
        // {row, col, mask, remainingEnergy, moves}

        q.push({sr, sc, 0, energy, 0});
        best[0][sr * n + sc] = energy;

        int dr[4] = {1, -1, 0, 0};
        int dc[4] = {0, 0, 1, -1};

        while (!q.empty()) {
            auto cur = q.front();
            q.pop();

            int r = cur[0];
            int c = cur[1];
            int mask = cur[2];
            int rem = cur[3];
            int moves = cur[4];

            if (mask == FULL)
                return moves;

            // Cannot make another move without energy
            if (rem == 0)
                continue;

            for (int d = 0; d < 4; d++) {
                int nr = r + dr[d];
                int nc = c + dc[d];

                if (nr < 0 || nr >= m || nc < 0 || nc >= n)
                    continue;

                if (classroom[nr][nc] == 'X')
                    continue;

                int newRem = rem - 1;
                int newMask = mask;

                // Collect litter
                if (id[nr][nc] != -1) {
                    newMask |= (1 << id[nr][nc]);
                }

                // Reset energy
                if (classroom[nr][nc] == 'R') {
                    newRem = energy;
                }

                int pos = nr * n + nc;

                /*
                    If we've already reached the same
                    (position, mask) with equal or more energy,
                    this state is useless.
                */
                if (best[newMask][pos] >= newRem)
                    continue;

                best[newMask][pos] = newRem;

                q.push({
                    nr,
                    nc,
                    newMask,
                    newRem,
                    moves + 1
                });
            }
        }

        return -1;
    }
};