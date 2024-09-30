#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int MOD = 1e9 + 7;

void solve() {
    string s, t;
    cin >> s >> t;

    int n = s.size();
    for (int w = 1; w < n; ++w) {
        vector<string> vec;
        for (int i = 0; i < n; ++i) {
            vec.emplace_back(s.substr(i, w));
            i += w - 1;
        }

        for (int c = 0; c < w; ++c) {
            string tmp;
            for (string& v : vec) {
                if (v.size() > c) {
                    tmp += v[c];
                }
            }

            // cout << tmp << "\n";
            if (tmp == t) {
                cout << "Yes\n";
                return;
            }
        }
    }

    cout << "No\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
