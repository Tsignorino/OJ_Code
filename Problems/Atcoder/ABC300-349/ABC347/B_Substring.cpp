#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    string s;
    cin >> s;

    int n = s.size();

    set<string> set;
    for (int l = 1; l <= n; ++l) {
        for (int i = 0; i < n; ++i) {
            set.insert(s.substr(i, l));
        }
    }

    cout << set.size() << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
