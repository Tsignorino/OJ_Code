#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int n, q;
    cin >> n >> q;

    vector<int> vec(n);
    for (int& v : vec) {
        cin >> v;
    }

    vector<ll> pre(n + 1);
    for (int i = 0; i < n; ++i) {
        pre[i + 1] = pre[i] + vec[i];
    }

    vector<int> diff(n + 2);
    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            ll v = pre[j + 1] - pre[i];
            ll v1 = sqrt(v);
            if (v1 * v1 == v) {
                diff[i]++;
                diff[j + 1]--;
            }
        }
    }

    vector<ll> pre2(n + 3);
    for (int i = 0; i < n; ++i) {
        pre2[i + 1] = pre2[i] + diff[i];
    }

    while (q--) {
        int x;
        cin >> x;

        cout << pre2[x] << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}