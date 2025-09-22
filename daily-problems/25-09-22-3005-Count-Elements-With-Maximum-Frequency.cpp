/*
Problem: Count Elements With Maximum Frequency (LeetCode #3005) 
Given an array of integers, return the total number of elements that occur with the highest frequency.
Performance: 
- Runtime: 0 ms (Beats 100.00%)
- Memory: 23.21 MB (Beats 36.33%)
*/
class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        //Hash map to count frequency of each element
        unordered_map<int, int> countMap;
        for(int num : nums) {
            countMap[num]++;
        }

        int maxFreq = 0;
        int total = 0; //Total number of elements with maxFrequency

        //Iterate through frequency map to find total elements with maximum frequency
        for(auto pair : countMap) {
            if(pair.second > maxFreq) {
                //If a higher frequency is found, update maxFreq and reset total
                maxFreq = pair.second;
                total = maxFreq;
            } else if (pair.second == maxFreq) {
                //If the same frequency is found, add to total
                total += maxFreq;
            }
        }
        return total;
    }
};