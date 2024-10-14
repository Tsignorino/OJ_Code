#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

map<string, int> mp {
    {"tourist",    3858},
    {"ksun48",     3679},
    {"Benq",       3658},
    {"Um_nik",     3648},
    {"apiad",      3638},
    {"Stonefeang", 3630},
    {"ecnerwala",  3613},
    {"mnbvmar",    3555},
    {"newbiedmy",  3516},
    {"semiexp",    3481},
};

void solve() {
    string s;
    cin >> s;

    cout << mp[s] << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}