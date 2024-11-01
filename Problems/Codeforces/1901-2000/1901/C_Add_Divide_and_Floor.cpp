#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<int> vec(n);
    for (int& v : vec) {
        cin >> v;
    }

    int mx = ranges::max(vec), mn = ranges::min(vec);

    vector<int> res;
    while (mx > mn) {
        int x = mn & 1;
        res.emplace_back(x);
        mx = (mx + x) / 2;
        mn = (mn + x) / 2;
    }

    cout << res.size() << "\n";
    if (res.size() <= n) {
        for (int& v : res) {
            cout << v << " ";
        }
        cout << "\n";
    }
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