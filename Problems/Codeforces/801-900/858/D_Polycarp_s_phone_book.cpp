#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int n;
    cin >> n;

    constexpr int N = 9;

    vector<string> vec(n);
    for (string& s : vec) {
        cin >> s;
    }

    map<pair<int, int>, int> mp; // 哈希值，长度 —— 序号
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < N; ++i) {
            int cur = 0;
            for (int j = i; j < N; ++j) {
                cur = cur * 10 + vec[k][j] - '0';

                auto [iter, ok] = mp.emplace(pair(cur, j - i + 1), k);
                if (!ok && iter->second != k) {
                    iter->second = -1;
                }
            }
        }
    }

    for (int k = 0; k < n; ++k) {
        int len = N + 1, id = 0;
        for (int i = 0; i < N; ++i) {
            int cur = 0;
            for (int j = i; j < N; ++j) {
                cur = cur * 10 + vec[k][j] - '0';
                int l = j - i + 1;
                if (l < len && mp[{cur, l}] == k) {
                    id = i, len = l;
                }
            }
        }
        cout << vec[k].substr(id, len) << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}