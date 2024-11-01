#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    string s;
    cin >> s;

    int ans = 0;
    int pre = find(s.begin(), s.end(), 'A') - s.begin();
    for (int i = 1; i < 26; ++i) {
        int id = find(s.begin(), s.end(), 'A' + i) - s.begin();
        // cout << id << " ";
        ans += abs(id - pre);
        pre = id;
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}