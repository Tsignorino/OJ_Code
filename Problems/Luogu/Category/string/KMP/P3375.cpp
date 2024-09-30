#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int MOD = 1e9 + 7;

vector<int> nxtArray(string& t) {
    int m = t.size() + 1;
    vector<int> nxt(m);
    nxt[0] = -1;
    // nxt[1] = 0;
    int i = 2, j = 0;
    while (i < m) {
        if (t[i - 1] == t[j]) {
            nxt[i++] = ++j;
        } else if (j > 0) {
            j = nxt[j];
        } else {
            nxt[i++] = 0;
        }
    }
    return nxt;
}

void solve() {
    string s, t;
    cin >> s >> t;

    int n = s.size(), m = t.size();
    vector<int> nxt = nxtArray(t);
    int i = 0, j = 0;
    while (i < n) {
        if (s[i] == t[j]) {
            i++, j++;
        } else if (j > 0) {
            j = nxt[j];
        } else {
            i++;
        }

        if (j == m) {
            cout << i - j + 1 << "\n";
            j = nxt[j]; // !
        }
    }

    for (int i = 1; i < nxt.size(); ++i) {
        cout << nxt[i] << " ";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
