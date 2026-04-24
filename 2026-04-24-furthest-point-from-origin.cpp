// Problem: Furthest Point From Origin
// Link: https://leetcode.com/problems/furthest-point-from-origin/
// Date: 2026-04-24
// Difficulty: Easy
// Language: C++

class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int left = 0, right = 0, blank = 0;

        for (char c : moves) {
            if (c == 'L') left++;
            else if (c == 'R') right++;
            else blank++;
        }

        // Net distance without blanks
        int dist = abs(right - left);

        // Use all blanks to maximize distance
        return dist + blank;
    }
};
