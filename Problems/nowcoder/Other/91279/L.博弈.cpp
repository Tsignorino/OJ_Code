#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

/*
    https://ac.nowcoder.com/acm/contest/91279/L
*/

void solve() {
    int n;
    cin >> n;

    vector<int> vec(n + 1);
    vector<int> inDeg(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> vec[i];
        inDeg[vec[i]]++;
    }

    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (inDeg[i] == 0) {
            q.emplace(i);
        }
    }

    vector<int> vis(n + 1);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        vis[u] = 1;
        if (--inDeg[vec[u]] == 0) {
            q.emplace(vec[u]);
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        if (vis[i] == 0) {
            ans++;
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