#include <bits/stdc++.h>

using namespace std;

constexpr int mod = 1e9 + 7;
constexpr int MX = 1e5 + 1;
vector<int> f(MX), g(MX);
int init = []() {
    f[0] = g[0] = 1;
    f[1] = g[1] = 1;
    f[2] = g[2] = 2;
    f[3] = g[3] = 4;
    for (int i = 4; i < MX; ++i) {
        f[i] = (int) ((f[i - 1] * 1ll + f[i - 2] + f[i - 3]) % mod);
        g[i] = (int) ((g[i - 1] * 1ll + g[i - 2] + g[i - 3] + g[i - 4]) % mod);
    }
    return 0;
}();

class Solution {
public:
    int countTexts(string s) {
        int n = s.size();
        int ans = 1, cnt = 0;
        for (int i = 0; i < n; ++i) {
            cnt++;
            char ch = s[i];
            if (i == n - 1 || ch != s[i + 1]) {
                ans = (int) (ans * 1ll * (ch != '7' && ch != '9' ? f[cnt] : g[cnt]) % mod);
                cnt = 0;
            }
        }
        return ans;
    }
};