#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#endif

using namespace std;
using ll = long long;

static constexpr int MOD = 1'000'000'007;

class Trie {
private:
    Trie* children[26] {};
    int mlen = 1e6;

public:
    Trie() = default;

    void insert(string& s) {
        Trie* node = this;
        int cnt = ssize(s);
        for (char ch : s) {
            if (node->children[ch - 'a'] == nullptr) {
                node->children[ch - 'a'] = new Trie();
            }
            node = node->children[ch - 'a'];
            cnt--;
            node->mlen = min(node->mlen, cnt);
        }
    }

    int find(string& s) {
        Trie* node = this;
        int ans = ssize(s);
        int cnt = ssize(s);
        for (char ch : s) {
            if (node->children[ch - 'a'] == nullptr) {
                break;
            }
            node = node->children[ch - 'a'];
            cnt--;
            ans = min(ans, cnt + node->mlen);
        }
        return ans;
    }
};

void solve() {
    int n;
    cin >> n;

    Trie t;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;

        cout << t.find(s) << "\n";
        t.insert(s);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}