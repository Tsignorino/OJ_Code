#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

vector<int> zfunc(const string& s) {
    int n = s.size();
    vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r) {
            z[i] = min(z[i - l], r - i + 1);
        }
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
            l = i, r = i + z[i]++;
        }
    }
    return z;
}

/*
    https://ac.nowcoder.com/acm/contest/88392/F
*/

void solve() {
    int n;
    cin >> n;

    string s, t;
    cin >> s >> t;

    vector<int> ans(n + 1);
    for (int i = n - 1; i > 0; --i) {
        if (s[i] == t[i]) {
            ans[i] = ans[i + 1] + 1;
        }
    }

    ranges::reverse(s);
    auto Z = zfunc(t + '#' + s);
    vector<int> z;
    for (int i = n + 1; i < Z.size(); ++i) {
        z.emplace_back(Z[i]);
    }
    ranges::reverse(z);

    int mx = -1, id = 0;
    for (int i = 0; i < n; ++i) {
        int res = z[i] + (z[i] <= i ? 0 : ans[i + 1]);
        if (res > mx) {
            mx = res;
            id = i;
        }
    }
    cout << mx << " " << id + 1 << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}