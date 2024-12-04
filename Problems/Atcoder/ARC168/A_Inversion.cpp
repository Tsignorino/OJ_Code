// Date: 2024-12-04  星期三

#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#endif

using namespace std;
using ll = long long;

vector<string> split(const string& s, char sep) {
    vector<string> result;
    string sub;
    istringstream subStream(s);
    while (getline(subStream, sub, sep)) {
        result.emplace_back(sub);
    }
    return result;
}

void solve() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    ll ans = 0;
    for (auto& v : split(s, '<')) {
        int len = v.size();
        ans += len * 1ll * (len + 1) / 2;
    }
    cout << ans << "\n";
}

/*
python:

_ = input()
print(sum((l := len(v)) * (l + 1) // 2 for v in input().split("<")))

*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}