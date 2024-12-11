// Date: 2024-12-11  星期三

#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#endif

using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;

    const int N = 495;
    vector<int> cnt(N);
    for (int i = 0; i < n; ++i) {
        int v;
        cin >> v;
        cnt[v % N]++;
    }

    auto work = [&]() {
        ll ans = 0;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < i; ++j) {
                if (i * j % N == 0) {
                    ans += cnt[i] * 1ll * cnt[j];
                }
            }
        }
        for (int i = 0; i < N; ++i) {
            if (i * i % N == 0) {
                ans += (cnt[i] - 1) * 1ll * cnt[i] / 2;
            }
        }
        return ans;
    };

    ll ans = work();
    for (int i = 0; i < N; ++i) {
        if (cnt[i]) {
            cnt[i]--;
            cnt[(i + 1) % N]++;
            ans = max(ans, work());
            cnt[(i + 1) % N]--;
            cnt[i]++;
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