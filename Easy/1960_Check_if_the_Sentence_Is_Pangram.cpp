/*
 * Problem: Check if the Sentence Is Pangram
 * Problem ID: 1960
 * Difficulty: Easy
 * Language: C++
 * Runtime: 0 ms
 * Memory: 8.9 MB
 * Synced From: LeetCode
 * Date: 2026-07-01
 */

class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector<bool>alpha(26,0);
        for(int i=0 ;i<sentence.size();i++ ){
            int index = sentence[i] - 'a';
            alpha[index] =1;

        }
        for(int i = 0 ; i<26 ; i++){
            if(alpha[i]==0){
                return 0;
            }
        }
        return 1;
    }
};