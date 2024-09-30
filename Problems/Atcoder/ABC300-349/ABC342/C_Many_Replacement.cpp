#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int n;
    string s;
    cin >> n >> s;

    string t(26, ' ');
    iota(t.begin(), t.end(), 'a');

    int q;
    cin >> q;
    while (q--) {
        char c1, c2;
        cin >> c1 >> c2;

        replace(t.begin(), t.end(), c1, c2);
    }

    for (int i = 0; i < n; ++i) {
        s[i] = t[s[i] - 'a'];
    }
    cout << s << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}