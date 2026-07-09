/*
 * Problem: Search in Rotated Sorted Array
 * Problem ID: 33
 * Difficulty: Medium
 * Language: C++
 * Runtime: 0 ms
 * Memory: 15 MB
 * Synced From: LeetCode
 * Date: 2026-07-09
 */

class Solution {
public:
    int search(vector<int>& arr, int target) {
        
        int start = 0 ;
        int end = arr.size()-1;

        while(start <= end ){

            int mid = start + (end - start)/2;

            if (arr[mid]== target){
                return mid;
            }

            // left side sorted
            else if (arr[mid] >= arr[start]){

                if (arr[start] <= target && target < arr[mid]){
                    end = mid -1 ;
                }
                else {
                    start = mid +1 ;
                }
            }

            // right side sorted
            else{

                if (arr[mid] < target && arr[end] >= target){
                    start = mid +1 ;
                }
                else {
                    end = mid -1 ;
                }
            }
        }

        return -1;    
    }
};