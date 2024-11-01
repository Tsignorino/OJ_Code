#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int mod = 1e9 + 7;

/*
    可以按照字符串寻找最后一个剩余的字符，再反过来对乘积取余更容易维护。
*/

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> vec(n);
    for (int& v : vec) {
        cin >> v;
    }

    string s;
    cin >> s;
    int p = 0;
    for (int i = 0; i < n - 1; ++i) {
        p += s[i] == 'L';
    }
    int mul = vec[p] % k; // the last element

    vector<int> res(n);
    res[n - 1] = mul;
    for (int i = n - 2, l = p, r = p; i >= 0; --i) {
        mul = mul * (s[i] == 'R' ? vec[++r] : vec[--l]) % k;
        res[i] = mul;
    }

    for (int& v : res) {
        cout << v << " ";
    }
    cout << "\n";
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