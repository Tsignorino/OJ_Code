#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int n, q;
    cin >> n >> q;

    vector<pair<int, int>> vec(n);
    for (int i = 0; i < n; ++i) {
        vec[i] = {n - i, 0};
    }

    while (q--) {
        int Op;
        cin >> Op;

        if (Op == 1) {
            char ch;
            cin >> ch;

            auto [x, y] = vec.back();
            if (ch == 'U') {
                y++;
            } else if (ch == 'D') {
                y--;
            } else if (ch == 'L') {
                x--;
            } else {
                x++;
            }
            vec.emplace_back(x, y);
        } else {
            int id;
            cin >> id;

            auto [x, y] = vec[vec.size() - id];
            cout << x << " " << y << "\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}