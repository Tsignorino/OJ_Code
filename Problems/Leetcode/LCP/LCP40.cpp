#include <bits/stdc++.h>

using namespace std;

static constexpr int MOD = 1e9 + 7;

class Solution {
public:
    int maxmiumScore(vector<int>& cards, int cnt) {
        ranges::sort(cards, greater<>());

        vector<int> odds, evens;
        for (int& v : cards) {
            (v & 1 ? odds : evens).emplace_back(v);
        }

        int n = odds.size(), m = evens.size();
        int c0 = min(n, cnt), mx = c0 - (c0 % 2 == 1);
        int c1 = max(0, cnt - m), mn = c1 + (c1 % 2 == 1);
        if (cnt - mx > m || mn > mx) {
            return 0;
        }

        int p = mn, q = cnt - mn;
        int s1 = accumulate(odds.begin(), odds.begin() + p, 0);
        int s2 = accumulate(evens.begin(), evens.begin() + q, 0);
        int ans = s1 + s2;
        for (int i = p; i + 1 <= mx; i += 2, q -= 2) {
            s1 += odds[i] + odds[i + 1];
            s2 -= evens[q - 1] + evens[q - 2];
            ans = max(ans, s1 + s2);
        }
        return ans;
    }
};

int main() {
    Solution sol;

    vector<int> cards {3, 1, 6, 9, 2, 4, 9, 2, 3};
    sol.maxmiumScore(cards, 4);

    return 0;
}