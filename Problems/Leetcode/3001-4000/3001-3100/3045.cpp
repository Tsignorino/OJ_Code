#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution_0 {
    struct Node {
        Node* son[26] {};
        int cnt = 0;
    };

public:
    //* Z-algo + Trie
    // 对于两个字符串 s 和 t，s 的长度是 m
    // 如果 s 既是 t 的前缀，也是 t 的后缀，那么对于 t 来说，它的长为 m 的前后缀长度必须相等
    long long countPrefixSuffixPairs(vector<string>& words) {
        long long ans = 0;
        Node* root = new Node();
        for (string& t : words) {
            int n = t.length();

            vector<int> z(n);
            int l = 0, r = 0;
            for (int i = 1; i < n; i++) {
                if (i <= r) {
                    z[i] = min(z[i - l], r - i + 1);
                }
                while (i + z[i] < n && t[z[i]] == t[i + z[i]]) {
                    l = i;
                    r = i + z[i];
                    z[i]++;
                }
            }
            z[0] = n;

            auto cur = root;
            for (int i = 0; i < n; i++) {
                int c = t[i] - 'a';
                if (cur->son[c] == nullptr) {
                    cur->son[c] = new Node();
                }
                cur = cur->son[c];

                if (z[n - 1 - i] == i + 1) { // t 的长为 i+1 的前后缀相同
                    ans += cur->cnt;
                }
            }
            cur->cnt++;
        }

        return ans;
    }
};

class Solution_1 {
    struct Node {
        unordered_map<int, Node*> son;
        int cnt = 0;
    };

public:
    //* 把每一个字符串 s 视作 pair 列表
    // {(s[0], s[n-1]), (s[1], s[n-2]), ..., (s[i], s[n-1-i]), ..., (s[n-1], s[0])}
    long long countPrefixSuffixPairs(vector<string>& words) {
        long long ans = 0;
        Node* root = new Node();
        for (string& s : words) {
            int n = s.length();
            auto cur = root;
            for (int i = 0; i < n; i++) {
                int p = (int) (s[i] - 'a') << 5 | (s[n - 1 - i] - 'a');
                if (cur->son[p] == nullptr) {
                    cur->son[p] = new Node();
                }
                cur = cur->son[p];

                ans += cur->cnt;
            }
            cur->cnt++;
        }

        return ans;
    }
};