#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Trie {
private:
    vector<Trie*> children;

public:
    Trie() : children(10) {}

    void insert(string word) {
        Trie* node = this;
        for (char ch : word) {
            ch -= '0';
            if (node->children[ch] == nullptr) {
                node->children[ch] = new Trie();
            }
            node = node->children[ch];
        }
    }

    int calc(string s) {
        Trie* node = this;
        int cnt = 0;
        for (char ch : s) {
            ch -= '0';

            if (node->children[ch] == nullptr) {
                return cnt;
            }
            node = node->children[ch];
            cnt++;
        }
        return cnt;
    }
};

class Solution {
public:
    int longestCommonPrefix_0(vector<int>& arr1, vector<int>& arr2) {
        if (arr1.size() > arr2.size()) {
            swap(arr1, arr2);
        }

        Trie trie;
        for (const int& v : arr2) {
            trie.insert(to_string(v));
        }

        int cnt = 0;
        for (const int& v : arr1) {
            cnt = max(cnt, trie.calc(to_string(v)));
        }

        return cnt;
    }

public:
    int longestCommonPrefix_1(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<string> set;
        for (const int& x : arr1) {
            string s = to_string(x);
            for (int i = 1; i <= s.length(); i++) {
                set.insert(s.substr(0, i));
            }
        }

        int ans = 0;
        for (const int& x : arr2) {
            string s = to_string(x);
            for (int i = 1; i <= s.length(); i++) {
                if (!set.contains(s.substr(0, i))) {
                    break;
                }
                ans = max(ans, i);
            }
        }
        return ans;
    }

public:
    int longestCommonPrefix_2(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<int> set;
        for (int x : arr1) {
            for (; x; x /= 10) {
                set.insert(x);
            }
        }

        int mx = 0;
        for (int x : arr2) {
            for (; x && !set.contains(x); x /= 10) {}
            mx = max(mx, x);
        }
        return mx ? to_string(mx).length() : 0;
    }
};