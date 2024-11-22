#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int mod = 1e9 + 7;

void solve() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    // vector<int> vec(27);
    // for (char& ch : s) {
    //     int v = ch - 'A' + 1;
    //     vec[v]++;
    // }

    // int cnt = 0;
    // for (int i = 1; i <= 26; ++i) {
    //     cnt += vec[i] >= i;
    // }

    int cnt = 0;
    for (int i = 0; i < 26; ++i) {
        cnt += count(s.begin(), s.end(), 'A' + i) >= i + 1;
    }

    cout << cnt << "\n";
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
