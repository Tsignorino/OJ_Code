#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int MOD = 1e9 + 7;

void solve_() {
    int n;
    string s;
    cin >> n >> s;

    vector<int> vec(n);
    vec[0] = 1;
    s = ' ' + s;
    for (int i = 1; i < n; i++) {
        if (s[i] == '=') {
            vec[i] = vec[i - 1];
        }
        if (s[i] == 'R') {
            vec[i] = vec[i - 1] + 1;
        }
        if (s[i] == 'L') {
            vec[i] = 1;
            if (vec[i - 1] == 1) {
                vec[i - 1]++;
                for (int j = i - 1; j >= 1; j--) {
                    if (s[j] == '=') {
                        vec[j - 1] = vec[j];
                    } else if (s[j] == 'L' && vec[j - 1] == vec[j]) {
                        vec[j - 1]++;
                    } else {
                        break;
                    }
                }
            }
        }
    }

    for (int& v : vec) {
        cout << v << ' ';
    }
    cout << "\n";
}

void solve() {
    int n;
    string s;
    cin >> n >> s;

    vector<int> vec(n, 1);
    for (int i = 0; i < n; i++) {
        int cur = 1;
        for (int j = i; j < n - 1; j++) {
            if (s[j] == 'R') {
                break;
            }
            if (s[j] == 'L') {
                cur++;
            }
        }
        if (cur > vec[i]) {
            vec[i] = cur;
        }

        cur = 1;
        for (int j = i - 1; j >= 0; j--) {
            if (s[j] == 'L') {
                break;
            }
            if (s[j] == 'R') {
                cur++;
            }
        }
        if (cur > vec[i]) {
            vec[i] = cur;
        }
    }

    for (int& v : vec) {
        cout << v << ' ';
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(20);

    solve();

    return 0;
}
