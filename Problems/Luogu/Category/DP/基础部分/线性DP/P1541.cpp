#include <bits/stdc++.h>

using namespace std;
using ll = long long;

/*
    乌龟棋：每张卡片用一次，且保证从起点到终点
*/

// int f[41][41][41][41] {}; // 本地环境栈区开不下，必须放在全局堆区

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> vec(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> vec[i];
    }
    vector<int> cards(5);
    for (int i = 0; i < m; ++i) {
        int val;
        cin >> val;
        cards[val]++;
    }

    // f[0][0][0][0] = vec[1];
    int f[41][41][41] {}; // 滚动数组优化
    f[0][0][0] = 0;
    for (int a = 0; a <= cards[1]; ++a) {
        for (int b = 0; b <= cards[2]; ++b) {
            for (int c = 0; c <= cards[3]; ++c) {
                for (int d = 0; d <= cards[4]; ++d) {
                    // int dis = a + 2 * b + 3 * c + 4 * d + 1;
                    // if (a) {
                    //     f[a][b][c][d] = max(f[a][b][c][d], f[a - 1][b][c][d] + vec[dis]);
                    // }
                    int t = vec[a + 2 * b + 3 * c + 4 * d + 1];
                    if (b) {
                        f[b][c][d] = max(f[b][c][d], f[b - 1][c][d]);
                    }
                    if (c) {
                        f[b][c][d] = max(f[b][c][d], f[b][c - 1][d]);
                    }
                    if (d) {
                        f[b][c][d] = max(f[b][c][d], f[b][c][d - 1]);
                    }
                    f[b][c][d] += t;
                }
            }
        }
    }
    // cout << f[cards[1]][cards[2]][cards[3]][cards[4]] << "\n";
    cout << f[cards[2]][cards[3]][cards[4]] << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}