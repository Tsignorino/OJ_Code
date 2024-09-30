#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int MOD = 1e9 + 7;

void solve() {
    string s, t;
    cin >> s >> t;

    vector<int> cnt(2); // ! array<int, 2> cnt {};
    for (char& ch : s) {
        cnt[ch & 1]++;
    }

    // 前缀函数
    vector<int> pi(t.size());
    int j = 0;
    for (int i = 1; i < t.size(); ++i) {
        char v = t[i];
        while (j > 0 && t[j] != v) {
            j = pi[j - 1];
        }
        if (t[j] == v) {
            j++;
        }
        pi[i] = j;
    }

    string ans;
    j = 0;
    while (cnt[t[j] & 1]) {
        ans.push_back(t[j]);
        cnt[t[j] & 1]--;
        j++;
        if (j == t.size()) {
            j = pi[j - 1];
        }
    }

    cout << ans << string(cnt[0], '0') << string(cnt[1], '1');
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(20);

    solve();

    return 0;
}
