#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int MOD = 1e9 + 7;

void solve() {
    int x;
    cin >> x;

    vector<int> ans;
    while (x) {
        if (x % 2 == 0) {
            ans.emplace_back(0);
        } else if (x % 4 == 1) {
            ans.emplace_back(1);
            x--;
        } else {
            ans.emplace_back(-1);
            x++;
        }
        x /= 2;
    }

    cout << ans.size() << "\n";
    for (int& s : ans) {
        cout << s << " ";
    }
    cout << "\n";
}

void mysolve() {
    ll x;
    cin >> x;

    bitset<32> bits(x);
    vector<int> vec;
    bool flag = false;
    for (int i = 31; i >= 0; --i) {
        if (bits[i]) {
            flag = true;
        }
        if (flag) {
            vec.emplace_back(bits[i]);
        }
    }

    ranges::reverse(vec);

    int n = vec.size();
    int c = 0;
    for (int i = 0; i < n; ++i) {
        while (i < n && c) {
            vec[i]++;
            if (vec[i] == 2) {
                vec[i] = 0;
                i++;
            } else {
                c = 0;
                break;
            }
        }

        if (i + 1 < n && vec[i] & vec[i + 1]) {
            vec[i] = -1, vec[i + 1] = 0;
            i++;
            c = 1;
        }
    }

    if (c) {
        vec.emplace_back(1);
    }

    cout << vec.size() << "\n";
    for (int& v : vec) {
        cout << v << " ";
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(20);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}
