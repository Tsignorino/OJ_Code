#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int mod = 1e9 + 7;

void solve() {
    int n, m, x;
    cin >> n >> m >> x;

    vector<int> status(n);
    x--;
    status[x] = 1;
    for (int i = 0; i < m; ++i) {
        int r;
        char ch;
        cin >> r >> ch;

        vector<int> tmp(n);
        for (int j = 0; j < n; ++j) {
            if (status[j]) {
                if (ch != '1') {
                    tmp[(j + r) % n] = 1;
                }
                if (ch != '0') {
                    tmp[(j - r + n) % n] = 1;
                }
            }
        }

        status = std::move(tmp);
    }

    cout << count(status.begin(), status.end(), 1) << "\n";
    for (int i = 0; i < n; ++i) {
        if (status[i]) {
            cout << i + 1 << " ";
        }
    }
    cout << "\n";

    /* Solution
        set<int> s {x};
        for (int i = 0; i < m; ++i) {
            int r;
            char ch;
            cin >> r >> ch;

            set<int> tmp = std::move(s);
            for (auto iter = tmp.begin(); iter != tmp.end(); iter++) {
                int v = *iter;

                int tmp1 = (v + r) % n;
                int tmp2 = (v - r + n) % n;
                int v1 = tmp1 == 0 ? n : tmp1;
                int v2 = tmp2 == 0 ? n : tmp2;

                if (ch == '0') {
                    s.insert(v1);
                }
                if (ch == '1') {
                    s.insert(v2);
                }
                if (ch == '?') {
                    s.insert(v1);
                    s.insert(v2);
                }
            }
        }

        cout << s.size() << "\n";
        vector<int> vec;
        for (auto iter = s.begin(); iter != s.end(); iter++) {
            vec.emplace_back(*iter);
        }
        sort(vec.begin(), vec.end());
        for (int& v : vec) {
            cout << v << " ";
        }
        cout << "\n";
    */
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int count;
    cin >> count;
    while (count--) {
        solve();
    }

    return 0;
}
