/*
Problem: Letter Combinations of a Phone Number (LeetCode #17)
Return all possible letter combinations of a given digit string using the classic phone keypad mapping.
Performance:
- Runtime: 0 ms (Beats 100.00%)
- Memory: 9.10 MB (Beats 87.67%)
*/
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        //Return empty vector if input is empty
        if(digits.empty()) {
            return {};
        }
    
        vector<string> keypad = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

        vector<string> combos = {""};

        //Iterate through each digit in the input
        for(const char c : digits) {
            //Convert digit char to keypad index
            int i = c - '2';
            string letters = keypad[i];
            //Temporary vector to store only new combinations formed
            vector<string> newCombos;

            //Combine each existing combination with each letter
            for(const char l : letters) {
                for(const string& s : combos) {
                    newCombos.push_back(s + l);
                }
            }

            combos = newCombos;
        }

        return combos;
    }
};