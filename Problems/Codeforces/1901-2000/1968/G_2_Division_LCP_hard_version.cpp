#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

vector<int> Z_Algo(string s) {
    int n = s.size();
    vector<int> z(n);
    // z[0] = n;
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r) {
            z[i] = min(z[i - l], r - i + 1);
        }
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
            l = i, r = i + z[i]++;
        }
    }
    return z;
}

void solve() {
    int n, l, r;
    string s;
    cin >> n >> l >> r >> s;

    vector<int> z = Z_Algo(s);
    auto get = [&](int k) {
        auto func = [&](int len) {
            for (int i = 1, j = len; i < k; ++i) {
                while (j < n && z[j] < len) {
                    j += 1;
                }
                if (j == n) {
                    return false;
                }
                j += len;
            }
            return true;
        };
        return *ranges::partition_point(views::iota(1, (n / k) + 1), func) - 1;
    };

    // process
    vector<int> f(n + 1);
    f[l] = get(l);
    f[r] = get(r);
    function<void(int, int)> divide = [&](int l, int r) -> void {
        if (f[l] == f[r]) {
            for (int i = l; i <= r; ++i) {
                f[i] = f[l];
            }
            return;
        }
        if (l + 1 == r) {
            return;
        }

        int m = l + (r - l) / 2;
        f[m] = get(m);
        divide(l, m);
        divide(m, r);
    };
    divide(l, r);

    for (int i = l; i <= r; ++i) {
        cout << f[i] << " ";
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