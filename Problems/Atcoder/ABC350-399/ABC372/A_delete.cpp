#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    string s;
    cin >> s;

    int n = s.size();
    for (int i = 0; i < n; ++i) {
        if (s[i] == '.') {
            continue;
        }
        cout << s[i];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}