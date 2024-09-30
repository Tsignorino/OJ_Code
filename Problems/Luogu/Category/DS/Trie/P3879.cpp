#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1e9 + 7;

class Trie {
private:
    Trie* children[26] {};
    bool isEnd;
    set<int> flag; // 标记第几个字符串

public:
    Trie() {}

    void insert(string& s, int i) {
        Trie* node = this;
        for (char ch : s) {
            if (node->children[ch - 'a'] == nullptr) {
                node->children[ch - 'a'] = new Trie();
            }
            node = node->children[ch - 'a'];
        }
        node->isEnd = true;
        node->flag.emplace(i);
    }

    void find(string& s) {
        Trie* node = this;
        for (char ch : s) {
            if (node->children[ch - 'a'] == nullptr) {
                cout << "\n";
                return;
            }
            node = node->children[ch - 'a'];
        }
        if (node->isEnd) {
            for (auto iter = node->flag.begin(); iter != node->flag.end(); ++iter) {
                cout << *iter << " "; // 题目识别不出来
            }
        }
        cout << "\n";
    }
};

void solve() {
    int n;
    cin >> n;

    Trie trie;
    for (int i = 1; i <= n; ++i) {
        int m;
        cin >> m;
        while (m--) {
            string s;
            cin >> s;
            trie.insert(s, i);
        }
    }

    int q;
    cin >> q;
    while (q--) {
        string s;
        cin >> s;
        trie.find(s);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}