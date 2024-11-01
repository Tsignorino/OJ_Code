#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<int> vec(n);
    for (int& v : vec) {
        cin >> v;
    }

    int q;
    cin >> q;
    while (q--) {
        string s;
        cin >> s;
        if (s.size() != n) {
            cout << "NO\n";
            continue;
        }

        map<char, int> mp1;
        map<int, char> mp2;
        int ok = 1;
        for (int i = 0; i < n; ++i) {
            if (mp1.contains(s[i]) && mp1[s[i]] != vec[i]) {
                ok = 0;
                break;
            }
            if (mp2.contains(vec[i]) && mp2[vec[i]] != s[i]) {
                ok = 0;
                break;
            }
            mp1[s[i]] = vec[i];
            mp2[vec[i]] = s[i];
        }

        cout << (ok ? "YES" : "NO") << "\n";
    }
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