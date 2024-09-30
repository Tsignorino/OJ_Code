#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int MOD = 1e9 + 7;

// KMP + 栈（双端队列）

vector<int> nextArray(string& s) {
    int n = s.size();
    vector<int> nxt(n + 1);
    nxt[0] = -1;
    for (int i = 2, j = 0; i <= n; ++i) {
        while (j != -1 && s[i - 1] != s[j]) {
            j = nxt[j];
        }
        nxt[i] = ++j;
    }
    return nxt;
}

void solve() {
    string s, t;
    cin >> s >> t;

    auto nxt(nextArray(t));

    deque<pair<int, int>> q;
    int n = s.size(), m = t.size();
    int i = 0, j = 0;
    while (i < n) {
        if (s[i] == t[j]) {
            q.emplace_back(i, j);
            i++, j++;
        } else if (j > 0) {
            j = nxt[j];
        } else {
            q.emplace_back(i, -1);
            i++;
        }

        if (j == m) {
            for (int i = 0; i < m; ++i) {
                q.pop_back();
            }
            j = q.empty() ? 0 : q.back().second + 1;
        }
    }

    while (!q.empty()) {
        cout << s[q.front().first];
        q.pop_front();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
