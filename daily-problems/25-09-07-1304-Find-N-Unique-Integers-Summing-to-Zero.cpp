/*
Problem: Find N Unique Integers Sum up to Zero (LeetCode #1304)
Given an integer n, return any array containing n unique integers such that they add up to 0.
Performance: 
- Runtime: 0 ms (Beats 100%)
- Memory: 9.62 MB (Beats 55.05%)
*/
class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> v;
        // Include 0 if n is odd to balance sum
        if(n % 2 == 1) {
            v.push_back(0);
        }
        //Add +i and -i to sum to zero
        for(int i = 1; i < n / 2 + 1; ++i) {
            v.push_back(i);
            v.push_back(-i);
        }
        return v;
    }
};