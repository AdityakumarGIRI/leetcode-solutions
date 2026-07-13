/*
 * Problem: Sequential Digits
 * Problem ID: 1212
 * Difficulty: Medium
 * Language: C++
 * Runtime: 2 ms
 * Memory: 8.2 MB
 * Synced From: LeetCode
 * Date: 2026-07-13
 */

class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string digits = "123456789";
        vector<int> ans;

        int minlen = to_string(low).size();
        int maxlen = to_string(high).size();

        for (int len = minlen; len <= maxlen; len++) {

           
            for (int i = 0; i + len <= 9; i++) {

                int num = stoi(digits.substr(i, len));

                if (num >= low && num <= high)
                    ans.push_back(num);
            }
        }

        return ans;



        
    }
};