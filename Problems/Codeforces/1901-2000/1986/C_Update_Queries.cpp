#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

void solve() {
    int n, m;
    cin >> n >> m;

    string s;
    cin >> s;

    vector<int> vec(m);
    for (int& v : vec) {
        cin >> v;
    }

    string t;
    cin >> t;

    ranges::sort(vec);
    int id = unique(vec.begin(), vec.end()) - vec.begin();

    ranges::sort(t);

    for (int i = 0; i < id; ++i) {
        s[vec[i] - 1] = t[i];
    }
    cout << s << "\n";
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