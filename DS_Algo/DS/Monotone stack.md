单调栈：
    存放下标更具有通用性，
    及时去除无用数据，保证栈中数据有序。

```cpp
vector<int> nums;

vector<int> ans(n);
stack<int> stk;

// 从左到右，更新为主，去除为辅，元素可重复
for(int i = 0; i < n; ++i) {
    while(!stk.empty() && `num` > nums[stk.top()]) {
        int j = stk.top();
        stk.pop();
        ans[j] = i - j;
    }
    stk.emplace(i);
}

// 从右到左，去除为主，更新为辅，元素无重复
for(int i = n - 1; i >= 0; --i) {
    while(!stk.empty() && `num` >= nums[stk.top()]) {
        stk.pop();
    }

    if(!stk.empty()) {
        // process:
        // ans[i] = stk.top() - i;
    }
    stk.emplace(i);
}
```
