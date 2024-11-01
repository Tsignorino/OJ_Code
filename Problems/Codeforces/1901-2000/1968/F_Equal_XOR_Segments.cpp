#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int n, q;
    cin >> n >> q;
    map<int, vector<int>> id {
        {0, {0}}
    };
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];

        a[i] ^= a[i - 1];
        id[a[i]].emplace_back(i);
    }

    while (q--) {
        int l, r;
        cin >> l >> r;

        // k == 2, [l, m] 和 [m+1, r]
        // a[m] ^ a[l-1] = a[r] ^ a[m]，即 a[l-1] = a[r]
        if (a[l - 1] == a[r]) {
            cout << "YES\n";
            continue;
        }

        // k > 3 ==> k == 3
        // k == 3, [l, s], [s+1, m], [m+1, r]
        // a[s] ^ a[l-1] = a[m] ^ a[s] = a[r] ^ a[m]，即 a[m] = a[l-1], a[r] = a[s], s < m
        int p1 = *prev(ranges::lower_bound(id[a[l - 1]], r));
        int p2 = *ranges::lower_bound(id[a[r]], l);
        cout << (p1 > p2 ? "YES" : "NO") << "\n";
    }
    cout << "\n";
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