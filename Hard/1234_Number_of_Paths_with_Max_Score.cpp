/*
 * Problem: Number of Paths with Max Score
 * Problem ID: 1234
 * Difficulty: Hard
 * Language: C++
 * Runtime: 5 ms
 * Memory: 11.6 MB
 * Synced From: LeetCode
 * Date: 2026-07-05
 */

class Solution {
public:
    const int MOD = 1e9 + 7;

    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n = board.size();

        vector<vector<int>> dp(n, vector<int>(n, -1));     
        vector<vector<int>> ways(n, vector<int>(n, 0));     

        dp[n - 1][n - 1] = 0;   
        ways[n - 1][n - 1] = 1;

        for (int i = n - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (board[i][j] == 'X' || (i == n - 1 && j == n - 1))
                    continue;

                int best = -1;
                long long cnt = 0;


                if (i + 1 < n && dp[i + 1][j] != -1) {
                    if (dp[i + 1][j] > best) {
                        best = dp[i + 1][j];
                        cnt = ways[i + 1][j];
                    } else if (dp[i + 1][j] == best) {
                        cnt = (cnt + ways[i + 1][j]) % MOD;
                    }
                }

            
                if (j + 1 < n && dp[i][j + 1] != -1) {
                    if (dp[i][j + 1] > best) {
                        best = dp[i][j + 1];
                        cnt = ways[i][j + 1];
                    } else if (dp[i][j + 1] == best) {
                        cnt = (cnt + ways[i][j + 1]) % MOD;
                    }
                }


                if (i + 1 < n && j + 1 < n && dp[i + 1][j + 1] != -1) {
                    if (dp[i + 1][j + 1] > best) {
                        best = dp[i + 1][j + 1];
                        cnt = ways[i + 1][j + 1];
                    } else if (dp[i + 1][j + 1] == best) {
                        cnt = (cnt + ways[i + 1][j + 1]) % MOD;
                    }
                }

                if (best == -1) continue;

                int val = 0;
                if (board[i][j] != 'E' && board[i][j] != 'S')
                    val = board[i][j] - '0';

                dp[i][j] = best + val;
                ways[i][j] = cnt % MOD;
            }
        }

        if (dp[0][0] == -1) return {0, 0};

        return {dp[0][0], ways[0][0]};
    }
};