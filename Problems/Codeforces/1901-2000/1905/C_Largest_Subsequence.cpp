#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1e9 + 7;

void solve() {
    int n;
    string s;
    cin >> n >> s;

    // 单调栈求最大子序列
    stack<int> stk;
    string res;
    for (int i = 0; i < n; ++i) {
        while (!stk.empty() && s[i] > s[stk.top()]) {
            stk.pop();
            res.pop_back();
        }
        stk.emplace(i);
        res.push_back(s[i]);
    }

    for (char& ch : res) {
        s[stk.top()] = ch;
        stk.pop();
    }

    if (!is_sorted(s.begin(), s.end())) {
        cout << -1 << "\n";
    } else {
        cout << res.size() - count(res.begin(), res.end(), res[0]) << "\n";
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