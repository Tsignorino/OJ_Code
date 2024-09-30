#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;

static constexpr int MOD = 1e9 + 7;
static constexpr int base = 13131;

void solve() {
    int n;
    cin >> n;

    unordered_map<ull, set<int>> mp; // map 超时
    for (int i = 0; i < n; ++i) {
        vector<int> vec(6);
        for (int& v : vec) {
            cin >> v;
        }

        for (int j = 0; j < 6; ++j) {
            ull h = 0;
            for (int k = 0; k < 6; ++k) {
                h = h * base + vec[(j + k) % 6];
            }
            mp[h].emplace(i);
        }
        for (int j = 0; j < 6; ++j) {
            ull h = 0;
            for (int k = 0; k < 6; ++k) {
                h = h * base + vec[(j - k + 6) % 6];
            }
            mp[h].emplace(i);
        }
    }

    for (auto& [_, v] : mp) {
        if (v.size() >= 2) {
            cout << "Twin snowflakes found.\n";
            return;
        }
    }
    cout << "No two snowflakes are alike.";
}

void solve2() {
    int n;
    cin >> n;

    map<ull, int> mp;
    for (int i = 0; i < n; ++i) {
        vector<int> vec(6);
        for (int& v : vec) {
            cin >> v;
        }

        ull h = 0;
        for (int j = 0; j < 6; ++j) {
            h = h * base + vec[j];
        }

        for (int j = 0; j < 6; ++j) {
            ull h = 0;
            for (int k = 0; k < 6; ++k) {
                h = h * base + vec[(j + k) % 6];
            }
            if (mp.contains(h)) {
                cout << "Twin snowflakes found.";
                return;
            }
        }
        for (int j = 0; j < 6; ++j) {
            ull h = 0;
            for (int k = 0; k < 6; ++k) {
                h = h * base + vec[(j - k + 6) % 6];
            }
            if (mp.contains(h)) {
                cout << "Twin snowflakes found.";
                return;
            }
        }
        mp[h] = 1;
    }
    cout << "No two snowflakes are alike.";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
