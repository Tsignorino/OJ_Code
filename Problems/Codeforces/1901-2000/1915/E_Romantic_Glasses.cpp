#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int mod = 1e9 + 7;

void solve() {
    int n;
    cin >> n;

    map<ll, int> mp {
        {0, 1}
    };
    ll sum = 0;
    int flag = 0;
    for (int i = 0; i < n; ++i) {
        int v;
        cin >> v;

        if (i & 1) {
            v = -v;
        }

        sum += v;
        if (mp[sum]) {
            flag = 1;
        }
        mp[sum]++;
    }

    cout << (flag ? "YES" : "NO") << "\n";
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
