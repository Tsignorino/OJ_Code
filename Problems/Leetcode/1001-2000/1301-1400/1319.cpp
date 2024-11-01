#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        vector<int> pa(n), size(n, 1);
        iota(pa.begin(), pa.end(), 0);
        int cnt = 0; // 记录多余的线

        function<int(int)> find = [&](int x) -> int {
            return pa[x] == x ? x : pa[x] = find(pa[x]);
        };

        for (auto& vec : connections) {
            int px = find(vec[0]), py = find(vec[1]);
            if (px == py) {
                cnt++;
                continue;
            }
            if (size[px] > size[py]) {
                swap(px, py);
            }
            pa[px] = py;
            size[py] += size[px];
        }

        set<int> set;
        for (int i = 0; i < n; ++i) {
            set.emplace(find(i));
        }
        return cnt >= set.size() - 1 ? set.size() - 1 : -1;
    }
};

int main() {
    Solution sol;

    return 0;
}