#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> a(n);
    for (int& v : a) {
        cin >> v;
    }

    vector<int> b(m);
    map<int, int> cnt;
    for (int& v : b) {
        cin >> v;
        cnt[v]++;
    }

    int ans = 0, c = 0;
    for (int r = 0; r < n; ++r) {
        if (cnt[a[r]] > 0) {
            c++;
        }
        cnt[a[r]]--;

        int l = r + 1 - m;
        if (l < 0) {
            continue;
        }

        if (c >= k) {
            ans++;
        }

        if (++cnt[a[l]] > 0) {
            c--;
        }
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