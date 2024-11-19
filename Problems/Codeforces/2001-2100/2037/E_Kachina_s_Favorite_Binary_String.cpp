#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#endif

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

template <typename T = int32_t, typename... Args>
T query(Args... args) {
    cout << "? ";
    ((cout << args << ' '), ...) << endl;

    T t;
    cin >> t;
    return t;
}
template <typename... Args>
void respond(Args... args) {
    cout << "! ";
    ((cout << args << ' '), ...) << endl;
}

void solve() {
    int n;
    cin >> n;

    int pre = query(1, n);
    if (pre == 0) {
        respond("IMPOSSIBLE");
        return;
    }

    string ans(n, '1');
    for (int i = n - 1; i > 1; --i) {
        int v = query(1, i);
        if (v == pre) {
            ans[i] = '0';
        } else if (v == 0) {
            while (pre--) {
                ans[--i] = '0';
            }
            respond(ans);
            return;
        }
        pre = v;
    }
    ans[0] = '0';
    respond(ans);
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