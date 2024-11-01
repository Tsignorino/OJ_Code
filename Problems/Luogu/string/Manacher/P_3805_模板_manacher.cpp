#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1e9 + 7;

vector<int> manacher(string& s) {
    int n = s.size() * 2 + 1;
    string t(n, ' ');
    for (int i = 0, j = 0; i < n; ++i) {
        t[i] = i & 1 ? s[j++] : '#';
    }

    vector<int> vec(n);
    for (int i = 0, c = 0, r = 0; i < n; ++i) {
        int len = r > i ? min(vec[2 * c - i], r - i) : 1;
        while (i + len <= n && i - len >= 0 && t[i - len] == t[i + len]) {
            len++;
        }
        if (i + len > r) {
            r = i + len;
            c = i;
        }
        vec[i] = len;
    }
    return vec;
} // 返回值为真实长度 +1

void solve() {
    string s;
    cin >> s;

    cout << ranges::max(manacher(s)) - 1 << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}