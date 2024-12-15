// Date: 2024-12-14  星期六

#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#endif

using namespace std;
using ll = long long;

void solve() {
    const int N = 5;

    vector<int> a(N);
    for (int& v : a) {
        cin >> v;
    }

    vector<int> ord(pow(2, N));
    iota(ord.begin(), ord.end(), 0);
    vector<pair<int, string>> ans;
    for (int& v : ord) {
        int sum = 0;
        string s;
        for (int i = 0; i < N; ++i) {
            if (v >> i & 1) {
                sum += a[i];
                s.push_back('A' + i);
            }
        }
        ans.emplace_back(sum, s);
    }

    ranges::sort(ans, [&](const auto& p, const auto& q) { return p.first > q.first || p.first == q.first && p.second < q.second; });

    for (auto& [_, s] : ans) {
        cout << s << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}