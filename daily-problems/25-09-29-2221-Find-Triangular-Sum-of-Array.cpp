/*
Problem: Find Triangular Sum of an Array (LeetCode #2221)
Given an array of digits, replace each element with the sum of it and its neighbor to the right modulo 10, until one element remains.
Performance:
- Runtime: 49 ms (Beats 89.61%)
- Memory: 22.46 MB (Beats 60.31%)
*/
class Solution {
public:
    int triangularSum(vector<int>& nums) {
        //Loop through the vector until only one value remains
        while (nums.size() > 1) {
            for (int i = 0; i < nums.size() - 1; ++i) {
                //Replace each element with the sum of it and its neighbor mod 10
                nums[i] = (nums[i] + nums[i + 1]) % 10;
            }
            //One value becomes obsolete each iteration
            nums.pop_back();
        }
        return nums[0];
    }
};