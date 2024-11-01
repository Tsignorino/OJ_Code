#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int n;
    string s;
    cin >> n >> s;

    for (int k = n; k > 0; --k) {
        vector<int> t(n), end(n + 1);
        for (int i = 0; i < n; ++i) {
            t[i] = s[i] - '0';
        }

        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            cnt -= end[i];
            t[i] ^= (cnt & 1);
            if (t[i] == 0) {
                if (i + k <= n) {
                    end[i + k]++;
                    cnt++;
                    t[i] = 1;
                } else {
                    break;
                }
            }
        }
        if (ranges::min(t) == 1) {
            cout << k << "\n";
            return;
        }
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