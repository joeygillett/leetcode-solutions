/*
Problem: Container With Most Water (LeetCode #11)
Given an array of heights, find the maximum water container.
The area is determined by the shorter line and the distance between the lines.
Performance:
- Runtime: 0 ms (Beats 100.00%)
- Memory: 62.91 MB (Beats 48.06%)
*/
class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0;
        int j = height.size() - 1;
        int currArea = 0, maxArea = 0;

        //Two pointer approach to find max area efficiently
        while(i < j) {
            currArea = min(height[i], height[j]) * (j - i);
            maxArea = max(maxArea, currArea);

            //Move pointer to shorter line
            if(height[i] < height[j]) {
                ++i;
            } else {
                --j;
            }
        }
        return maxArea;
    }
};