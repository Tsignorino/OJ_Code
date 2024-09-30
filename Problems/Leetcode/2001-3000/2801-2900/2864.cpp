#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int n = s.size(), cnt = ranges::count(s, '1');
        return string(cnt - 1, '1') + string(n - cnt, '0') + "1";
    }
};