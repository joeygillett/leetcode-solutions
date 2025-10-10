/*
Problem: Taking Maximum Energy From the Mystic Dungeon (LeetCode #3147)
Find the highest total that can be obtained from an array, starting at any index and summing every k-th element.
Performance:
- Runtime: 129 ms (Beats 86.27%)
- Memory: 145.37 MB (Beats 88.38%)
*/
class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int oneEnergy = energy.size();
        int total = 0;
        int max = INT_MIN;

        //Iterate only through the last k indicies to cover all backward paths
        for(int i = oneEnergy - 1; i > oneEnergy - 1 - k; --i) {
            total = 0;
            
            //Traverse backwards summing the energy and finding the maximum
            for(int j = i; j >= 0; j -= k) {
                total += energy[j];
                if(total > max) {
                    max = total;
                }
            }
        }
        return max;
    }
};