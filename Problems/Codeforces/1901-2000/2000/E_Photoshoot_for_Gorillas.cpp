#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1e9 + 7;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;

    int q;
    cin >> q;
    vector<int> vec(q);
    for (int& v : vec) {
        cin >> v;
    }

    ranges::sort(vec, greater<>());

    /*
        统计每个块的计算次数
    */
    // （直接计算）
    vector<ll> cnt;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cnt.emplace_back((min(i, n - k) - max(0, i - k + 1) + 1) * 1ll * (min(j, m - k) - max(0, j - k + 1) + 1));
        }
    }

    ranges::sort(cnt, greater<>());

    ll ans = 0;
    for (int i = 0; i < q; ++i) {
        ans += vec[i] * cnt[i];
    }
    cout << ans << "\n";

    // （利用二维差分，二维前缀和）
    // vector diff(n + 2, vector<int>(m + 2));
    // for (int i = 0; i + k - 1 < n; ++i) {
    //     for (int j = 0; j + k - 1 < m; ++j) {
    //         diff[i][j]++;
    //         diff[i][j + k]--;
    //         diff[i + k][j]--;
    //         diff[i + k][j + k]++;
    //     }
    // }

    // map<int, ll> mp;
    // vector pre(n + 2, vector<int>(m + 2));
    // for (int i = 0; i < n + 1; ++i) {
    //     for (int j = 0; j < m + 1; ++j) {
    //         pre[i + 1][j + 1] = pre[i + 1][j] + pre[i][j + 1] - pre[i][j] + diff[i][j];
    //         mp[pre[i + 1][j + 1]]++;
    //     }
    // }

    // ll ans = 0;
    // int id = 0;
    // for (auto iter = mp.rbegin(); iter != mp.rend(); ++iter) {
    //     auto [v, c] = *iter;

    //     ll sum = 0;
    //     for (int i = id, cnt = 0; i < q && cnt < c; ++i, ++cnt) {
    //         sum += vec[i];
    //     }
    //     id = min(q * 1ll, id + c);

    //     ans += sum * v;
    // }
    // cout << ans << "\n";
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