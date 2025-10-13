/*
Problem: Remove Consecutive Anagrams (LeetCode #2273)
Given a vector of strings, return a vector of strings which removes consecutive anagrams.
Performance:
- Runtime: 0 ms (Beats 100.00%)
- Memory: 16.07 MB (Beats 75.29%)
*/
class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> ans;
        string prevSorted = "";

        for (string& word : words) {
            //Create a buffer string to sort and check
            string sortedWord = word;
            sort(sortedWord.begin(), sortedWord.end());
            //Add the word if it is distinct from the previous
            if (sortedWord != prevSorted) {
                ans.push_back(word);
                prevSorted = sortedWord;
            }
        }
        return ans;
    }
};