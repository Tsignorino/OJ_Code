// Date: 2024-11-27  星期三

#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#endif

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int n, q;
    cin >> n >> q;

    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    int block = sqrt(n);
    int tot = (n + block - 1) / block;

    vector<int> L(tot + 1), R(tot + 1);
    for (int i = 1; i <= tot; ++i) {
        L[i] = (i - 1) * block + 1;
        R[i] = i * block;
    }
    R[tot] = n;

    vector<int> belong(n + 1);
    for (int i = 1; i <= n; ++i) {
        belong[i] = (i - 1) / block + 1;
    }

    vector<int> d(a);
    for (int i = 1; i <= tot; ++i) {
        sort(d.begin() + L[i], d.begin() + R[i] + 1);
    }

    vector<int> lazy(n + 1);
    while (q--) {
        char Op;
        int l, r, x;
        cin >> Op >> l >> r >> x;

        if (Op == 'A') {
            int ans = 0;
            if (belong[l] == belong[r]) {
                for (int i = l; i <= r; ++i) {
                    ans += a[i] + lazy[belong[l]] >= x;
                }
            } else {
                for (int i = l; i <= R[belong[l]]; ++i) {
                    ans += a[i] + lazy[belong[l]] >= x;
                }
                for (int i = L[belong[r]]; i <= r; ++i) {
                    ans += a[i] + lazy[belong[r]] >= x;
                }
                for (int i = belong[l] + 1; i <= belong[r] - 1; ++i) {
                    int lo = L[i] - 1, hi = R[i] + 1;
                    while (lo + 1 < hi) {
                        int mid = lo + (hi - lo) / 2;
                        if (d[mid] + lazy[i] >= x) {
                            hi = mid;
                        } else {
                            lo = mid;
                        }
                    }
                    ans += R[i] - lo;
                }
            }
            cout << ans << "\n";
        } else {
            if (belong[l] == belong[r]) {
                for (int i = l; i <= r; ++i) {
                    a[i] += x;
                }
                for (int i = L[belong[l]]; i <= R[belong[l]]; ++i) {
                    d[i] = a[i];
                }
                sort(d.begin() + L[belong[l]], d.begin() + R[belong[l]] + 1);
            } else {
                for (int i = l; i <= R[belong[l]]; ++i) {
                    a[i] += x;
                }
                for (int i = L[belong[l]]; i <= R[belong[l]]; ++i) {
                    d[i] = a[i];
                }
                sort(d.begin() + L[belong[l]], d.begin() + R[belong[l]] + 1);

                for (int i = L[belong[r]]; i <= r; ++i) {
                    a[i] += x;
                }
                for (int i = L[belong[r]]; i <= R[belong[r]]; ++i) {
                    d[i] = a[i];
                }
                sort(d.begin() + L[belong[r]], d.begin() + R[belong[r]] + 1);

                for (int i = belong[l] + 1; i <= belong[r] - 1; ++i) {
                    lazy[i] += x;
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}