#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int MOD = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<int> vec(n);
    vector<int> pos;
    for (int i = 0; i < n; ++i) {
        cin >> vec[i];
        if (vec[i] != -1) {
            pos.emplace_back(i);
        }
    }
    if (pos.empty()) {
        for (int i = 0; i < n; ++i) {
            cout << i % 2 + 1 << " \n"[i == n - 1];
        }
        return;
    }

    // 处理两边
    bool ok = true;
    for (int i = pos.front() - 1; i >= 0; --i, ok ^= 1) {
        vec[i] = (ok ? vec[i + 1] * 2 : vec[i + 1] / 2);
    }
    ok = true;
    for (int i = pos.back() + 1; i < n; ++i, ok ^= 1) {
        vec[i] = (ok ? vec[i - 1] * 2 : vec[i - 1] / 2);
    }

    for (int i = 1; i < pos.size(); ++i) {
        int l = pos[i - 1], r = pos[i];
        int x = vec[l], y = vec[r];
        int p = 31 - __builtin_clz(x), q = 31 - __builtin_clz(y); // 最高有效位的索引
        while (p >= 0 && q >= 0 && (x >> p & 1) == (y >> q & 1)) {
            p--, q--;
        }

        int diff = r - l - (p + q + 2);
        if (diff < 0 || diff % 2 > 0) {
            cout << -1 << "\n";
            return;
        }

        int k = l + 1;
        for (; p >= 0; --p, ++k) {
            vec[k] = vec[k - 1] / 2;
        }
        for (; q >= 0; --q, ++k) {
            vec[k] = vec[k - 1] * 2 | (y >> q & 1);
        }

        ok = true;
        for (; k < r; ++k, ok ^= 1) {
            vec[k] = (ok ? vec[k - 1] * 2 : vec[k - 1] / 2);
        }
    }

    for (int& v : vec) {
        cout << v << " ";
    }
    cout << "\n";
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
