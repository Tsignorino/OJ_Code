#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    string s;
    cin >> s;

    int ok = isupper(s[0]) != 0;
    for (int i = 1; i < s.size(); ++i) {
        if (isupper(s[i])) {
            ok = 0;
        }
    }
    cout << (ok ? "Yes" : "No") << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}