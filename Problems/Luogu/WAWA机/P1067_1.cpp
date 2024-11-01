#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1e9 + 7;

string& p1(string& s, int v) { // 首项非零系数
    if (v == 1) {
        s += "";
    } else if (v == -1) {
        s += '-';
    } else {
        s += to_string(v);
    }
    return s;
}

string& p2(string& s, int v) { // 幂次
    s.push_back('x');
    if (v != 1) { // x 的一次方也不需要写
        s.push_back('^');
        s += to_string(v);
    }
    return s;
}

void solve() {
    int n;
    cin >> n;
    vector<int> vec(n + 1);
    for (int& v : vec) {
        cin >> v;
    }

    if (n == 0) { // 只有一项的情况
        cout << vec[0] << "\n";
        return;
    }

    string s;
    for (int i = 0; i < n + 1; ++i) {
        if (i == 0) { // 处理第一项
            if (vec[i]) {
                p1(s, vec[i]);
                p2(s, n);
            }
            continue;
        }
        if (i == n) { // 处理最后一项
            if (vec[i]) {
                if (vec[i] > 0) {
                    s.push_back('+');
                }
                s += to_string(vec[i]);
            }
            continue;
        }

        if (vec[i]) { // 处理中间项
            if (vec[i] > 0) {
                s.push_back('+');
            }
            p1(s, vec[i]);
            p2(s, n - i);
        }
    }
    cout << s << "\n";
}

void another_solve() {
    int n;
    cin >> n;

    for (int i = n; i >= 0; --i) {
        int val;
        cin >> val;

        //* 一元 n 次多项式，首项非 0
        if (val) { // 判零
            if (i != n && val > 0) { // 正数、非首项
                cout << '+';
            }

            if (abs(val) > 1 || i == 0) { // 非 ±1 or 末项
                cout << val;
            }

            if (val == -1 && i) { // -1、非末项
                cout << '-';
            }

            // 幂次
            if (i > 1) {
                cout << "x^" << i;
            }
            if (i == 1) {
                cout << 'x';
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
