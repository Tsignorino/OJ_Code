#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int n;
    cin >> n;

    vector<int> vec(n);
    for (int& v : vec) {
        cin >> v;
    }

    vector<int> pre(n);
    stack<int> stk;
    for (int i = 0; i < n; ++i) {
        while (!stk.empty() && vec[stk.top()] < vec[i]) {
            stk.pop();
        }
        if (!stk.empty()) {
            pre[i] = stk.top() + 1; // 后移一位
        }
        stk.emplace(i);
    }

    vector<int> d(n + 2);
    for (int i = 0; i < n; ++i) {
        d[pre[i]]++;
        d[i + 1]--;
    }

    vector<ll> pre2(n + 2);
    for (int i = 0; i < n; ++i) {
        pre2[i + 1] = pre2[i] + d[i];
    }

    for (int i = 2; i < n + 2; ++i) {
        cout << pre2[i] << " ";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}