/*
Problem: Final Value After Performing Operations (LeetCode #2011)
Given a vector of string operations take a variable initialized to 0 and 
increment it for "++X" or "X++" and decrement it for "--X" or "X--" (these are the only two operations)
Performance:
- Runtime: 0 ms (Beats 100.00%)
- Memory: 17.52 MB (Beats 74.44%)
*/
class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int x = 0;
        //Iterate through operations
        for(string op : operations) {
            //Check for increment
            if(op == "X++" || op == "++X") {
                ++x;
            } else {
                //There are only two valid operations
                --x;
            }
        }
        return x;
    }
};