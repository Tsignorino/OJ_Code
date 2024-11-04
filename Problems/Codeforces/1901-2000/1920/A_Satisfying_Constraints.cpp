#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int mod = 1e9 + 7;

void solve() {
    int n;
    cin >> n;

    int k1 = 0, k2 = INT_MAX;
    vector<int> vec;
    while (n--) {
        int a, x;
        cin >> a >> x;

        if (a == 1) {
            k1 = max(k1, x);
        }
        if (a == 2) {
            k2 = min(k2, x);
        }
        if (a == 3) {
            vec.emplace_back(x);
        }
    }

    int cnt = k2 - k1 + 1;
    for (int& v : vec) {
        cnt -= v >= k1 && v <= k2;
    }
    cout << max(cnt, 0) << "\n";
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
