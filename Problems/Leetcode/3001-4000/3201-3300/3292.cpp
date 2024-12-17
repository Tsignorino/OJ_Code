#include <bits/stdc++.h>

#include "debug.h"

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

// 从根到 node 的字符串，也是某个 words[i] 的前缀
struct Node {
    Node* son[26] {};
    Node* fail; // 当 cur.son[i] 不能匹配 target 中的某个字符时，cur.fail.son[i] 即为下一个待匹配节点（等于 root 则表示没有匹配）
    int len; // 从根到 node 的字符串的长度，也是 node 在 trie 中的深度

    Node(int len) : len(len) {}
};

struct AhoCorasick {
    Node* root = new Node(0);

    void insert(string& s) {
        auto cur = root;
        for (char b : s) {
            b -= 'a';
            if (cur->son[b] == nullptr) {
                cur->son[b] = new Node(cur->len + 1);
            }
            cur = cur->son[b];
        }
    }

    void build_fail() {
        root->fail = root;
        queue<Node*> q;
        for (auto& son : root->son) {
            if (son == nullptr) {
                son = root;
            } else {
                son->fail = root; // 第一层的失配指针，都指向根节点 ∅
                q.push(son);
            }
        }
        // BFS
        while (!q.empty()) {
            auto cur = q.front();
            q.pop();
            for (int i = 0; i < 26; i++) {
                auto& son = cur->son[i];
                if (son == nullptr) {
                    // 虚拟子节点 cur.son[i]，和 cur.fail.son[i] 是同一个
                    // 方便失配时直接跳到下一个可能匹配的位置（但不一定是某个 words[k] 的最后一个字母）
                    son = cur->fail->son[i];
                    continue;
                }
                son->fail = cur->fail->son[i]; // 计算失配位置
                q.push(son);
            }
        }
    }
};

class Solution {
public:
    int minValidStrings(vector<string>& words, string target) {
        // f[i] 表示 target 的长为 i 的前缀需要连接的最少字符串数，那么有 f[i] <= f[i+1]
        AhoCorasick ac;
        for (string& s : words) {
            ac.insert(s);
        }
        ac.build_fail();

        int n = target.size();
        vector<int> f(n + 1);
        auto cur = ac.root, root = ac.root;
        for (int i = 0; i < n; ++i) {
            cur = cur->son[target[i] - 'a'];
            if (cur == root) {
                return -1;
            }
            f[i + 1] = f[i - cur->len + 1] + 1;
        }
        return f[n];
    }
};

int main() {
    Solution sol;

    return 0;
}