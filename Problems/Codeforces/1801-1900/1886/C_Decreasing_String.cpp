#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int mod = 1e9 + 7;

void solve() {
    string s;
    ll pos;
    cin >> s >> pos;

    int curLen = s.size();
    s.push_back('a' - 1); // 标记

    string ss;
    bool flag = pos <= curLen;

    for (char ch : s) {
        while (flag == false && ss.size() && ss.back() > ch) {
            pos -= curLen--;
            ss.pop_back();

            if (pos <= curLen) {
                flag = true;
            }
        }
        ss.push_back(ch);
    }

    cout << ss[pos - 1];
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
