#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution {
private:
    string stringAdd(const string& s, int s1, int e1, int s2, int e2) {
        string tmp;
        for (int cur = 0; e1 >= s1 || e2 >= s2 || cur; cur /= 10) {
            if (e1 >= s1) {
                cur += s[e1--] - '0';
            }
            if (e2 >= s2) {
                cur += s[e2--] - '0';
            }
            tmp.push_back(cur % 10 + '0');
        }
        reverse(tmp.begin(), tmp.end());
        return tmp;
    }

    bool valid(const string& num, int s2, int e2) {
        int n = num.size();
        int s1 = 0, e1 = s2 - 1;
        while (e2 <= n - 1) {
            string tmp = stringAdd(num, s1, e1, s2, e2);
            int s3 = e2 + 1, e3 = e2 + tmp.size();
            if (e3 >= n || num.substr(s3, tmp.size()) != tmp) {
                return false;
            }
            if (e3 == n - 1) {
                return true;
            }
            s1 = s2, e1 = e2;
            s2 = s3, e2 = e3;
        }
        return false;
    }

public:
    bool isAdditiveNumber(string num) {
        int n = num.size();
        for (int i = 1; i < n - 1; ++i) {
            if (num[0] == '0' && i != 1) {
                break;
            }
            for (int j = i; j < n - 1; ++j) {
                if (num[i] == '0' && i != j) {
                    break;
                }
                if (valid(num, i, j)) {
                    return true;
                }
            }
        }
        return false;
    }
};