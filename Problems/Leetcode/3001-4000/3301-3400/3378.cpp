#include <bits/stdc++.h>

#include "debug.h"

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

struct DSU { // Implement (union by size) + (path compression)
    vector<int> pa, _size;
    int block; // 记录连通块的数量

    DSU(int n) : pa(n), _size(n, 1), block(n) { iota(pa.begin(), pa.end(), 0); }

    // int find(int x) { return x == pa[x] ? x : pa[x] = find(pa[x]); }
    int find(int x) {
        int root = x;
        while (pa[root] != root) {
            root = pa[root];
        }
        while (pa[x] != root) {
            int tmp = pa[x];
            pa[x] = root;
            x = tmp;
        }
        return root;
    }

    void merge(int x, int y) {
        int px = find(x), py = find(y);
        if (px == py) {
            return;
        }
        if (_size[px] > _size[py]) {
            swap(px, py);
        }
        pa[px] = py;
        _size[py] += _size[px];
        block--;
    }

    bool same(int x, int y) { return find(x) == find(y); }

    int size(int x) { return _size[find(x)]; }
};

/*

https://leetcode.cn/problems/count-connected-components-in-lcm-graph/solutions/3013720/mei-ju-gcd-bing-cha-ji-pythonjavacgo-by-sq6vd

LCM(x, y) <= threshold，即 x * y / gcd(x, y) <= threshold

考虑枚举 gcd，把满足条件的点合并。

不能枚举 x（超时），而应该在 nums 中找到最小的 g 的倍数作为 x

题目保证所有元素互不相同

> 如果枚举的过程中，出现 g=2,x=4,y=8 的情况怎么办？此时 g != gcd(x,y)。

    虽然 GCD 对不上，但不影响正确性。如果此时 xy / g ≤ threshold 成立，那么 xy / GCD(x,y) ≤ threshold 也必然成立。

*/

class Solution {
public:
    int countComponents(vector<int>& nums, int threshold) {
        int n = nums.size();
        vector<int> idx(threshold + 1, -1);
        for (int i = 0; i < n; ++i) {
            if (nums[i] <= threshold) {
                idx[nums[i]] = i;
            }
        }

        DSU dsu(n);
        for (int g = 1; g <= threshold; ++g) {
            int ix = -1;
            for (int x = g; x <= threshold; x += g) {
                if (idx[x] >= 0) {
                    ix = x;
                    break;
                }
            }
            if (ix < 0) {
                continue;
            }
            for (int y = ix + g; y <= g * 1ll * threshold / ix; y += g) {
                if (idx[y] >= 0) {
                    dsu.merge(idx[ix], idx[y]);
                }
            }
        }
        return dsu.block;
    }
};

int main() {
    Solution sol;

    return 0;
}