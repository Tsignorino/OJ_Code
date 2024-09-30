#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class TreeAncestor {
    vector<vector<int>> pa;

public:
    TreeAncestor(int n, vector<int>& parent) {
        int len = bit_width(n * 1ull);
        pa.resize(n, vector<int>(len, -1));
        for (int i = 0; i < n; ++i) {
            pa[i][0] = parent[i];
        }
        for (int i = 1; i < len; ++i) {
            for (int x = 0; x < n; ++x) {
                int p = pa[x][i - 1];
                if (p != -1) {
                    pa[x][i] = pa[p][i - 1];
                }
            }
        }
    }

    int getKthAncestor(int node, int k) {
        int len = bit_width(k * 1ull);
        for (int i = 0; i < len; ++i) {
            if (k >> i & 1) {
                node = pa[node][i];
                if (node < 0) {
                    break;
                }
            }
        }
        return node;
    }

    int getKthAncestor2(int node, int k) {
        for (; k && ~node; k &= k - 1) {
            node = pa[node][__builtin_ctz(k)];
        }
        return node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */
