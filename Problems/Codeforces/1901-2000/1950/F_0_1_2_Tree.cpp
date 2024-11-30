#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int a, b, c;
    cin >> a >> b >> c;

    if (c != a + 1) {
        cout << "-1\n";
        return;
    }

    queue<int> q;
    q.emplace(0);

    int ans = 0;
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        ans = x;
        if (a) {
            a--;
            q.emplace(x + 1);
            q.emplace(x + 1);
        } else if (b) {
            b--;
            q.emplace(x + 1);
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