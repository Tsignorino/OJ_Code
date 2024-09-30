#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int MOD = 1e9 + 7;

/*
    注意是寻找第一次出现的单词的首字母出现的位置（文本可能开头就含有空格）
*/
void solve() {
    string s;
    string passage;
    getline(cin, s);
    getline(cin, passage);

    for_each(s.begin(), s.end(), [&](char& ch) { ch |= 32; });
    transform(passage.begin(), passage.end(), passage.begin(), ::tolower);

    stringstream ss;
    string t;
    ss << passage;
    int cnt = 0;
    while (ss >> t) {
        cnt += t == s;
    }

    if (cnt == 0) {
        cout << -1 << "\n";
    } else {
        s = " " + s + " ";
        passage = " " + passage + " ";
        cout << format("{} {}", cnt, passage.find(s)) << "\n";
    }
}

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    // cout.precision(20);

    solve();

    return 0;
}
