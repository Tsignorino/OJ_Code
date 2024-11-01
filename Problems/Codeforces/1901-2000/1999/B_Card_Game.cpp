#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;

static constexpr int MOD = 1e9 + 7;

void solve() {
    vector<int> a(2), b(2);
    for (int& v : a) {
        cin >> v;
    }
    for (int& v : b) {
        cin >> v;
    }

    int cnt = 0;
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            if (a[i] > b[j] && a[i ^ 1] > b[j ^ 1] || a[i] > b[j] && a[i ^ 1] == b[j ^ 1] || a[i] == b[j] && a[i ^ 1] > b[j ^ 1]) {
                cnt++;
            }
        }
    }
    cout << cnt << "\n";
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