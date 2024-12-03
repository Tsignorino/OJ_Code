// Date: 2024-12-03  星期二

#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#endif

using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    map<char, int> d;
    for (char ch : s) {
        d[ch]++;
    }

    vector<pair<char, int>> vec;
    for (auto& [ch, v] : d) {
        vec.emplace_back(ch, v);
    }

    ranges::sort(vec, [&](const auto& p, const auto& q) { return p.second < q.second; });

    s[find(s.begin(), s.end(), vec.front().first) - s.begin()] = vec.back().first;

    cout << s << "\n";
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