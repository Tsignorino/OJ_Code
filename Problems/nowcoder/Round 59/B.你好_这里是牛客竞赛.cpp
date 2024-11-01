#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

map<string, string> mp {
    {"https://ac.nowcoder.com",  "Ac"      },
    {"ac.nowcoder.com",          "Ac"      },
    {"https://www.nowcoder.com", "Nowcoder"},
    {"www.nowcoder.com",         "Nowcoder"}
};

void solve() {
    string s;
    cin >> s;

    string res;
    for (int i = 0; i < s.size(); ++i) {
        res += s[i];
        if (i >= 2 && s[i - 2] == 'c' && s[i - 1] == 'o' && s[i] == 'm') {
            break;
        }
    }

    if (mp.contains(res)) {
        cout << mp[res] << "\n";
    } else {
        cout << "No\n";
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