#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int> is_weak(n);
        for (auto& e : edges) {
            is_weak[e[1]] = true; // 不是冠军
        }

        int ans = -1;
        for (int i = 0; i < n; i++) {
            if (is_weak[i]) {
                continue;
            }
            if (ans != -1) {
                return -1; // 冠军只能有一个
            }
            ans = i;
        }
        return ans;
    }
};