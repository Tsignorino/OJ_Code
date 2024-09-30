#include <bits/stdc++.h>

using namespace std;
using ll = long long;

// https://leetcode.cn/problems/find-substring-with-given-hash-value/
/*
    * 倒序窗口：正序遍历会因为取模丢失信息

    * h(i, p, m) = (val(s[i]) * p^0 + val(s[i+1]) * p^1 + ... + val(s[i+k-1]) * p^(k-1)) mod m
    * h(i+1, p, m) = (val(s[i+1]) * p^0 + val(s[i+2]) * p^1 + ... + val(s[i+k]) * p^k) mod m

    * 因而可得，h(i, p, m) = (val(s[i]) * p^0) + p * h(i+1, p, m) - val(s[i+k] * p^k) mod m
*/
class Solution {
public:
    string subStrHash(string s, int power, int mod, int k, int hashValue) {
        int n = s.size();
        int total = 0, start = 1;
        int i = n - 1;

        // * s[i] - 'a' + 1  <==>  int(s[i] & 31)
        for (; i >= n - k; --i) {
            // 秦九韶算法计算哈希值
            total = (total * power + (s[i] - 'a' + 1)) % mod;
            start = start * (power % mod) % mod;
        }

        string ans;
        if (total == hashValue) {
            ans = s.substr(n - k, k);
        }

        for (; i >= 0; --i) {
            total = (total * power + (s[i] - 'a' + 1) + mod - start * (s[i + k] - 'a' + 1) % mod) % mod;
            if (total == hashValue) {
                ans = s.substr(i, k);
            }
        }

        return ans;
    }
};

int main() {
    Solution sol;

    string s = "fbxzaad";
    int power = 31, mod = 100, k = 3, hashValue = 32;

    sol.subStrHash(s, power, mod, k, hashValue);

    return 0;
}