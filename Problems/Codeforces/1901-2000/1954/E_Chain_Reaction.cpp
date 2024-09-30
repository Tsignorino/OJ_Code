#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int mod = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<int> vec(n);
    for (int& v : vec) {
        cin >> v;
    }

    vector<vector<int>> open(100010);
    for (int i = 0; i < n; ++i) {
        open[vec[i]].emplace_back(i);
    }

    vector<int> cnt(100010);
    vector<int> state(n, 1);
    int cur = 1;
    for (int i = 0; i <= 1e5; ++i) {
        int prev = -2, left = -1, right = -1;
        for (int& x : open[i]) {
            if (x == prev + 1) {
                right = x;
            } else {
                if (left != -1) {
                    if (left == 0 || state[left - 1] == 0) {
                        cur -= right == n - 1 || state[right + 1] == 0;
                    } else {
                        cur += right != n - 1 && state[right + 1];
                    }
                }

                left = right = x;
            }
            state[x] = 0;
        }

        if (left != -1) {
            if (left == 0 || state[left - 1] == 0) {
                cur -= right == n - 1 || state[right + 1] == 0;
            } else {
                cur += right != n - 1 && state[right + 1];
            }
        }

        cnt[i] = cur;
    }

    int maxV = *max_element(vec.begin(), vec.end());
    for (int k = 1; k <= maxV; ++k) {
        ll res = 0;
        for (int i = 0; i <= maxV; i += k) {
            res += cnt[i];
        }
        cout << res << " ";
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();

    return 0;
}
