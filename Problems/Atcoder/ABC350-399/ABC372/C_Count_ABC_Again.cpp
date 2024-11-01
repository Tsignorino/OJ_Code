#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int n, q;
    cin >> n >> q;

    string s;
    cin >> s;

    int ans = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (s.substr(i, 3) == "ABC") {
            ans++;
        }
    }

    auto check = [&](int i) {
        return s[i] == 'A' && s.substr(i, 3) == "ABC" || //
               s[i] == 'B' && i > 0 && s.substr(i - 1, 3) == "ABC" || //
               s[i] == 'C' && i > 1 && s.substr(i - 2, 3) == "ABC";
    };

    while (q--) {
        int i;
        char ch;
        cin >> i >> ch;
        i--;

        if (check(i)) {
            ans--;
        }
        s[i] = ch;
        if (check(i)) {
            ans++;
        }

        cout << ans << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}