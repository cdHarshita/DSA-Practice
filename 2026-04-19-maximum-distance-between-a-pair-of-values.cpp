// Problem: Maximum Distance Between a Pair of Values
// Link: https://leetcode.com/problems/maximum-distance-between-a-pair-of-values/
// Date: 2026-04-19
// Difficulty: Medium
// Language: C++

class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int i = 0;
        int j = 0;
        int n = nums1.size() ;
        int m = nums2.size();
        int ans = 0;
        while( i < n && j < m){
            if(nums1[i] <= nums2[j]){
                ans = max(ans,  j -i);
                j++;
            }
            else{
                i++;
            }
        }
        return ans == INT_MIN ? 0 : ans;
    }
};