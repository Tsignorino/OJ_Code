#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class NumArray {
private:
    vector<int> nums, tree;

    int prefixSum(int i) {
        int sum = 0;
        for (; i > 0; i &= i - 1) { // i -= i & -i
            sum += tree[i];
        }
        return sum;
    }

public:
    NumArray(vector<int>& nums) : nums(nums.size()), tree(nums.size() + 1) {
        for (int i = 0; i < nums.size(); ++i) {
            update(i, nums[i]);
        }
    }

    void update(int index, int val) {
        int delta = val - nums[index];
        nums[index] += val;
        for (int i = index + 1; i < tree.size(); i += i & -i) {
            tree[i] += delta;
        }
    }

    int sumRange(int left, int right) {
        return prefixSum(right + 1) - prefixSum(left);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */