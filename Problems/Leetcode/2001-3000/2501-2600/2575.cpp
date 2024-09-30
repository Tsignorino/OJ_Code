#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution {
public:
    vector<int> divisibilityArray(string word, int m) {
        int n = word.size();
        vector<int> ans(n);
        int mul = 10;
        ll num = 0;
        for (int i = 0; i < n; ++i) {
            num += (word[i] - '0') * mul;
            if (num % m == 0) {
                ans[i] = 1;
                num = 0;
            }
        }
        return ans;
    }
};