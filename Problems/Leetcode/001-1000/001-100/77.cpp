#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution_0 {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> vec;

        function<void(int)> dfs = [&](int i) -> void {
            int d = k - vec.size();
            if (i < d) {
                return;
            }

            if (d == 0) {
                ans.emplace_back(vec);
                return;
            }

            for (int j = i; j > -1; j--) {
                vec.emplace_back(j);
                dfs(j - 1);
                vec.pop_back();
            }
        };

        dfs(n);

        return ans;
    }
};

class Solution_1 {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> vec;

        function<void(int)> dfs = [&](int i) -> void {
            int d = k - vec.size();
            if (d == 0) {
                ans.emplace_back(vec);
                return;
            }

            // 选
            vec.emplace_back(i);
            dfs(i - 1);
            vec.pop_back();

            // 不选
            if (i > d) {
                dfs(i - 1);
            }
        };

        dfs(n);

        return ans;
    }
};

class Solution_2 {
public:
    //* 从 1~n 里面选择 k 个数
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;

        int i = (1 << k) - 1;
        int end = i << (n - k);
        while (i <= end) {
            vector<int> vec;
            for (int j = 0; j < n; ++j) {
                if (i & (1 << j)) {
                    vec.emplace_back(j + 1);
                }
            }

            ans.emplace_back(vec);

            int lowbit = i & -i;
            int x = i + lowbit;
            i = (i ^ x) / lowbit >> 2 | x;
        }

        return ans;
    }
};