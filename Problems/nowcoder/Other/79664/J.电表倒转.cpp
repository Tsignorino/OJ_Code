#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

/*
    https://ac.nowcoder.com/acm/contest/79664/J
*/

struct Item {
    char ch;
    ll cnt;
    int flag;
};

void solve() {
    int n;
    string s;
    cin >> n >> s;

    deque<Item> q;
    map<char, ll> mp;
    ll ans = 0;
    for (int k = 0; k < s.size(); k++) {
        if (q.size() >= 6) {
            ans++;

            char ch = q.front().ch;
            q.pop_front();
            if (--mp[ch] == 0) {
                mp.erase(ch);
            }
        }

        mp[s[k]]++;

        if (s[k] == 'A') {
            q.emplace_back('A', 2, 1);
        } else if (s[k] == 'B') {
            q.emplace_back('B', 3, 1);
        } else if (s[k] == 'C') {
            q.emplace_back('C', 1, 1);
        } else if (s[k] == 'D') {
            q.emplace_back('D', 2, 1);
        } else if (s[k] == 'E') {
            q.emplace_back('E', 1, 1);
        } else if (s[k] == 'F') {
            q.emplace_back('F', 0, 0);
        } else {
            q.emplace_back('G', 0, 0);
            for (int i = 0; i < q.size(); i++) {
                if (q[i].flag == 0) {
                    continue;
                }

                if (q[i].ch == 'A') {
                    ans++;
                } else if (q[i].ch == 'B') {
                    ans += 2;
                } else if (q[i].ch == 'C') {
                    s += "AB";
                } else if (q[i].ch == 'D') {
                    ans += mp.size();
                } else {
                    s += "F";
                }

                q[i].cnt = 0;
                q[i].flag = 0;
            }
        }

        if (mp.contains('F') && s[k] != 'F' && s[k] != 'G') {
            for (int i = 0; i < q.size(); i++) {
                q[i].cnt = max(q[i].cnt - mp['F'], 0ll);

                if (q[i].cnt == 0 && q[i].flag == 1) {
                    if (q[i].ch == 'A') {
                        ans++;
                    } else if (q[i].ch == 'B') {
                        ans += 2;
                    } else if (q[i].ch == 'C') {
                        s += "AB";
                    } else if (q[i].ch == 'D') {
                        ans += mp.size();
                    } else {
                        s += "F";
                    }
                    q[i].flag = 0;
                }
            }
        }
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}