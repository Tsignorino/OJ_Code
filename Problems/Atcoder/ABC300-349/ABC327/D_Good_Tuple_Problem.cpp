#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> A(m), B(m);
    for (int i = 0; i < m; ++i) {
        cin >> A[i];
        A[i]--;
    }
    for (int i = 0; i < m; ++i) {
        cin >> B[i];
        B[i]--;
    }

    vector<vector<int>> g(n);
    for (int i = 0; i < m; i++) {
        g[A[i]].emplace_back(B[i]);
        g[B[i]].emplace_back(A[i]);
    }

    vector<int> flag(n, -1);
    for (int i = 0; i < n; i++) {
        if (flag[i] == -1) {
            queue<int> q;
            q.emplace(i);
            flag[i] = 0;
            while (!q.empty()) {
                int x = q.front();
                q.pop();
                for (int y : g[x]) {
                    if (flag[y] == -1) {
                        flag[y] = flag[x] ^ 1;
                        q.emplace(y);
                    } else if (flag[x] == flag[y]) {
                        cout << "No\n";
                        return;
                    }
                }
            }
        }
    }
    cout << "Yes\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}