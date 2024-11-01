#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<ll> vec(n); // 记录值
    map<ll, int> mp; // 统计值的个数
    mp[0] = n;
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;

        a--;

        if (--mp[vec[a]] == 0) {
            mp.erase(vec[a]);
        }

        vec[a] += b;
        mp[vec[a]]++;

        cout << mp.size() << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}