#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numberOfSpecialChars(string word) {
        int lomask = 0, upmask = 0;
        int invalid = 0;
        for (char ch : word) {
            int v = ch & 31;
            if (ch & 32) {
                lomask |= 1 << v;
                if (upmask >> v & 1) { // 大写已经出现过
                    invalid |= 1 << v;
                }
            } else {
                upmask |= 1 << v;
            }
        }
        return __popcount(lomask & upmask & ~invalid);
    }
};

class Solution_2 {
public:
    int numberOfSpecialChars(string word) {
        int ans = 0;
        int status[27] {};
        for (char ch : word) {
            int v = ch & 31;
            if (islower(ch)) {
                if (status[v] == 0) {
                    status[v] = 1;
                } else if (status[v] == 2) {
                    status[v] = -1;
                    ans--;
                }
            } else {
                if (status[v] == 0) {
                    status[v] = -1;
                } else if (status[v] == 1) {
                    status[v] = 2;
                    ans++;
                }
            }
        }
        return ans;
    }
};

class mySolution {
public:
    int numberOfSpecialChars(string word) {
        vector<pair<int, int>> vec(26, {-1, -1});
        int n = word.size();
        for (int i = 0; i < n; ++i) {
            char ch = word[i];
            if (islower(ch)) {
                int& fi = vec[ch - 'a'].first;
                fi = fi == -1 ? i : max(fi, i);
            } else {
                int& se = vec[ch - 'A'].second;
                se = se == -1 ? i : min(se, i);
            }
        }

        int cnt = 0;
        for (auto& [i, j] : vec) {
            cnt += i != -1 && j != -1 && i < j;
        }
        return cnt;
    }
};