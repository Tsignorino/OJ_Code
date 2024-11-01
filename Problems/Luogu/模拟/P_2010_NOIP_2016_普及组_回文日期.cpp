#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1e9 + 7;

vector<int> d {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

void solve() {
    int a, b;
    cin >> a >> b;

    int cnt = 0;
    for (int i = a / 10000; i <= b / 10000; i++) { // 枚举每一年
        // 年
        int year = i;

        // 月
        int month = year % 10 * 10 + year / 10 % 10;
        if (month < 1 || month > 12) {
            continue;
        }

        // 日
        int day = year / 100 % 10 * 10 + year / 1000;
        int limit = d[month - 1] + (month == 2 && (year % 400 == 0 || year % 100 != 0 && year % 4 == 0) ? 1 : 0);
        if (day < 1 || day > limit) {
            continue;
        }

        if (i == a / 10000 && month * 100 + day < a % 10000) {
            continue;
        }
        if (i == b / 10000 && month * 100 + day > b % 10000) {
            continue;
        }

        // cout << format("{} {:02d}{:02d}", year, month, day) << "\n";
        cnt++;
    }
    cout << cnt << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
