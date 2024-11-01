#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int MOD = 1e9 + 7;

void solve() {
    int n, f, k;
    cin >> n >> f >> k;
    vector<int> vec(n);
    for (int& v : vec) {
        cin >> v;
    }
    int val = vec[--f];

    // ranges::sort(vec, greater<>());
    int c1 = 0, c2 = 0;
    for (int& v : vec) {
        c1 += v > val;
        c2 += v >= val;
    }
    // cout << c1 << " " << c2 << "\n";
    if (k <= c1) {
        cout << "NO\n";
    } else if (k >= c2) {
        cout << "YES\n";
    } else {
        cout << "MAYBE\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(20);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}
