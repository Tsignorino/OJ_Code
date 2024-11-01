#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int mod = 1e9 + 7;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> id(n + 1);
    for (int i = 1; i <= n; ++i) {
        int v;
        cin >> v;
        id[v] = i;
    }

    int ans = n + 1;
    set<int> s;
    for (int i = 1; i <= n; ++i) {
        s.emplace(id[i]);
        if (i >= k) {
            ans = min(ans, *s.rbegin() - *s.begin());
            s.erase(id[i - k + 1]);
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
