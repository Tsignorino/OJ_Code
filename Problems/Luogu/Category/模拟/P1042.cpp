#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int MOD = 1e9 + 7;

void solve() {
    string s, ss;
    while (cin >> s) {
        ss += s;
    }

    auto f = [&](int score) {
        int W = 0, L = 0;
        for (char ch : ss) {
            if (ch == 'E') {
                break;
            }

            (ch == 'W' ? W : L)++;
            if ((W >= score || L >= score) && abs(W - L) >= 2) {
                cout << W << ":" << L << "\n";
                W = 0, L = 0;
            }
        }
        cout << W << ":" << L << "\n";
    };

    f(11);
    cout << "\n";
    f(21);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(20);

    solve();

    return 0;
}
