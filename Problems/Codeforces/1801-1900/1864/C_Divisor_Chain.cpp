#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1e9 + 7;

void solve() {
    int n;
    cin >> n;

    vector<int> vec {n};
    while (n != (n & -n)) {
        n -= n & -n;
        vec.emplace_back(n);
    }
    while (n > 1) {
        n /= 2;
        vec.emplace_back(n);
    }

    cout << vec.size() << "\n";
    for (int& v : vec) {
        cout << v << " ";
    }
    cout << "\n";
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