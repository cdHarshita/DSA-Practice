// Problem: Two Furthest Houses With Different Colors
// Link: https://leetcode.com/problems/two-furthest-houses-with-different-colors/
// Date: 2026-04-20
// Difficulty: Easy
// Language: C++

class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n = colors.size();
        int ans = 0;

        // compare with first element
        for(int i = n - 1; i >= 0; i--){
            if(colors[i] != colors[0]){
                ans = max(ans, i);
                break;
            }
        }

        // compare with last element
        for(int i = 0; i < n; i++){
            if(colors[i] != colors[n - 1]){
                ans = max(ans, n - 1 - i);
                break;
            }
        }

        return ans;
    }
};
