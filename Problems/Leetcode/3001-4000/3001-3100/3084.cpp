#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long countSubstrings(string s, char c) {
        int cnt = ranges::count(s, c);
        return cnt * 1LL * (cnt + 1) / 2;
    }
};