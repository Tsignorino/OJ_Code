#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    string s, t;
    cin >> s >> t;

    vector<int> cnt(2);
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

    solve();

    return 0;
}
