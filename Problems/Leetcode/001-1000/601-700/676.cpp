#include <bits/stdc++.h>

using namespace std;
using ll = long long;

static constexpr int MOD = 1e9 + 7;

class Trie {
private:
    Trie* children[26] {};
    bool isEnd;

public:
    Trie() = default;

    void insert(const string& s) {
        Trie* node = this;
        for (char ch : s) {
            if (node->children[ch - 'a'] == nullptr) {
                node->children[ch - 'a'] = new Trie();
            }
            node = node->children[ch - 'a'];
        }
        node->isEnd = true;
    }

    bool search(const string& s) {
        function<bool(int, Trie*, int)> dfs = [&](int i, Trie* node, int diff) {
            if (i >= s.size()) {
                return diff == 1 && node->isEnd;
            }
            int j = s[i] - 'a';
            if (node->children[j] && dfs(i + 1, node->children[j], diff)) {
                return true;
            }
            if (diff == 0) {
                for (int k = 0; k < 26; ++k) {
                    if (k != j && node->children[k]) {
                        if (dfs(i + 1, node->children[k], 1)) {
                            return true;
                        }
                    }
                }
            }
            return false;
        };
        return dfs(0, this, 0);
    }
};

class MagicDictionary {
public:
    MagicDictionary() { trie = new Trie(); }

    void buildDict(const vector<string>& dictionary) {
        for (const string& s : dictionary) {
            trie->insert(s);
        }
    }

    bool search(const string& searchWord) { return trie->search(searchWord); }

private:
    Trie* trie;
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */

// Another Solution:
class MagicDictionary2 {
public:
    MagicDictionary2() { root = new Node(); }

    void buildDict(const vector<string>& dictionary) {
        for (const string& s : dictionary) {
            Node* node = root;
            for (char ch : s) {
                if (!node->children.contains(ch)) {
                    node->children[ch] = new Node();
                }
                node = node->children[ch];
            }
            node->isEnd = true;
        }
    }

    bool search(const string& searchWord) { return dfs(0, false, root, searchWord); }

private:
    struct Node {
        unordered_map<char, Node*> children;
        bool isEnd = false;
    };

    Node* root;

    bool dfs(int i, int diff, Node* node, const string& s) {
        if (i == s.size()) {
            return diff == 1 && node->isEnd;
        }
        for (auto& [ch, node] : node->children) {
            if (ch == s[i]) {
                if (dfs(i + 1, diff, node, s)) {
                    return true;
                }
            } else if (diff == 0) {
                if (dfs(i + 1, 1, node, s)) {
                    return true;
                }
            }
        }
        return false;
    }
};