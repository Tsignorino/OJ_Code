#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;

    // f[ch][j]: ch: a, b, c, d, e; j: count(others) - count(ch)
    // ch -> string -> <cnt, len>
    vector<vector<pair<int, int>>> f(5, vector<pair<int, int>>(n));

    int ans = 0;
    string s;
    //* 枚举每个字符串
    for (int j = 0; j < n; ++j) {
        cin >> s;

        //* 枚举字符串中的每个字符
        int len = s.size();
        for (int k = 0; k < len; ++k) {
            f[s[k] - 'a'][j].first++;
        }
        for (int i = 0; i < 5; ++i) {
            f[i][j] = make_pair(len - f[i][j].first * 2, len);
        }
    }

    int cnt = 0; // cnt 表示以 ch 为当前字符能制作的有趣故事最大数量的字数
    for (int i = 0; i < 5; ++i) {
        sort(f[i].begin(), f[i].end());
        int r = 0;
        while (f[i][r].first <= 0) {
            cnt += f[i][r].second;
        }

        ans = max(ans, cnt);
    }

    cout << ans << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int count;
    cin >> count;
    while (count--) {
        solve();
    }

    return 0;
}

// void solve() {
//     int n;
//     cin >> n;
//     string s;
//     vector<vector<pair<int, int>>> f(5, vector<pair<int, int>>(n));
//     // f[ch][j]: ch -> a, b, c, d, e; j -> count(ch) - count(others)
//     int ans = 0;
//     for (int i = 0; i < 5; ++i) {
//         char ch = i + 'a';
//         int cnt = 0; // 表示以 ch 为当前字符能制作的有趣故事最大数量的字数
//         for (int j = 0; j < n; ++j) {
//             cin >> s;

//             int len = s.size();
//             for (int k = 0; k < len; ++k) {
//                 f[ch][j].first += s[k] == ch;
//             }
//             f[ch][j] = make_pair(len - f[ch][j].first, len);
//         }

//         sort(f[ch].begin(), f[ch].end());

//         int r = 0;
//         while (f[ch][r].first >= 0) {
//             cnt += f[ch][r].second;
//         }

//         ans = max(ans, cnt);
//     }

//     cout << ans << "\n";
// }
