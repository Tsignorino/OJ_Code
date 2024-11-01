#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

/*
    WA:
        1
        2 1 1
*/

void solve() {
    ll s, n, k;
    cin >> s >> n >> k; // s >= 1, n >= 1, k >= 0

    if (k > n) { // 需要补全 [0, k-1]，占据 k 个位置
        cout << "NO\n";
        return;
    }

    if (k == 0) {
        if (n > s) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
            for (int i = 0; i < n - 1; ++i) {
                cout << 1 << " ";
            }
            cout << s - n + 1 << "\n";
        }
        return;
    }

    // if (k == 1) { //! 必须输出一个 0
    //     if (s == 1 || n == 1) {
    //         cout << "NO\n";
    //     } else {
    //         cout << "YES\n";
    //         for (int i = 0; i < n - 1; ++i) {
    //             cout << 0 << " ";
    //         }
    //         cout << s << "\n";
    //     }
    //     return;
    // }
    //
    // 后续也能进行另一步判断
    if (k == 1 && s == 1) {
        cout << "NO\n";
        return;
    }

    // [0, k-1] ∪ [k+1, n]
    ll sum = (k - 1) * k / 2;
    s -= sum;
    if (s < 0) {
        cout << "NO\n";
        return;
    }

    const int m = n - k; // 需要让 m 个不等于 k (> 0) 的数总和为 s
    if (m == 0) {
        if (s != 0) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
            for (int i = 0; i < k; ++i) {
                cout << i << " ";
            }
            cout << "\n";
        }
        return;
    }

    if (s == k) {
        if (m == 1) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
            for (int i = 0; i < k; ++i) {
                cout << i << " ";
            }
            for (int i = 0; i < m - 2; ++i) {
                cout << 0 << " ";
            }
            cout << 1 << " " << s - 1 << "\n";
        }
    } else {
        cout << "YES\n";
        for (int i = 0; i < k; ++i) {
            cout << i << " ";
        }
        for (int i = 0; i < m - 1; ++i) {
            cout << 0 << " ";
        }
        cout << s << "\n";
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