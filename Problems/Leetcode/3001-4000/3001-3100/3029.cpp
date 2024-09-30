#include <bits/stdc++.h>

using namespace std;
using ll = long long;

/**

由于前一两天看的 KMP 算法，一看到字符串匹配，直接写了 KMP，不过也通过了

*/

class Solution {
private:
    vector<int> Z_func(string s) {
        int n = s.size();
        vector<int> z(n);

        for (int i = 1, l = 0, r = 0; i < n; ++i) {
            if (i <= r) {
                z[i] = min(z[i - l], r - i + 1);
            }
            while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
                l = i, r = i + z[i]++;
            }
        }
        return z;
    }

public:
    //* 贴板子的写法
    int minimumTimeToInitialState_1(string s, int k) {
        vector<int> z(Z_func(s));
        int n = s.size();
        int i = 1;
        while (i * k < n) {
            if (z[i * k] == n - i * k) {
                return i;
            } else {
                i++;
            }
        }
        return i;
    }

public:
    //* 在板子上修改
    int minimumTimeToInitialState(string s, int k) {
        int n = s.size();
        vector<int> z(n);
        for (int i = 1, l = 0, r = 0; i < n; ++i) {
            if (i <= r) {
                z[i] = min(z[i - l], r - i + 1);
            }

            while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
                l = i, r = i + z[i]++;
            }

            if (i % k == 0 && z[i] == n - i) {
                return i / k;
            }
        }

        return (n - 1) / k + 1;
    }
};