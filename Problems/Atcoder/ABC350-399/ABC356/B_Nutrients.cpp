#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int mod = 1e9 + 7;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> a(m);
    for (int& v : a) {
        cin >> v;
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int val;
            cin >> val;
            a[j] -= val;
        }
    }

    if (ranges::max(a) > 0) {
        cout << "No\n";
        return;
    }
    cout << "Yes\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
