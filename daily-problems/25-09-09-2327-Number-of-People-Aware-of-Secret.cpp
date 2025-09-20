/*
Problem: Number of People Aware of a Secret (LeetCode #2327)
Given delay until a person starts sharing, and the number of days until they forget, compute how many people know the secret on day n.
Performance: 
- Runtime: 0 ms (Beats 100.00%)
- Memory: 9.16 MB (Beats 94.96%)
*/

class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        const int MODULUS = 1000000007;
        vector<int> numLearned(n); //numLearned[i] = number of people who learn the secret on day i - 1
        numLearned[0] = 1;
        long thoseWhoShare = 0; //Current number of people eligible to share

        //Sliding window to add new sharers and subtract forgetters
        for (int i = 1; i < n; ++i) {
            //Add sharers, skip if array out of bounds
            if(i - delay >= 0) {
                thoseWhoShare = (thoseWhoShare + numLearned[i - delay]) % MODULUS;
            }
            //Subtract forgetters, skip if array out of bounds
            if(i - forget >= 0) {
                thoseWhoShare = (thoseWhoShare - numLearned[i - forget] + MODULUS) % MODULUS;
            }
            numLearned[i] = thoseWhoShare;
        }
        //Sum the number of people who remember the secret on day n
        int thoseWhoKnow = 0;
        for (int j = n - forget; j < n; ++j) {
            thoseWhoKnow = (thoseWhoKnow + numLearned[j]) % MODULUS;
        }
        return thoseWhoKnow;
    }
};