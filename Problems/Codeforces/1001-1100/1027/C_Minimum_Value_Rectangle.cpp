#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#endif

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int n;
    cin >> n;

    map<int, int> C;
    for (int i = 0; i < n; ++i) {
        int v;
        cin >> v;
        C[v]++;
    }

    vector<int> vec;
    for (auto& [v, c] : C) {
        if (c >= 4) {
            cout << format("{} {} {} {}", v, v, v, v) << "\n";
            return;
        } else if (c >= 2) {
            vec.push_back(v);
        }
    }

    int a = 1, b = 0;
    for (int i = 1; i < vec.size(); ++i) {
        if (vec[i] * b < vec[i - 1] * a) {
            a = vec[i], b = vec[i - 1];
        }
    }
    cout << format("{} {} {} {}", a, a, b, b) << "\n";
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