#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        unordered_map<int, int> ump;
        for (int& v : changed) {
            ump[v]++;
        }

        int cnt = ump[0];
        if (cnt & 1) {
            return {};
        }
        ump.erase(0);

        vector<int> ans(cnt / 2);
        for (auto [key, _] : ump) {
            int x = key;
            if (x % 2 == 0 && ump.contains(x / 2)) { // !
                continue;
            }

            while (ump.contains(x)) {
                int cntX = ump[x];
                if (cntX > ump[x * 2]) {
                    return {};
                }

                ans.insert(ans.end(), cntX, x);
                if (cntX < ump[x * 2]) {
                    ump[x * 2] -= cntX;
                    x *= 2;
                } else {
                    x *= 4;
                }
            }
        }

        return ans;
    }
};

class mySolution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        ranges::sort(changed);

        vector<int> vec;
        queue<int> q;
        for (int& v : changed) {
            if (!q.empty() && (q.front() << 1) == v) {
                vec.emplace_back(q.front());
                q.pop();
            } else {
                q.emplace(v);
            }
        }

        return q.empty() ? vec : vector<int>();
    }
};

int main() {
    Solution sol;

    vector<int> vec {1, 3, 2, 4, 6, 8};
    sol.findOriginalArray(vec);

    return 0;
}