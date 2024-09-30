#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n;
    string s;
    cin >> n >> s;

    //* 记录一下每个翻转的改变量和初始 total
    long long total = 0;
    vector<long long> vec;
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'L') {
            vec.emplace_back((n - i - 1) - i);
            total += i;
        } else {
            vec.emplace_back(i - (n - i - 1));
            total += n - i - 1;
        }
    }

    //* 降序排列
    sort(vec.rbegin(), vec.rend());

    for (int i = 0; i < n; ++i) {
        if (vec[i] > 0) {
            total += vec[i];
        }
        cout << total << " ";
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
