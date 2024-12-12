#include <bits/stdc++.h>

using namespace std;

namespace DoubleHashAndDP {
    class Solution {
    public:
        int minimumCost(string target, vector<string>& words, vector<int>& costs) {
            int n = target.length();

            const int MOD1 = 1'070'777'777;
            const int MOD2 = 1'000'000'007;
            mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
            const int BASE1 = uniform_int_distribution<>(8e8, 9e8)(rng);
            const int BASE2 = uniform_int_distribution<>(8e8, 9e8)(rng);
            vector<int> pow_base1(n + 1), pow_base2(n + 1);
            vector<int> pre_hash1(n + 1), pre_hash2(n + 1);
            pow_base1[0] = pow_base2[0] = 1;
            for (int i = 0; i < n; i++) {
                pow_base1[i + 1] = (long long) pow_base1[i] * BASE1 % MOD1;
                pow_base2[i + 1] = (long long) pow_base2[i] * BASE2 % MOD2;
                pre_hash1[i + 1] = ((long long) pre_hash1[i] * BASE1 + target[i]) % MOD1;
                pre_hash2[i + 1] = ((long long) pre_hash2[i] * BASE2 + target[i]) % MOD2;
            }

            // 计算 target[l] 到 target[r-1] 的哈希值
            auto sub_hash = [&](int l, int r) {
                long long h1 = ((pre_hash1[r] - (long long) pre_hash1[l] * pow_base1[r - l]) % MOD1 + MOD1) % MOD1;
                long long h2 = ((pre_hash2[r] - (long long) pre_hash2[l] * pow_base2[r - l]) % MOD2 + MOD2) % MOD2;
                return h1 << 32 | h2;
            };

            map<int, unordered_map<long long, int>> min_cost; // 长度 -> 哈希值 -> 最小成本
            for (int i = 0; i < words.size(); i++) {
                long long h1 = 0, h2 = 0;
                for (char b : words[i]) {
                    h1 = (h1 * BASE1 + b) % MOD1;
                    h2 = (h2 * BASE2 + b) % MOD2;
                }
                long long h = h1 << 32 | h2;
                int m = words[i].length();
                if (!min_cost[m].contains(h)) {
                    min_cost[m][h] = costs[i];
                } else {
                    min_cost[m][h] = min(min_cost[m][h], costs[i]);
                }
            }

            vector<int> f(n + 1, INT_MAX / 2);
            f[0] = 0;
            for (int i = 1; i <= n; i++) {
                for (auto& [len, mc] : min_cost) {
                    if (len > i) {
                        break;
                    }
                    auto it = mc.find(sub_hash(i - len, i));
                    if (it != mc.end()) {
                        f[i] = min(f[i], f[i - len] + it->second);
                    }
                }
            }
            return f[n] == INT_MAX / 2 ? -1 : f[n];
        }
    };
} // namespace DoubleHashAndDP

namespace {
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
} // namespace

int main() {
    Solution sol;

    string s = "r";
    vector<string> words = {"r", "r", "r", "r"};
    vector<int> costs = {1, 6, 3, 3};
    sol.minimumCost(s, words, costs);

    return 0;
}