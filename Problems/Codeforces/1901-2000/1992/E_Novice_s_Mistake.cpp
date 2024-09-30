#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;

    vector<pair<int, int>> vec;
    for (int a = 1; a <= 10000; ++a) {
        string s = to_string(n);
        int len = s.size();
        while (s.size() < 8) {
            s += s;
        }

        for (int b = a * len - 1; b >= a * len - 8; --b) {
            if (b >= 1 && b <= 10000) {
                int w = a * len - b;
                if (stoi(s.substr(0, w)) == n * a - b) {
                    vec.emplace_back(a, b);
                }
            }
        }
    }

    cout << vec.size() << "\n";
    for (auto& [a, b] : vec) {
        cout << format("{} {}", a, b) << "\n";
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