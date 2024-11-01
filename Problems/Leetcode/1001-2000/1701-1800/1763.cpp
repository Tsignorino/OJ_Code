#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution {
private:
    void f(const string& s, int l, int r, int& maxPos, int& maxLen) {
        if (l >= r) {
            return;
        }

        int lower = 0, upper = 0;
        for (int i = l; i <= r; ++i) {
            if (islower(s[i])) {
                lower |= 1 << (s[i] - 'a');
            } else {
                upper |= 1 << (s[i] - 'A');
            }
        }

        if (lower == upper) {
            if (r - l + 1 > maxLen) {
                maxPos = l;
                maxLen = r - l + 1;
            }
            return;
        }

        int pos = l;
        while (pos <= r) {
            l = pos;
            while (pos <= r && (lower & upper) & (1 << (tolower(s[pos]) - 'a'))) {
                ++pos;
            }

            f(s, l, pos - 1, maxPos, maxLen);

            pos++;
        }
    }

public:
    string longestNiceSubstring(string s) {
        //* 枚举 + 二进制
        // int n = s.size();
        // int maxPos = 0, maxLen = 0;
        // for (int i = 0; i < n; ++i) {
        //     int lower = 0, upper = 0;
        //     for (int j = i; j < n; ++j) {
        //         if (islower(s[j])) {
        //             lower |= 1 << (s[j] - 'a');
        //         } else {
        //             upper |= 1 << (s[j] - 'A');
        //         }

        //         if (lower == upper && j - i + 1 > maxLen) {
        //             maxPos = i;
        //             maxLen = j - i + 1;
        //         }
        //     }
        // }

        // return s.substr(maxPos, maxLen);

        //* 分治
        // int n = s.size(), maxPos = 0, maxLen = 0;
        // f(s, 0, n - 1, maxPos, maxLen);

        // return s.substr(maxPos, maxLen);

        //* 滑窗
        int n = s.size();
        int maxPos = 0, maxLen = 0;
        auto check = [&](int t) {
            vector<int> lowerCnt(26), upperCnt(26);
            int cnt = 0, total = 0;
            for (int l = 0, r = 0; r < n; ++r) {
                int idx = tolower(s[r]) - 'a';
                if (islower(s[r])) {
                    cnt += ++lowerCnt[idx] == 1 && upperCnt[idx] > 0;
                } else {
                    cnt += ++upperCnt[idx] == 1 && lowerCnt[idx] > 0;
                }

                total += (lowerCnt[idx] + upperCnt[idx]) == 1 ? 1 : 0;

                while (total > t) {
                    idx = tolower(s[l]) - 'a';
                    total -= (lowerCnt[idx] + upperCnt[idx]) == 1 ? 1 : 0;
                    if (islower(s[l])) {
                        cnt -= --lowerCnt[idx] == 0 && upperCnt[idx] > 0;
                    } else {
                        cnt -= --upperCnt[idx] == 0 && lowerCnt[idx] > 0;
                    }

                    l++;
                }

                if (cnt == t && r - l + 1 > maxLen) {
                    maxLen = r - l + 1;
                    maxPos = l;
                }
            }
        };

        int mask = 0;
        for (char& c : s) {
            mask |= 1 << (tolower(c) - 'a');
        }

        int m = __builtin_popcount(mask);
        for (int i = 1; i <= m; ++i) {
            check(i);
        }

        return s.substr(maxPos, maxLen);
    }
};

int main() {
    Solution sol;

    string s = "YazaAay";
    cout << sol.longestNiceSubstring(s);

    return 0;
}