#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int n = words.size(), cnt = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int p = words[i].size(), q = words[j].size();
                if (p <= q && words[j].substr(0, p) == words[i] && words[j].substr(q - p) == words[i]) {
                    ++cnt;
                }
            }
        }
        return cnt;
    }
};