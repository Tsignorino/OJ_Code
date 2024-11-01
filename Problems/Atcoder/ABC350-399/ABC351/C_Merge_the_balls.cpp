#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int n;
    cin >> n;

    stack<int> stk;
    for (int i = 0; i < n; ++i) {
        int v;
        cin >> v;

        while (!stk.empty() && v == stk.top()) {
            stk.pop();
            v++;
        }
        stk.emplace(v);
    }
    cout << stk.size() << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}