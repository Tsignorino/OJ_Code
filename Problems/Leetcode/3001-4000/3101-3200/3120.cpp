#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numberOfSpecialChars(string word) {
        int mask[2] {};
        for (char ch : word) {
            mask[ch >> 5 & 1] |= 1 << (ch & 31);
        }
        return __popcount(mask[0] & mask[1]);
    }
};

class mySolution {
public:
    int numberOfSpecialChars(string word) {
        vector<int> vec(26);
        for (char ch : word) {
            if (islower(ch)) {
                vec[ch - 'a'] |= 1;
            } else {
                vec[ch - 'A'] |= 2;
            }
        }
        return ranges::count(vec, 3);
    }
};
