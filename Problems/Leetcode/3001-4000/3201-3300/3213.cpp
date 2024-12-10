#include <bits/stdc++.h>

using namespace std;

struct Node {
    Node* son[26] {};
    Node* fail; // 当 cur.son[i] 不能匹配 target 中的某个字符时，cur.fail.son[i] 即为下一个待匹配节点（等于 root 则表示没有匹配）
    Node* last; // 后缀链接（suffix link），用来快速跳到一定是某个 words[k] 的最后一个字母的节点（等于 root 则表示没有）
    int len = 0;
    int cost = INT_MAX;
};

struct AhoCorasick {
    Node* root = new Node();

    void put(string& s, int cost) {
        auto cur = root;
        for (char b : s) {
            b -= 'a';
            if (cur->son[b] == nullptr) {
                cur->son[b] = new Node();
            }
            cur = cur->son[b];
        }
        cur->len = s.length();
        cur->cost = min(cur->cost, cost);
    }

    void build_fail() {
        root->fail = root->last = root;
        queue<Node*> q;
        for (auto& son : root->son) {
            if (son == nullptr) {
                son = root;
            } else {
                son->fail = son->last = root; // 第一层的失配指针，都指向根节点 ∅
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
                // 沿着 last 往上走，可以直接跳到一定是某个 words[k] 的最后一个字母的节点（如果跳到 root 表示没有匹配）
                son->last = son->fail->len ? son->fail : son->fail->last;
                q.push(son);
            }
        }
    }
};

class Solution {
public:
    int minimumCost(string target, vector<string>& words, vector<int>& costs) {
        AhoCorasick ac;
        for (int i = 0; i < words.size(); i++) {
            ac.put(words[i], costs[i]);
        }
        ac.build_fail();

        int n = target.length();
        vector<int> f(n + 1, INT_MAX / 2);
        f[0] = 0;
        auto cur = ac.root;
        for (int i = 1; i <= n; i++) {
            cur = cur->son[target[i - 1] - 'a']; // 如果没有匹配相当于移动到 fail 的 son[target[i-1]-'a']
            if (cur->len) { // 匹配到了一个尽可能长的 words[k]
                f[i] = min(f[i], f[i - cur->len] + cur->cost);
            }
            // 还可能匹配其余更短的 words[k]，要在 last 链上找
            for (auto match = cur->last; match != ac.root; match = match->last) {
                f[i] = min(f[i], f[i - match->len] + match->cost);
            }
        }
        return f[n] == INT_MAX / 2 ? -1 : f[n];
    }
};

int main() {
    Solution sol;

    string s = "r";
    vector<string> words = {"r", "r", "r", "r"};
    vector<int> costs = {1, 6, 3, 3};
    sol.minimumCost(s, words, costs);

    return 0;
}