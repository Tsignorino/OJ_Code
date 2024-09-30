#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> nextArray(string s) {
        int n = s.size();
        if (n == 1) {
            return {-1};
        }

        vector<int> nxt(n);
        nxt[0] = -1; // nxt[1] = 0;

        int i = 2, j = 0; // i：当前下标，j：要比对的下标
        while (i < n) {
            if (s[i - 1] == s[j]) {
                nxt[i++] = ++j;
            } else {
                j > 0 ? j = nxt[j] : nxt[i++] = 0;
            }
        }
        return nxt;
    }

    int kmp(string s, string t) {
        int n = s.size(), m = t.size();
        vector<int> nxt(nextArray(t));

        int x = 0, y = 0;
        while (x < n && y < m) {
            if (s[x] != t[y]) {
                y == 0 ? x++ : y = nxt[y];
            } else {
                x++, y++;
            }
        }
        return y == m ? x - y : -1;
    }

public:
    int strStr(string s, string t) {
        //* BF
        // int n = s.size(), m = t.size();
        // for (int i = 0; i <= n - m; ++i) {
        //     int j = i, k = 0;
        //     while (k < m && s[j] == t[k]) {
        //         j++, k++;
        //     }
        //     if (k == m) {
        //         return i;
        //     }
        // }
        // return -1;

        //* KMP
        return kmp(s, t);
    }
};

int main() {
    Solution sol;

    string s("sadbutsad"), t("sad");
    cout << sol.strStr(s, t);

    return 0;
}