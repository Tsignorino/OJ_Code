#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1e9 + 7;

void solve() {
    int n;
    cin >> n;

    vector<string> vec(n);
    for (string& v : vec) {
        cin >> v;
    }

    // 拼出最大的字符串
    ranges::sort(vec, [&](string& a, string& b) {
        for (int i = 0; i < min(a.size(), b.size()); ++i) {
            if (a[i] == b[i]) {
                continue;
            }
            return a[i] > b[i];
        }
        return a.front() > b.back();
    });

    string ans;
    for (string& v : vec) {
        // cout << v << " ";
        ans += v;
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}