#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int mod = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<int> vec(n);
    for (int& v : vec) {
        cin >> v;
    }
    string s;
    cin >> s;

    vector<int> left, right;
    for (int i = 0; i < n; ++i) {
        (s[i] == 'B' ? left : right).emplace_back(vec[i]);
    }

    sort(left.begin(), left.end());
    sort(right.begin(), right.end());

    int res = 1;
    for (int i = 0; i < left.size(); ++i) {
        if (left[i] < res) {
            cout << "NO\n";
            return;
        }
        res++;
    }
    for (int i = 0; i < right.size(); ++i) {
        if (right[i] > res) {
            cout << "NO\n";
            return;
        }
        res++;
    }

    cout << "YES\n";
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
