#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

/*
    https://ac.nowcoder.com/acm/contest/88455/E
*/

void solve() {
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> vec(n);
    for (int i = 0; i < n; ++i) {
        cin >> vec[i].first;
    }
    for (int i = 0; i < n; ++i) {
        cin >> vec[i].second;
    }

    ranges::sort(vec, [&](pair<int, int>& p, pair<int, int>& q) { return p.second < q.second; });

    vector<int> res;
    int cnt = 0;
    int end = vec[0].first + vec[0].second;
    for (int i = 0; i < n; ++i) {
        if (end >= vec[i].second) {
            cnt++;
        } else {
            res.emplace_back(cnt);
            cnt = 1;
        }
        end = max(end, vec[i].first + vec[i].second);
    }
    res.emplace_back(cnt);

    ranges::sort(res, greater<>());

    ll sum = 0;
    for (int i = 0; i < min(m, (int) res.size()); ++i) {
        sum += res[i];
    }
    cout << sum << "\n";
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