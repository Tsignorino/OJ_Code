#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int mod = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<int> v1(n);
    for (int i = 0; i < n; ++i) {
        cin >> v1[i];
    }

    int m;
    cin >> m;
    vector<int> v2(m);
    for (int i = 0; i < m; ++i) {
        cin >> v2[i];
    }

    int l;
    cin >> l;
    vector<int> v3(l);
    for (int i = 0; i < l; ++i) {
        cin >> v3[i];
    }

    set<int> s;
    for (int& n1 : v1) {
        for (int& n2 : v2) {
            for (int& n3 : v3) {
                s.emplace(n1 + n2 + n3);
            }
        }
    }

    int q;
    cin >> q;
    while (q--) {
        int num;
        cin >> num;
        cout << (s.contains(num) ? "Yes" : "No") << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
