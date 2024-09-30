#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int mod = 1e9 + 7;

/*
    找到剩下的人中倒数第二个出价高的人的最高报价，二分查找最后一个人恰好大于该价格的报价
*/
void solve() {
    int n;
    cin >> n;

    vector<vector<int>> candidates(n + 1);
    vector<int> maxV(n + 1); // 每个人的最高报价
    for (int i = 1; i <= n; ++i) {
        int p, bid;
        cin >> p >> bid;
        candidates[p].emplace_back(bid);
        maxV[p] = bid;
    }

    map<int, int, greater<>> mp; // 记录最高报价对应的人
    for (int i = 1; i <= n; ++i) {
        if (maxV[i]) {
            mp[maxV[i]] = i;
        }
    }

    int q;
    cin >> q;
    while (q--) {
        int k;
        cin >> k;
        vector<int> vec(k);

        // 移除
        for (int& v : vec) {
            cin >> v;
            if (maxV[v]) {
                mp.erase(maxV[v]);
            }
        }

        if (mp.empty()) {
            cout << "0 0\n";
        } else if (mp.size() == 1) {
            int id = mp.begin()->second;
            cout << id << " " << candidates[id][0] << "\n";
        } else {
            int fi = mp.begin()->second;
            int se = next(mp.begin(), 1)->second;

            auto iter = ranges::upper_bound(candidates[fi], candidates[se].back());
            cout << fi << " " << *iter << "\n";
        }

        // 加入
        for (int& v : vec) {
            if (maxV[v]) {
                mp[maxV[v]] = v;
            }
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout.precision(20);

    solve();

    return 0;
}
