#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<string> vec(n);
    for (string& s : vec) {
        cin >> s;
    }

    for (int i = 0; i < n - 2; ++i) {
        if (vec[i] == "sweet" && vec[i + 1] == "sweet") {
            cout << "No\n";
            return;
        }
    }
    cout << "Yes\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}