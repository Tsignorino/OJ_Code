#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int n;
    cin >> n;

    vector<vector<string>> f(6);
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        f[s.size()].push_back(s);
    }

    ll ans = 0;
    for (int x = 1; x <= 5; x++) {
        for (int y = 1; y <= 5; y++) {
            if ((x + y) % 2 == 0) {
                array<int, 100> cnt {};

                int h = (x + y) / 2;
                for (string& a : f[x]) {
                    int s = 50;
                    for (int i = 0; i < x; i++) {
                        if (i < h) {
                            s += a[i] - '0';
                        } else {
                            s -= a[i] - '0';
                        }
                    }
                    cnt[s] += 1;
                }
                for (string& a : f[y]) {
                    int s = 50;
                    for (int i = 0; i < y; i++) {
                        if (x + i >= h) {
                            s += a[i] - '0';
                        } else {
                            s -= a[i] - '0';
                        }
                    }
                    ans += cnt[s];
                }
            }
        }
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}