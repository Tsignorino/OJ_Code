#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution {
public:
    vector<int> resultsArray(vector<vector<int>>& queries, int k) {
        int n = queries.size();
        vector<int> ans(n, -1);
        priority_queue<int> pq;
        for (int i = 0; i < n; ++i) {
            pq.emplace(abs(queries[i][0]) + abs(queries[i][1]));
            if (pq.size() > k) {
                pq.pop();
            }
            if (pq.size() == k) {
                ans[i] = pq.top();
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;

    return 0;
}