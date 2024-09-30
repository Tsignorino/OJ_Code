#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define mod 1e9 + 7

unordered_set<string> dict {"abc", "acb", "bac", "cba"};

void solve() {
    string s;
    cin >> s;

    cout << (ranges::find(dict, s) == dict.end() ? "NO\n" : "YES\n");
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int count;
    cin >> count;
    while (count--) {
        solve();
    }

    return 0;
}
