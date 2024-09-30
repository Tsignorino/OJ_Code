#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int n, x;
    cin >> n >> x;

    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }

    vector<int> id_a(n);
    iota(id_a.begin(), id_a.end(), 0);
    ranges::sort(id_a, [&](int i, int j) { return a[i] < a[j]; });

    vector<int> id_b(n);
    iota(id_b.begin(), id_b.end(), 0);
    ranges::sort(id_b, [&](int i, int j) { return b[i] < b[j]; });

    vector<int> c(n);
    for (int i = 0; i < n; ++i) {
        c[id_a[i]] = b[id_b[(i + x) % n]];
    }

    int k = 0;
    for (int i = 0; i < n; ++i) {
        k += a[i] > c[i];
    }
    if (k == x) {
        cout << "YES\n";
        for (int i = 0; i < n; ++i) {
            cout << c[i] << " \n"[i == n - 1];
        }
    } else {
        cout << "NO\n";
    }
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