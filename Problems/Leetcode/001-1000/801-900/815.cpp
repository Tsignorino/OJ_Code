#include <bits/stdc++.h>

using namespace std;
using ll = long long;

/*
    > 哈希表记录车站下标
    > 特殊情况的判断（不包含对应站点，起点终点一致）
    > 已访问车站的标记（访问完后直接把 routes 清空，避免之后循环体里面的 contains 访问）
*/

class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int s, int t) {
        map<int, vector<int>> ids;
        for (int i = 0; i < routes.size(); ++i) {
            for (int x : routes[i]) {
                ids[x].emplace_back(i);
            }
        }

        if (!ids.contains(s) || !ids.contains(t)) { // !
            return s == t ? 0 : -1;
        }

        map<int, int> dis;
        dis[s] = 0;

        queue<int> q;
        q.emplace(s);
        while (!q.empty()) {
            int x = q.front();
            q.pop();

            for (int i : ids[x]) {
                for (int y : routes[i]) {
                    if (!dis.contains(y)) {
                        dis[y] = dis[x] + 1;
                        q.emplace(y);
                    }
                }
                routes[i].clear(); // !
            }
        }
        return dis.contains(t) ? dis[t] : -1;
    }
};

int main() {
    Solution sol;

    return 0;
}