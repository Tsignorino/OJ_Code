#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1e9 + 7;

class Trie {
private:
    Trie* children[2] {};
    bool isEnd = false;
    int cnt = 0; // 统计信息节点数（处理暗号长度大于信息长度的情况）
    int cntEnd = 0; // 统计信息尾结点数量（处理暗号长度小于信息长度的情况）

public:
    Trie() = default;

    void insert(string& s) {
        Trie* node = this;
        for (char ch : s) {
            if (node->children[ch - '0'] == nullptr) {
                node->children[ch - '0'] = new Trie();
            }
            node = node->children[ch - '0'];
            node->cnt++;
        }
        node->isEnd = true;
        node->cntEnd++;
    }

    int startsWith(string& s) {
        Trie* node = this;
        int tot = 0;
        for (int i = 0; i < s.size(); ++i) {
            char ch = s[i];
            if (node->children[ch - '0'] == nullptr) {
                return tot;
            }
            node = node->children[ch - '0'];
            if (i < s.size() - 1 && node->isEnd) { // 避免尾字符重复统计
                tot += node->cntEnd;
            }
        }
        return tot + node->cnt; // 记录尾字符
    }
};

void solve() {
    int n, m;
    cin >> n >> m;

    Trie trie;
    for (int i = 0; i < n; ++i) {
        int q;
        cin >> q;
        string s(q, ' ');
        for (int k = 0; k < q; ++k) {
            cin >> s[k];
        }
        trie.insert(s);
    }

    for (int i = 0; i < m; ++i) {
        int q;
        cin >> q;
        string s(q, ' ');
        for (int k = 0; k < q; ++k) {
            cin >> s[k];
        }

        cout << trie.startsWith(s) << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
