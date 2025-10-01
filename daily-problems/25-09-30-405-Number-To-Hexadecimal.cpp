/*
Problem: Convert a Number to Hexadecimal (LeetCode #405)
Convert a 32 bit int to a string of its hexadecimal representation, using two's complement for negative numbers.
Performance:
- Runtime: 0 ms (Beats 100.00%)
- Memory: 7.9 MB (Beats 44.78%)
*/
class Solution {
public:
    string toHex(int num) {
        char digits[] = {'0', '1', '2', '3', '4', '5', '6', '7', 
                         '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};
        string hex ="";

        //Handle zero case
        if(num == 0) {
            return "0";
        }

        //Handle positive numbers
        while(num > 0) {
            hex = digits[num % 16] + hex;
            num /= 16;
        }

        //Handle negative numbers (two's complement)
        if(num < 0) {
            //Convert by adding 2^32 + 1
            long complement = 0xffffffff + num + 1;
            while(complement > 0) {
                hex = digits[complement % 16] + hex;
                complement /= 16;
            }
        }
        return hex;
    }
};