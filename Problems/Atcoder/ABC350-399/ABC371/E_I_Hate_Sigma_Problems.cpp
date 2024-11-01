#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int n;
    cin >> n;

    vector<int> vec(n);
    for (int& v : vec) {
        cin >> v;
    }

    ll sum = 0;
    set<int> s;
    for (int i = 0; i < n; ++i) {
        s.emplace(vec[i]);
        sum += s.size();
    }

    vector<int> right(n, n);
    map<int, int> mp;
    for (int i = n - 1; i >= 0; --i) {
        if (mp.contains(vec[i])) {
            right[i] = mp[vec[i]];
        }
        mp[vec[i]] = i;
    }

    ll ans = sum;
    for (int i = 0; i < n; ++i) {
        sum -= right[i] - i;
        ans += sum;
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}