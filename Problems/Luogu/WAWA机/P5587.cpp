#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int MOD = 1e9 + 7;

/*
    范文也有退格键
*/

void solve() {
    vector<string> vec;
    string s1, s2;
    while (getline(cin, s1), s1 != "EOF") {
        string s;
        for (char ch : s1) {
            if (ch == '<') {
                if (!s.empty()) {
                    s.pop_back();
                }
            } else {
                s.push_back(ch);
            }
        }
        vec.emplace_back(s);
    }

    int m = 0;
    int cnt = 0;
    while (getline(cin, s1), s1 != "EOF") {
        string s;
        for (char ch : s1) {
            if (ch == '<') {
                if (!s.empty()) {
                    s.pop_back();
                }
            } else {
                s.push_back(ch);
            }
        }

        for (int i = 0; i < min(s.size(), vec[m].size()); ++i) {
            cnt += vec[m][i] == s[i];
        }
        m++;
    }

    int t;
    cin >> t;
    cout << int(cnt * 60.0 / t + 0.5) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(20);

    solve();

    return 0;
}
