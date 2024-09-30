#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1e9 + 7;

void solve() {
    int n;
    string s;
    cin >> n >> s;

    ll ans = LLONG_MAX / 2;
    for (int i = 0; i < n - 1; ++i) { // 把当前位和后面一位合并
        vector<int> vec;
        for (int j = 0; j < n; ++j) {
            if (i == j) {
                vec.emplace_back(stoi(s.substr(i, 2)));
                j++;
            } else {
                vec.emplace_back(int(s[j] - '0'));
            }
        }

        if (count(vec.begin(), vec.end(), 1) == vec.size()) { // 特判全为 1 的情况
            ans = min(ans, 1ll);
            continue;
        }

        ll res = 0;
        for (int i = 0; i < vec.size(); ++i) {
            if (vec[i] == 0) {
                cout << 0 << "\n";
                return;
            } else if (vec[i] == 1) {
                continue;
            } else {
                res += vec[i];
            }
        }

        ans = min(ans, res);
    }

    cout << ans << "\n";
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