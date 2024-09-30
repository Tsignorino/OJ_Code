#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int mod = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), t(n);
    for (int& v : a) {
        cin >> v;
    }
    for (int& v : t) {
        cin >> v;
    }

    // 哨兵
    a.emplace_back(2e9);
    t.emplace_back(0);
    n++;

    vector<int> seq(n);
    iota(seq.begin(), seq.end(), 0);
    sort(seq.begin(), seq.end(), [&](int i, int j) { return a[i] < a[j]; });

    unsigned long long ans = 0;
    int last = 0;
    multiset<int> set;
    ll sum = 0;
    for (int i : seq) {
        while (a[i] > last && !set.empty()) {
            last++;
            auto iter = prev(set.end());
            sum -= *iter;
            set.erase(iter);
            ans += sum;
        }
        last = a[i];
        set.insert(t[i]);
        sum += t[i];
    }

    cout << ans << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();

    return 0;
}
