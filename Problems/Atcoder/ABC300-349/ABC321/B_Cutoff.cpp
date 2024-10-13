#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int n, s;
    cin >> n >> s;

    vector<int> vec(n - 1);
    for (int& v : vec) {
        cin >> v;
    }

    for (int i = 0; i <= 100; ++i) {
        vector<int> res(vec);
        res.emplace_back(i);
        ranges::sort(res);
        if (accumulate(res.begin() + 1, res.end() - 1, 0) >= s) {
            cout << i << "\n";
            return;
        }
    }
    cout << -1 << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}