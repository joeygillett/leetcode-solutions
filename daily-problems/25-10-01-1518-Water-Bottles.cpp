/*
Problem: Water Bottles (LeetCode #1518)
Find the maximum amount of water bottles that can be drunk.
Drinking a full water bottle turns it into an empty bottle. 
numExchange number of empty bottles can be exchanged for one full water bottle.
Performance:
- Runtime: 0 ms (Beats 100.00%)
- Memory: 7.89 MB (Beats 45.09%)
*/
class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int numFullBottles = numBottles;
        int numEmptyBottles = 0;
        int totalDrunk = 0;
        while(numFullBottles > 0) {
            //Drink all the current full bottles
            totalDrunk += numFullBottles; 
            numEmptyBottles += numFullBottles; 
            numFullBottles = 0;
            //Exchange empty bottles
            numFullBottles += numEmptyBottles / numExchange; 
            numEmptyBottles = numEmptyBottles % numExchange;
        }
        return totalDrunk;
    }
};