#include <bits/stdc++.h>

using namespace std;

struct Node {
    Node* son[26] {};
    int minLen = INT_MAX;
    int i;
};

class Solution {
public:
    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        Node* root = new Node();
        for (int idx = 0; idx < wordsContainer.size(); ++idx) {
            string& s = wordsContainer[idx];
            int l = s.size();
            Node* cur = root;
            if (l < cur->minLen) {
                cur->minLen = l;
                cur->i = idx;
            }

            for (int i = l - 1; i >= 0; --i) {
                int ch = s[i] - 'a';
                if (cur->son[ch] == nullptr) {
                    cur->son[ch] = new Node();
                }

                cur = cur->son[ch];
                if (l < cur->minLen) {
                    cur->minLen = l;
                    cur->i = idx;
                }
            }
        }

        vector<int> ans(wordsQuery.size());
        for (string& s : wordsQuery) {
            Node* cur = root;
            for (int i = s.size() - 1; i >= 0 && cur->son[s[i] - 'a']; --i) {
                cur = cur->son[s[i] - 'a'];
            }
            ans.emplace_back(cur->i);
        }

        return ans;
    }
};

int main() {
    vector<string> wordsContainer {"abcd", "bcd", "xbcd"};
    vector<string> wordsQuery {"cd", "bcd", "xyz"};
    Solution sol;
    vector<int> res = sol.stringIndices(wordsContainer, wordsQuery);
    for (int& v : res) {
        cout << v << " ";
    }

    return 0;
}

// 超时，爆内存
class mySolution {
public:
    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        int m = wordsContainer.size(), n = wordsQuery.size();
        for (string& s : wordsContainer) {
            reverse(s.begin(), s.end());
        }

        vector<int> ans;
        for (int i = 0; i < n; ++i) {
            reverse(wordsQuery[i].begin(), wordsQuery[i].end());

            int len = 0;
            int id = 0;
            int size = 1e9;
            for (int j = 0; j < m; ++j) {
                string s = wordsContainer[j] + '#' + wordsQuery[i];

                int ss = s.size();
                vector<int> z(ss);
                int new_len = 0;
                for (int i = 1, l = 0, r = 0; i < ss; ++i) {
                    if (i <= r) {
                        z[i] = min(z[i - l], r - i + 1);
                    }
                    while (i + z[i] < ss && s[z[i]] == s[i + z[i]]) {
                        l = i, r = i + z[i]++;
                    }

                    if (i == wordsContainer[j].size() + 1) {
                        new_len = z[i];
                        break;
                    }
                }

                int k = wordsContainer[j].size();
                if (new_len > len || new_len == len && k < size) {
                    len = new_len;
                    id = j;
                    size = k;
                }
            }

            ans.emplace_back(id);
        }

        return ans;
    }
};
