#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> vec(m);
    for (int& v : vec) {
        cin >> v;
    }

    vector<int> C(n);
    iota(C.begin(), C.end(), 1);
    vector<priority_queue<int>> Q(n);
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;

        for (int k = 0; k < m; ++k) {
            if (s[k] == 'o') {
                C[i] += vec[k];
            } else {
                Q[i].emplace(vec[k]);
            }
        }
    }

    int mx = ranges::max(C);
    for (int i = 0; i < n; ++i) {
        if (C[i] == mx) {
            cout << 0 << "\n";
            continue;
        }

        int cnt = 0;
        while (!Q[i].empty() && C[i] <= mx) {
            int v = Q[i].top();
            C[i] += v;
            Q[i].pop();
            cnt++;
        }
        cout << cnt << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}