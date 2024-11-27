// Date: 2024-11-27  星期三

#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#endif

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

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
    string s;
    cin >> s;

    auto vec = split(s, ',');
    cout << stoll(vec.back()) - stoll(vec.front()) - 2 << "\n";

    // ll a, b;
    // scanf("%lld,%lld,...,%lld", &a, &b, &b);
    // cout << b - a - 2;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}