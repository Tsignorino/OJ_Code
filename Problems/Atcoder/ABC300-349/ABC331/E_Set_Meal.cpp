#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int mOD = 1'000'000'007;

void solve() {
    int n, m, L;
    cin >> n >> m >> L;

    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }

    vector<int> id(m);
    iota(id.begin(), id.end(), 0);
    ranges::sort(id, [&](int i, int j) { return b[i] < b[j]; });

    vector<set<int>> s(n);
    for (int i = 0; i < L; i++) {
        int c, d;
        cin >> c >> d;
        c--, d--;
        s[c].emplace(d);
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = m - 1; j >= 0; j--) {
            if (!s[i].contains(id[j])) {
                ans = max(ans, a[i] + b[id[j]]);
                break;
            }
        }
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}