#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

/*
    两个人一起构建序列；
    考虑最长递增前缀和最长递减后缀两个序列的长度：
        两个都是偶数，无论先手操作前缀/后缀，后手总能在同一个方向操作，后手获胜；
        一奇一偶，先手选择奇数长度的一个，回到两个偶数的局面，此时先手必胜；
        两个奇数，先手选择首元素更大的序列，总操作次数为奇数，先手必胜。
*/

void solve() {
    int n;
    cin >> n;
    vector<int> vec(n);
    for (int& v : vec) {
        cin >> v;
    }

    int i = 0, j = n - 1;
    while (i < n - 1 && vec[i + 1] > vec[i]) {
        i++;
    }
    while (j > 0 && vec[j - 1] > vec[j]) {
        j--;
    }

    cout << (((i + 1) & 1 | (n - j) & 1) ? "Alice" : "Bob") << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}