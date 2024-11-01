#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        ranges::sort(happiness, greater<int>());
        ll ans = 0;
        for (int i = 0; i < k; ++i) {
            ans += max(happiness[i] * 1LL - i, 0LL);
        }
        return ans;
    }
};
