#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int mod = 1e9 + 7;

void solve() {
    string s, t;
    cin >> s >> t;

    if (s == t) {
        cout << s << "\n" << t << "\n";
        return;
    }

    int n = s.size();
    int id = -1;
    for (int i = 0; i < n; ++i) {
        if (s[i] != t[i]) {
            if (s[i] >= t[i]) {
                swap(s[i], t[i]);
            }
            id = i;
            break;
        }
    }

    for (int i = id + 1; i < n; ++i) {
        if (s[i] < t[i]) {
            swap(s[i], t[i]);
        }
    }
    cout << s << "\n" << t << "\n";
}

void other_solve() {
    string s, t;
    cin >> s >> t;

    int n = s.size();
    bool flag = true;
    for (int i = 0; i < n; ++i) {
        if (s[i] > t[i]) {
            swap(s[i], t[i]);
        }

        // ºóÃæ£¬s[i] >= t[i]
        if (!flag) {
            swap(s[i], t[i]);
        }
        if (s[i] != t[i]) {
            flag = false;
        }
    }
    cout << s << "\n" << t << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int count;
    cin >> count;
    while (count--) {
        solve();
    }

    return 0;
}
