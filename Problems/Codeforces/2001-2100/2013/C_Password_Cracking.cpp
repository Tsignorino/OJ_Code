#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

template <typename T = int32_t, typename... Args>
T query(Args... args) {
    cout << "? ";
    ((cout << args << ' '), ...) << endl;

    T t;
    cin >> t;
    return t;
}
template <typename... Args>
void print(Args... args) {
    cout << "! ";
    ((cout << args << ' '), ...) << endl;
}

void solve() {
    int n;
    cin >> n;

    string s;
    if (query('1')) {
        s.push_back('1');
    } else {
        s.push_back('0');
    }

    while (s.size() < n) {
        if (query(s + '1')) {
            s.push_back('1');
        } else if (query(s + '0')) {
            s.push_back('0');
        } else {
            break;
        }
    }
    while (s.size() < n) {
        if (query('1' + s)) {
            s.insert(s.begin(), '1');
        } else {
            s.insert(s.begin(), '0');
        }
    }

    print(s);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}