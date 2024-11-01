#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution {
public:
    bool canMeasureWater(int x, int y, int target) {
        //* 栈模拟 DFS
        // stack<pair<int, int>> stk;
        // stk.emplace(0, 0);

        // auto hash_func = [](const pair<int, int>& P) {
        //     return hash<int>()(P.first) ^ hash<int>()(P.second);
        // };
        // unordered_set<pair<int, int>, decltype(hash_func)> seen(0, hash_func);

        // while (!stk.empty()) {
        //     if (seen.count(stk.top())) {
        //         stk.pop();
        //         continue;
        //     }
        //     seen.emplace(stk.top());

        //     auto [remain_x, remain_y] = stk.top();
        //     stk.pop();

        //     // 用水壶中的一或两个来盛放取得的 target 升水
        //     if (remain_x == target || remain_y == target || remain_x + remain_y == target) {
        //         return true;
        //     }

        //     stk.emplace(x, remain_y);
        //     stk.emplace(remain_x, y);
        //     stk.emplace(0, remain_y);
        //     stk.emplace(remain_x, 0);
        //     stk.emplace(remain_x - min(remain_x, y - remain_y), remain_y + min(remain_x, y - remain_y));
        //     stk.emplace(remain_x + min(remain_y, x - remain_x), remain_y - min(remain_y, x - remain_x));
        // }

        // return false;

        //* 裴蜀定理（贝祖定理）
        // 两个桶不可能同时有水且不满
        // 对于一个不满的桶，加水和倒水都是没有意义的
        // 因此每次操作只会给水的总量带来 x 或者 y 的变化量
        // ax + by = target
        if (x + y < target) {
            return false;
        }
        // 题目要求：1 <= x, y, target <= 1e6
        // if (x == 0 || y == 0) {
        //     return target == 0 || x + y == target;
        // }

        return target % gcd(x, y) == 0;
    }
};

int main() {
    Solution sol;

    int jug1Capacity = 3, jug2Capacity = 5, targetCapacity = 4;
    cout << sol.canMeasureWater(jug1Capacity, jug2Capacity, targetCapacity);

    return 0;
}