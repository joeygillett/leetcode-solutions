/*
Problem: Successful Pairs of Spells and Potions (LeetCode #2300)
Given integer arrays spells and potions, find number of pairs of successful potions for each spell.
A spell and potion pair is successful if their product is at least success.
Performance:
- Runtime: 47 ms (Beats 39.82%)
- Memory: 124.97 MB (Beats 94.62%)
*/
class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int numSpell = spells.size();
        int numPot = potions.size();
        vector<int> out(numSpell);

        //Sort potions to allow binary search to work
        sort(potions.begin(), potions.end());

        //Iterate over each spell to find number of successful potions
        for(int i = 0; i < numSpell; ++i) {
            //Binary search sorted potions for smallest successful index
            int left = 0;
            int right = numPot - 1;
            int pos = numPot; //Lowest successful index, defaulted to numPot if none successful

            while(left <= right) {
                int mid = left + (right - left) / 2; 
                long long product = (long long)spells[i] * potions[mid];

                if(product >= success) {
                   pos = mid;
                   right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
            //Output for spell is total potions minus the first successful index
            out[i] = numPot - pos;
        }
        return out;
    }
};