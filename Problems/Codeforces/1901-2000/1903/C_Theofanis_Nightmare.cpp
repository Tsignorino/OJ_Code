#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int MOD = 1e9 + 7;

/*
    将 [1, 2, 3, 4] 划分成 [1, 2] [3, 4]，即 (1+2)*1 + (3+4) * 2  <==>  (1+2+3+4) + (3+4)
 */
void solve() {
    int n;
    cin >> n;
    vector<int> vec(n);
    for (int& v : vec) {
        cin >> v;
    }

    ll sum = 0, suf = 0;
    for (int i = n - 1; i >= 0; --i) {
        suf += vec[i];
        if (i == 0 || suf > 0) {
            sum += suf;
        }
    }
    cout << sum << "\n";
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
