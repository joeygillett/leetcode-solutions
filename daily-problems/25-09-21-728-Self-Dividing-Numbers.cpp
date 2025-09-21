/*
Problem: Self Dividing Numbers (LeetCode #728) 
Find all self dividing numbers between bounds left and right inclusive. Self dividing meaning it is divisible by each of its own digits.
Performance: 
- Runtime: 0 ms (Beats 100.00%)
- Memory: 9.03 MB (Beats 88.21%)
*/
class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> v;
        int num, dig;
        bool skip;

        for(int i = left; i <= right; ++i) {
            num = i;
            skip = false;

            //Check if if i is self dividing
            while(num > 0 && !skip) {
                dig = num % 10;

                //Short circuit evaluation to avoid divide by zero
                if(dig == 0 || i % dig != 0) {
                    skip = true;
                }
                num /= 10;
            }

            if(!skip) {
                v.push_back(i);
            }
        }
        return v;
    }
};