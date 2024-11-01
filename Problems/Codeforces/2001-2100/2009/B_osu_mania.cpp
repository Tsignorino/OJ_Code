#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int n;
    cin >> n;

    vector<int> ans;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;

        ans.emplace_back(s.find('#') + 1);
    }

    for (int& v : ans | views::reverse) {
        cout << v << " ";
    }
    cout << "\n";

    // vector<string> vec(n);
    // for (string& s : vec) {
    //     cin >> s;
    // }
    //
    // for (int i = n - 1; i >= 0; --i) {
    //     cout << vec[i].find('#') + 1 << " ";
    // }
    // cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}