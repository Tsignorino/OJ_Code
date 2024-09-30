#include <bits/stdc++.h>

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

void solve() {
    int n;
    cin >> n;

    vector<pair<int, int>> g;
    for (int v = 2; v <= n; ++v) {
        int u = 1;
        while (true) {
            int o = query(v, u);
            if (o == v) {
                break;
            }
            u = o;
        }
        g.emplace_back(u, v);
    }

    cout << "!";
    for (auto& [u, v] : g) {
        cout << format(" {} {}", u, v);
    }
    cout << endl;
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