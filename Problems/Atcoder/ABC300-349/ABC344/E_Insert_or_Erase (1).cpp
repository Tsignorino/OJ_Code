#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int n;
    cin >> n;
    vector<int> vec(n);
    for (int i = 0; i < n; ++i) {
        cin >> vec[i];
    }

    map<int, int> nxt, pre;
    int head = vec[0];
    for (int i = 0; i < n - 1; ++i) {
        nxt[vec[i]] = vec[i + 1];
        pre[vec[i + 1]] = vec[i];
    }
    nxt[vec[n - 1]] = -1, pre[vec[0]] = -1;

    int q;
    cin >> q;
    while (q--) {
        int Op;
        cin >> Op;

        if (Op == 1) {
            int x, y;
            cin >> x >> y;
            nxt[y] = nxt[x];
            nxt[x] = y;
            pre[y] = x;
            if (nxt[y] != -1) {
                pre[nxt[y]] = y;
            }
        } else {
            int y;
            cin >> y;
            int x = pre[y], z = nxt[y];
            if (x != -1) {
                nxt[x] = z;
            }
            if (z != -1) {
                pre[z] = x;
            }
            nxt.erase(y), pre.erase(y); // ！
            if (head == y) {
                head = z;
            }
        }
    }

    int x = head;
    while (x != -1) {
        cout << x << " ";
        x = nxt[x];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}