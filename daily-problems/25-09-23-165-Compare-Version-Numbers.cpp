/*
Problem: Compare Version Numbers (LeetCode #165) 
Given two version strings, revision numbers separated by dots (e.g. 1.0.2), compare their revision values
in left to right order, returning -1 if version1 < version2, 1 if version1 > version2, and 0 if they are equal.
Performance: 
- Runtime: 0 ms (Beats 100.00%)
- Memory: 9.26 MB (Beats 5.69%)
*/
class Solution {
public:
    int compareVersion(string version1, string version2) {
        //Parse versions, Convert to vector of ints
        vector<int> v1, v2;

        while(version1.find('.') != -1) {
            v1.push_back(stoi(version1.substr(0, version1.find('.'))));
            version1 = version1.substr(version1.find('.') + 1);
        }
        v1.push_back(stoi(version1));

        while(version2.find('.') != -1) {
            v2.push_back(stoi(version2.substr(0, version2.find('.'))));
            version2 = version2.substr(version2.find('.') + 1);
        }
        v2.push_back(stoi(version2));

        //Equalize length of versions by appending zeros
        int len1 = v1.size();
        int len2 = v2.size();
        int diff = len1 - len2;
        for(int i = 0; i < diff; ++i) {
            v2.push_back(0);
        }
        for(int j = 0; j > diff; --j) {
            v1.push_back(0);
        }

        //Compare versions in order of importance
        int len = v1.size();
        for(int k = 0; k < len; ++k) {
            if(v1[k] > v2[k]) {
                return 1;
            } else if(v1[k] < v2[k]) {
                return -1;
            }
        }
        return 0;
    }
};