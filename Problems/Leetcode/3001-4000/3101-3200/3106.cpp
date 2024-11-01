#include <bits/stdc++.h>

using namespace std;

class Solution {
public: // 2024_04_07
    string getSmallestString(string s, int k) {
        for (int i = 0; i < s.size(); ++i) {
            int dis = min(s[i] - 'a', 'z' - s[i] + 1);
            if (dis > k) {
                s[i] -= k;
                break;
            }
            s[i] = 'a';
            k -= dis;
        }
        return s;
    }

public: // 2024_07_27
    string getSmallestString_1(string s, int k) {
        // 字母 n 为分界点
        auto change = [&](char& ch) {
            if (ch >= 'n' && k >= 'z' - ch + 1) {
                k -= 'z' - ch + 1;
                ch = 'a';
            } else {
                int dis = min(k, ch - 'a');
                k -= dis;
                ch -= dis;
            }
        };

        for (char& ch : s) {
            change(ch);
        }
        return s;
    }

public:
    string getSmallestString_2(string s, int k) {
        for (int i = 0; i < s.size() && k > 0; ++i) {
            if (s[i] == 'a') {
                continue;
            }

            int diff;
            if (s[i] + k <= 'z') {
                diff = s[i] - 'a';
            } else {
                diff = min(s[i] - 'a', 'z' - s[i] + 1);
            }

            if (diff <= k) {
                s[i] = 'a';
                k -= diff;
            } else {
                s[i] -= k;
                return s;
            }
        }

        return s;
    }
};