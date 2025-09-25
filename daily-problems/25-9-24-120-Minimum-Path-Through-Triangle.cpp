/*
Problem: Minimum Path Through Triangle (LeetCode #120) 
Given triangle array return the minimum path sum from top to bottom, moving only to the adjacent number of the row below.
Performance: 
- Runtime: 0 ms (Beats 100.00%)
- Memory: 12.47 MB (Beats 97.14%)
*/
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int h = triangle.size();
        //Edit the values in place from the penultimate row up adding the minimum below
        for(int i = h - 2; i >= 0; --i) {
            int w = triangle[i].size();
            for(int j = 0; j < w; ++j) {
                triangle[i][j] += min(triangle[i+1][j], triangle[i+1][j+1]);
            }
        }
        //The top value is now the minimum path sum
        return triangle[0][0];
    }
};