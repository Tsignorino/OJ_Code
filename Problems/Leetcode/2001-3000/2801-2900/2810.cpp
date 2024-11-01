#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string finalString(string s) {
        deque<char> q;
        bool flag = true;
        for (char& ch : s) {
            if (ch == 'i') {
                flag = !flag;
            } else if (flag) {
                q.push_back(ch);
            } else {
                q.push_front(ch);
            }
        }
        return flag ? string(q.begin(), q.end()) : string(q.rbegin(), q.rend());
    }

public:
    string finalString_1(string s) {
        string t;
        for (char& ch : s) {
            if (ch != 'i') {
                t.push_back(ch);
            } else {
                reverse(t.begin(), t.end());
            }
        }
        return t;
    }
};