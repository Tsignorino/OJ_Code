#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int n, k, q;
    cin >> n >> k >> q;

    vector<int> vec(n);
    for (int i = 0; i < n; ++i) {
        cin >> vec[i];
        vec[i] -= i;
    }

    multiset<int> s; // 记录频次
    map<int, int> freq; // 数 - 频次
    for (int i = 0; i < k; ++i) {
        s.extract(freq[vec[i]]);
        freq[vec[i]]++;
        s.emplace(freq[vec[i]]);
    }

    vector<int> res {k - *s.rbegin()};
    for (int i = k; i < n; ++i) {
        s.extract(freq[vec[i]]);
        freq[vec[i]]++;
        s.emplace(freq[vec[i]]);

        s.extract(freq[vec[i - k]]);
        freq[vec[i - k]]--;
        s.emplace(freq[vec[i - k]]);

        res.emplace_back(k - *s.rbegin());
    }

    while (q--) {
        int l, r;
        cin >> l >> r;

        cout << res[l - 1] << "\n";
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