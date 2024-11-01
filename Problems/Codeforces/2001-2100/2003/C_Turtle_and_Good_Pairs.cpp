#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    vector<int> cnt(26);
    for (char& ch : s) {
        cnt[ch - 'a']++;
    }

    string ans;
    while (ans.size() < n) {
        for (int i = 0; i < 26; ++i) {
            if (cnt[i] > 0) {
                cnt[i]--;
                ans.push_back(i + 'a');
            }
        }
    }
    cout << ans << "\n";
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