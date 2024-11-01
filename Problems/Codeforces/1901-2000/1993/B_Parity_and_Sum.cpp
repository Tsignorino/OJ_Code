#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;

static constexpr int MOD = 1e9 + 7;

void solve() {
    int n;
    cin >> n;

    vector<int> vec(n), evens;
    ll mx = 0;
    for (int& v : vec) {
        cin >> v;

        if (v % 2 == 0) {
            evens.emplace_back(v);
        } else {
            mx = max(mx, v * 1ll);
        }
    }

    int c = evens.size();
    if (c == 0 || c == n) {
        cout << 0 << "\n";
        return;
    }

    // 只能全变成奇数
    ranges::sort(evens);
    for (int i = 0; i < evens.size(); ++i) {
        if (mx < evens[i]) {
            c++; // 将 max(evens) 加到 mx 即可
            break;
        }
        mx = mx + evens[i];
    }
    cout << c << "\n";
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