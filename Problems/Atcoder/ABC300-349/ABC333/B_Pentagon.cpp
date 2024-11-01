#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

const int d[] = {0, 1, 2, 2, 1};

void solve() {
    string s1, s2;
    cin >> s1 >> s2;

    ranges::sort(s1);
    ranges::sort(s2);

    if (d[s1[1] - s1[0]] == d[s2[1] - s2[0]]) {
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