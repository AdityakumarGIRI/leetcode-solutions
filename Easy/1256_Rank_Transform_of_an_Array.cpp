/*
 * Problem: Rank Transform of an Array
 * Problem ID: 1256
 * Difficulty: Easy
 * Language: C++
 * Runtime: 83 ms
 * Memory: 45.7 MB
 * Synced From: LeetCode
 * Date: 2026-07-12
 */

class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int>temp = arr;
        sort(temp.begin(),temp.end());

        map<int,int> rank;
        int currentrank =1;
        for(int i = 0 ; i < temp.size() ; i++){
            if(rank.find(temp[i])== rank.end()){
                rank[temp[i]] = currentrank;
                currentrank++;
            }
        }
        vector<int>answer;

        for(int i = 0 ;i < arr.size();i++){
            answer.push_back(rank[arr[i]]);

        }
        return answer;
    }
};