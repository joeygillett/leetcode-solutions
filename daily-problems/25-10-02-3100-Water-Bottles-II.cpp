/*
Problem: Water Bottles II (LeetCode #3100)
Find the maximum amount of water bottles that can be drunk.
Drinking a full water bottle turns it into an empty bottle.
numExchange number of empty bottles can be exchanged for one full water bottle.
numExchange is increased by one every time bottles are exchanged.
Performance:
- Runtime: 0 ms (Beats 100.00%)
- Memory: 8.42 MB (Beats 79.30%)
*/
class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int emptyBottles = 0;
        int total = 0;
        while(numBottles > 0) {
            //Drink all the current full bottles
            emptyBottles += numBottles;
            total += numBottles;
            numBottles = 0;
            //Exchange empty bottles, increasing exchange rate
            if(emptyBottles >= numExchange) {
                emptyBottles -= numExchange;
                ++numBottles;
                ++numExchange;
            } else {
                //If there are no bottles to exchange, break the loop
                break;
            }
        }
        return total;
    }
};