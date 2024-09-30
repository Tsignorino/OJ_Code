#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> vec(n + 1);
    int id = 0, cnt = 0;
    for (int i = 0; i < m; ++i) {
        int v;
        cin >> v;

        vec[v]++;

        if (vec[v] > cnt) {
            cnt = vec[v];
            id = v;
        } else if (vec[v] == cnt && v < id) {
            id = v;
        }

        cout << id << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}