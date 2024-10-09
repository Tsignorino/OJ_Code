#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int n;
    cin >> n;

    vector<int> vec(n);
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        for (int k = 0; k < n; ++k) {
            if (s[k] == 'o') {
                vec[i]++;
            }
        }
    }

    map<int, vector<int>> mp;
    for (int i = 0; i < n; ++i) {
        mp[vec[i]].emplace_back(i);
    }

    for (auto& [x, vec] : mp | views::reverse) {
        for (int& v : vec) {
            cout << v + 1 << " ";
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}