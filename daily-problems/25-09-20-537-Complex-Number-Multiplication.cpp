/*
Problem: Complex Number Multiplication (LeetCode #537)
Given two strings of form "a+bi" compute their complex product and return the result in the same format.
Performance: 
- Runtime: 0 ms (Beats 100.00%)
- Memory: 7.84 MB (Beats 83.18%)
*/
class Solution {
public:
    string complexNumberMultiply(string num1, string num2) {
        //Parse the string into its real and imaginary components
        int plusIndex = num1.find("+");
        int re1 = stoi(num1.substr(0, plusIndex));
        int im1 = stoi(num1.substr(plusIndex + 1, num1.find("i") - plusIndex - 1));
        
        plusIndex = num2.find("+");
        int re2 = stoi(num2.substr(0, plusIndex));
        int im2 = stoi(num2.substr(plusIndex + 1, num2.find("i") - plusIndex - 1));

        //Multiply the numbers with standard "foiling" method
        int re3 = re1 * re2 - im1 * im2;
        int im3 = re1 * im2 + re2 * im1;

        //Return the result formatted in "a+bi" format
        return to_string(re3) + "+" + to_string(im3) + "i";
    }
};