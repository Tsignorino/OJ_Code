#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1e9 + 7;

void solve() {
    int n, h;
    cin >> n >> h;
    vector<pair<int, int>> vec(n); // Guarantee: 升序且不相交
    for (auto& [l, r] : vec) {
        cin >> l >> r;
    }
    vec.insert(vec.begin(), pair(0, vec[0].first));

    int ans = 0, id = 1, end = vec[1].second + h;
    for (int i = 1; i <= n; ++i) {
        end += vec[i].first - vec[i - 1].second;
        for (int j = id + 1; j <= n && end > vec[j].first; ++j) {
            id = j;
            end += vec[j].second - vec[j].first;
        }
        ans = max(ans, end - vec[i].first);
        if (id == n) {
            break;
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