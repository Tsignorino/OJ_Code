#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int mod = 1e9 + 7;

void solve() {
    int n, k;
    cin >> n >> k;
    
    map<int, int> mp;
    for (int i = 0; i < k; ++i) {
        int val;
        cin >> val;
        mp[val] ^= 1;
    }

    for (auto& [_, v] : mp) {
        n -= v;
    }
    cout << n << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
