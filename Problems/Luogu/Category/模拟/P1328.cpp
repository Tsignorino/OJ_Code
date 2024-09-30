#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int MOD = 1e9 + 7;

void solve() {
    int n, p, q;
    cin >> n >> p >> q;
    vector<int> v1(p), v2(q);
    for (int& v : v1) {
        cin >> v;
    }
    for (int& v : v2) {
        cin >> v;
    }

    int s1 = 0, s2 = 0;
    auto f = [&](int a, int b) {
        if (a == 0 && b == 1) {
            s2++;
        }

        if (a == 0 && b == 2) {
            s1++;
        }
        if (a == 1 && b == 2) {
            s2++;
        }

        if ((a == 0 || a == 1) && b == 3) {
            s1++;
        }
        if (a == 2 && b == 3) {
            s2++;
        }

        if ((a == 0 || a == 1) && b == 4) {
            s2++;
        }
        if ((a == 2 || a == 3) && b == 4) {
            s1++;
        }
    };

    for (int i = 0; i < n; ++i) {
        f(v1[i % p], v2[i % q]);
    }
    swap(s1, s2);
    for (int i = 0; i < n; ++i) {
        f(v2[i % q], v1[i % p]);
    }

    swap(s1, s2);
    cout << s1 << " " << s2 << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(20);

    solve();

    return 0;
}
