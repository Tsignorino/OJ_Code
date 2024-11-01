
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int MX = 1e5;
bool is_prime[MX + 1];

auto Eratosthenes = []() {
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= MX; ++i) {
        is_prime[i] = true;
    }

    for (int i = 2; i * i <= MX; ++i) {
        if (is_prime[i]) {
            for (int j = i * i; j <= MX; j += i) {
                is_prime[j] = false;
            }
        }
    }

    return 0;
}();

class Solution {
public:
    long long countPaths(int n, vector<vector<int>>& edges) {
        /*
            合法路径中恰好只有一个节点的编号是质数
            可以枚举每个质数节点，从质数的邻居开始 DFS，统计在不经过质数的前提下，能访问到多少个非质数
            即，统计将该质数节点作为中间节点的合法路径的数目
            最后，统计从当前节点开始的合法路径数目，相加即可
            为减少 DFS 对同一个非质数连通块，可以记录每个非质数所在的连通块的大小
        */
        vector<vector<int>> g(n + 1);
        for (auto& e : edges) {
            int x = e[0], y = e[1];
            g[x].emplace_back(y);
            g[y].emplace_back(x);
        }

        vector<int> size(n + 1); // 记录连通块大小
        vector<int> nodes;
        function<void(int, int)> dfs = [&](int x, int parent) -> void {
            nodes.emplace_back(x);
            for (int y : g[x]) {
                if (y != parent && is_prime[y] == false) {
                    dfs(y, x);
                }
            }
        };

        long long ans = 0;
        for (int x = 1; x <= n; x++) {
            if (is_prime[x] == false) { // 跳过非质数
                continue;
            }

            int sum = 0;
            for (int y : g[x]) { // 以节点为中间节点的合法路径数目
                if (is_prime[y] == true) {
                    continue;
                }

                if (size[y] == 0) { // 未访问
                    nodes.clear();
                    dfs(y, x);
                    for (int z : nodes) {
                        size[z] = nodes.size();
                    }
                }

                ans += size[y] * 1LL * sum;
                sum += size[y];
            }

            ans += sum; // 从当前质数节点开始的合法路径数目
        }

        return ans;
    }
};
