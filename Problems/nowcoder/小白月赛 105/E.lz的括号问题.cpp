// Date: 2024-11-22  星期五

#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#endif

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    // 满足条件的数目等于总数减去还在栈里面的左括号数
    vector<int> ans(n);
    stack<int> stk;
    for (int i = 0, cnt = 0; i < s.size(); ++i) {
        if (s[i] == '(') {
            stk.push(cnt++);
        } else {
            if (stk.empty()) {
                cout << -1 << "\n";
                return;
            }
            ans[stk.top()] = n - stk.size();
            stk.pop();
        }
    }
    if (!stk.empty()) {
        cout << -1 << "\n";
        return;
    }
    for (int& v : ans) {
        cout << v << " ";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}