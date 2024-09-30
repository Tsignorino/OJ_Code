#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int mod = 1e9 + 7;

void solve_1() {
    string s;
    cin >> s;

    int cnt[26] {};
    for (auto& c : s) {
        cnt[c - 'a']++;
    }

    ll ans = 0;
    for (int i = 0; i < 26; i++) {
        ans += 1LL * cnt[i] * (cnt[i] - 1) / 2;
    }

    int n = s.size();
    ans = 1LL * n * (n - 1) / 2 - ans;
    if (ans < 1LL * n * (n - 1) / 2) {
        ans++;
    }
    cout << ans << "\n";
}

void solve_2() {
    string s;
    cin >> s;

    unordered_map<char, int> ump;
    for (char& v : s) {
        ump[v]++;
    }

    int n = s.size(), m = ump.size();
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += n - i - ump[s[i]];

        ump[s[i]]--;
        if (ump[s[i]] == 0) {
            ump.erase(s[i]);
        }
    }

    if (s.size() > m) {
        ans++;
    }

    cout << ans << "\n";
}

void solve() {
    string s;
    cin >> s;

    unordered_map<char, int> ump;
    for (char& v : s) {
        ump[v]++;
    }

    int n = s.size();
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += n - i - ump[s[i]];

        ump[s[i]]--;
        if (ump[s[i]] == 0) {
            ump.erase(s[i]);
        }
    }

    sort(s.begin(), s.end());
    auto iter = unique(s.begin(), s.end());
    s.erase(iter, s.end());
    if (s.size() < n) {
        ans++;
    }

    cout << ans << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve_2();

    return 0;
}
