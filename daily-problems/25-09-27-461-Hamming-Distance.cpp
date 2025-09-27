/*
Problem: Hamming Distance (LeetCode #461)
Given two ints, return the hamming distance: the number of bits which are different.
Performance:
- Runtime: 0 ms (Beats 100.00%)
- Memory: 7.79 MB (Beats 95.34%)
*/
class Solution {
public:
    int hammingDistance(int x, int y) {
        int total = 0;
        //Evaluate each bit by boring bit
        while(x || y) {
            total += (x % 2) ^ (y % 2);
            x /= 2;
            y /= 2;
        }
        return total;
    }
};