#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

const set<string> S {"A", "B", "C", "AB", "AC", "BC", "ABC"};

void solve() {
    string s;
    cin >> s;

    s.erase(unique(s.begin(), s.end()), s.end());

    if (S.contains(s)) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}