#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    string s;
    cin >> s;

    string ans;
    for (int i = 0; i < s.size(); ++i) {
        int n = ans.size();
        if (n >= 2 && ans[n - 1] == 'B' && ans[n - 2] == 'A' && s[i] == 'C') {
            ans.pop_back();
            ans.pop_back();
        } else {
            ans.push_back(s[i]);
        }
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}