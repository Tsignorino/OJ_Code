#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int mod = 1e9 + 7;

void solve() {
    string s;
    cin >> s;

    map<char, int> mp;
    int maxV = 0;
    for (char& ch : s) {
        mp[ch]++;
        maxV = max(maxV, mp[ch]);
    }

    map<int, int> mp2;
    for (auto& [_, cnt] : mp) {
        mp2[cnt]++;
    }

    for (int i = 1; i <= maxV; ++i) {
        if (mp2[i] != 0 && mp2[i] != 2) {
            cout << "No\n";
            return;
        }
    }
    cout << "Yes\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
