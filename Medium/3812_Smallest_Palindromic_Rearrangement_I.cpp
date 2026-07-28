/*
 * Problem: Smallest Palindromic Rearrangement I
 * Problem ID: 3812
 * Difficulty: Medium
 * Language: C++
 * Runtime: 17 ms
 * Memory: 73.9 MB
 * Synced From: LeetCode
 * Date: 2026-07-28
 */

class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int> freq(26, 0);

        for (char c : s)
            freq[c - 'a']++;

        string firstHalf = "";
        char middle = '\0';

        for (int i = 0; i < 26; i++) {
            firstHalf.append(freq[i] / 2, char('a' + i));
            if (freq[i] % 2)
                middle = char('a' + i);
        }

        string secondHalf = firstHalf;
        reverse(secondHalf.begin(), secondHalf.end());

        if (middle)
            return firstHalf + middle + secondHalf;

        return firstHalf + secondHalf;
    }
};