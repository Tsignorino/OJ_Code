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
    int n, k, _;
    string s;
    cin >> n >> k >> _ >> s;

    vector<int> z = Z_Algo(s);
    auto f = [&](int len) {
        for (int i = 1, j = len; i < k; i += 1) {
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
    cout << *ranges::partition_point(views::iota(1, (n / k) + 1), f) - 1 << "\n";
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