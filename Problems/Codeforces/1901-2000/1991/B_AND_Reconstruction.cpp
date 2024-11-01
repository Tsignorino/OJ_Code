#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<int> vec(n - 1);
    for (int& v : vec) {
        cin >> v;
    }

    for (int i = 1; i < n - 2; ++i) {
        int val = vec[i - 1] & vec[i + 1];
        for (int k = 30; k >= 0; --k) {
            if ((val >> k & 1) == 1 && (vec[i] >> k & 1) == 0) {
                cout << -1 << "\n";
                return;
            }
        }
    }

    vec.emplace_back(0);
    vector<int> ans(n);
    ans[0] = vec[0];
    for (int i = 1; i < n; ++i) {
        ans[i] = vec[i - 1] | vec[i];
    }
    for (int& v : ans) {
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