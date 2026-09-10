/*
 * Problem: Count Nodes Equal to Average of Subtree
 * Problem ID: 2347
 * Difficulty: Medium
 * Language: C++
 * Runtime: 10 ms
 * Memory: 15.7 MB
 * Synced From: LeetCode
 * Date: 2026-09-10
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int ans = 0;

    // Returns {sum, count} of the subtree
    pair<int, int> dfs(TreeNode* root) {
        if (root == nullptr)
            return {0, 0};

        // Get information from left and right subtrees
        auto left = dfs(root->left);
        auto right = dfs(root->right);

        // Calculate sum and count of current subtree
        int sum = root->val + left.first + right.first;
        int count = 1 + left.second + right.second;

        // Check if current node equals subtree average
        if (root->val == sum / count)
            ans++;

        return {sum, count};
    }

    int averageOfSubtree(TreeNode* root) {
        dfs(root);
        return ans;
    }
};