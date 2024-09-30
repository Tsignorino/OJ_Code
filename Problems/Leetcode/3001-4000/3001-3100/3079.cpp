#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int sumOfEncryptedInt(vector<int>& nums) {
        int ans = 0;
        for (int& num : nums) {
            int maxV = 0, cnt = 0;
            while (num) {
                maxV = max(maxV, num % 10);
                num /= 10;
                cnt++;
            }
            ans += stoi(string(cnt, char(maxV + '0')));
        }
        return ans;
    }
};

int main() {
    Solution sol;

    vector<int> vec {10, 21, 31};
    cout << sol.sumOfEncryptedInt(vec);

    return 0;
}