/*
 * Problem: Longest Substring of One Repeating Character
 * Problem ID: 2319
 * Difficulty: Hard
 * Language: C++
 * Runtime: 156 ms
 * Memory: 98.8 MB
 * Synced From: LeetCode
 * Date: 2026-08-13
 */

class Solution {
public:
    struct Node {
        char leftChar, rightChar;
        int leftLen, rightLen;
        int maxLen, len;

        Node() {}

        Node(char c) {
            leftChar = rightChar = c;
            leftLen = rightLen = maxLen = len = 1;
        }
    };

    vector<Node> tree;

    Node merge(Node &a, Node &b) {
        Node res;
        res.len = a.len + b.len;

        res.leftChar = a.leftChar;
        res.rightChar = b.rightChar;

        // Prefix
        res.leftLen = a.leftLen;
        if (a.leftLen == a.len && a.rightChar == b.leftChar)
            res.leftLen = a.len + b.leftLen;

        // Suffix
        res.rightLen = b.rightLen;
        if (b.rightLen == b.len && a.rightChar == b.leftChar)
            res.rightLen = b.len + a.rightLen;

        // Maximum inside either side
        res.maxLen = max(a.maxLen, b.maxLen);

        // Join suffix of a + prefix of b
        if (a.rightChar == b.leftChar)
            res.maxLen = max(res.maxLen, a.rightLen + b.leftLen);

        return res;
    }

    void build(string &s, int node, int l, int r) {
        if (l == r) {
            tree[node] = Node(s[l]);
            return;
        }

        int mid = (l + r) / 2;

        build(s, node * 2, l, mid);
        build(s, node * 2 + 1, mid + 1, r);

        tree[node] = merge(tree[node * 2], tree[node * 2 + 1]);
    }

    void update(int node, int l, int r, int idx, char c) {
        if (l == r) {
            tree[node] = Node(c);
            return;
        }

        int mid = (l + r) / 2;

        if (idx <= mid)
            update(node * 2, l, mid, idx, c);
        else
            update(node * 2 + 1, mid + 1, r, idx, c);

        tree[node] = merge(tree[node * 2], tree[node * 2 + 1]);
    }

    vector<int> longestRepeating(
        string s,
        string queryCharacters,
        vector<int>& queryIndices
    ) {
        int n = s.size();

        tree.resize(4 * n + 5);

        build(s, 1, 0, n - 1);

        vector<int> ans;

        for (int i = 0; i < queryIndices.size(); i++) {
            int idx = queryIndices[i];
            char c = queryCharacters[i];

            update(1, 0, n - 1, idx, c);

            ans.push_back(tree[1].maxLen);
        }

        return ans;
    }
};