/*
 * Problem: Concatenate Non-Zero Digits and Multiply by Sum I
 * Problem ID: 4135
 * Difficulty: Easy
 * Language: C++
 * Runtime: 0 ms
 * Memory: 9.3 MB
 * Synced From: LeetCode
 * Date: 2026-07-07
 */

class Solution {
public:
    long long sumAndMultiply(int n) {
        vector<int>digit;
        if(n==0){
            return 0 ;

        }
        while(n>0){
            digit.push_back(n%10);
            n/=10;
            
        }
        long long x=0;
        long long sum = 0;
        for(int i = digit.size()-1;i>=0;i--){
            if(digit[i] !=0 ){
                x=x*10 + digit[i];
                sum+=digit[i];
            }
        }
        return sum*x;
        
    }
};