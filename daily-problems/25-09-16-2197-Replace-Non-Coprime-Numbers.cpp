/*
Problem: Replace Non-Coprime Numbers in Array (LeetCode #2197)
Given an array of integers replace every pair of adjacent non-coprime integers with their lcm.
Performance: 
- Runtime: 20 ms (Beats 58.80%)
- Memory: 125.29 MB (Beats 44.44%)
*/
class Solution {
public:

    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int> v; //Vector v functions as a stack holding the current array
        int current;
        for(int num : nums) {
            current = num;
            //While the top element is not coprime
            while(!v.empty() && gcd(v.back(), current) > 1) {
                //Merge the numbers with their lcm
                current = std::lcm(v.back(), current);
                v.pop_back(); 
            }
            v.push_back(current);
        }
        return v;
    }
};