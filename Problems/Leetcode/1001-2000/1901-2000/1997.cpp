#include <bits/stdc++.h>

using namespace std;

class Solution {
    static constexpr int mod = 1e9 + 7;

public:
    // 前缀和优化DP
    int firstDayBeenInAllRooms(vector<int>& nextVisit) {
        // 0 <= nextVisit[i] <= i
        int n = nextVisit.size();
        vector<long long> s(n);
        for (int i = 0; i < n - 1; ++i) {
            s[i + 1] = (s[i] * 2 - s[nextVisit[i]] + 2 + mod) % mod;
        }
        return s[n - 1];
    }
};