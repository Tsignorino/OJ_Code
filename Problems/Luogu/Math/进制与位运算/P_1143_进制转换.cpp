#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

map<char, int> mp1;
map<int, char> mp2;
auto init = []() {
    for (char i = '0'; i <= '9'; ++i) {
        mp1[i] = i - '0', mp2[i - '0'] = i;
    }
    for (char i = 'A'; i <= 'F'; ++i) {
        mp1[i] = i - 'A' + 10, mp2[i - 'A' + 10] = i;
    }
    return 0;
}();

void solve() {
    int n, m;
    string s;
    cin >> n >> s >> m;

    int res = 0;
    for (char ch : s) {
        res = res * n + mp1[ch];
    }

    string ans;
    while (res) {
        int u = res / m, v = res % m;
        res = u;
        ans.push_back(mp2[v]);
    }
    ranges::reverse(ans);
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}