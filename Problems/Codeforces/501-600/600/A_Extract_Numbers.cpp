#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int MOD = 1e9 + 7;

void solve() {
    string s;
    cin >> s;

    int n = s.size();
    vector<string> words;
    for (int i = 0, j = -1; i <= n; i++) {
        if (i == n || s[i] == ',' || s[i] == ';') {
            words.emplace_back(s.substr(j + 1, i - j - 1));
            j = i;
        }
    }

    vector<string> ints, oths;
    for (auto s : words) {
        if (!s.empty() && all_of(s.begin(), s.end(), ::isdigit) && s[0] != '0' || s.size() == 1 && s[0] == '0') {
            ints.push_back(s);
        } else {
            oths.push_back(s);
        }
    }

    for (auto v : {ints, oths}) {
        if (v.empty()) {
            cout << "-\n";
        } else {
            cout << "\"";
            for (int i = 0; i < v.size(); i++) {
                cout << v[i] << ",\""[i == v.size() - 1];
            }
            cout << "\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
