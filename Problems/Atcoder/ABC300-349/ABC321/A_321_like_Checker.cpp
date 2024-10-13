#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    string s;
    cin >> s;

    char pre = s[0];
    for (int i = 1; i < s.size(); ++i) {
        if (s[i] >= pre) {
            cout << "No\n";
            return;
        }
        pre = s[i];
    }
    cout << "Yes\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}