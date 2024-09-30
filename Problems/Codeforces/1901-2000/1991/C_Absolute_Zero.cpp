#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<int> vec(n);
    for (int i = 0; i < n; ++i) {
        cin >> vec[i];
    }

    // for (int i = 1; i < n; i++) {
    //     if (vec[i] % 2 != vec[0] % 2) {
    //         std::cout << -1 << "\n";
    //         return;
    //     }
    // }

    vector<int> ans;
    int ok = 0;
    for (int k = 0; k < 40; ++k) {
        int mx = ranges::max(vec), mn = ranges::min(vec);
        int mid = (mx + mn) / 2;
        if (mx == 0) {
            ok = 1;
            break;
        }
        ans.emplace_back(mid);
        for (int i = 0; i < n; ++i) {
            vec[i] = abs(vec[i] - mid);
        }
    }

    if (ok) {
        cout << ans.size() << "\n";
        for (int& v : ans) {
            cout << v << " ";
        }
        cout << "\n";
    } else {
        cout << -1 << "\n";
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