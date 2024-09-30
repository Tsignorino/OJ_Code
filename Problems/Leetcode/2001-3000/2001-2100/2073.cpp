#include <bits/stdc++.h>

#include "_debug.h"

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int ans = 0, t0 = tickets[k];
        for (int i = 0; i < tickets.size(); ++i) {
            ans += min(tickets[i], t0 - (i > k));
        }
        return ans;
    }
};

int main() {
    Solution sol;

    return 0;
}