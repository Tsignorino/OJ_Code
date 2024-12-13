#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#endif

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

vector<string> duval(const string& s) {
    vector<string> res;
    int n = s.size();
    int i = 0;
    while (i < n) {
        int j = i;
        int k = i + 1;
        while (k < n && s[j] <= s[k]) {
            if (s[j] < s[k]) {
                j = i;
            } else {
                j++;
            }
            k++;
        }
        while (i <= j) {
            res.emplace_back(s.substr(i, k - j));
            i += k - j;
        }
    }
    return res;
}

void solve() {
    string s;
    cin >> s;

    int ans = 0;
    int pre = 0;
    for (auto& s : duval(s)) {
        pre += s.size();
        ans ^= pre;
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}