#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int mod = 1e9 + 7;

void solve() {
    string s;
    cin >> s;

    vector<int> vec(2);
    for (char& ch : s) {
        vec[(ch >> 5 & 1)]++;
    }

    if (vec[0] < vec[1]) {
        for (char& ch : s) {
            ch = tolower(ch);
        }
    } else {
        for (char& ch : s) {
            ch = toupper(ch);
        }
    }
    cout << s << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
