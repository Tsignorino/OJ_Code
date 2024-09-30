## 动态规划



## 数学类

> 范德蒙恒等式:  $\sum{\binom{n}{i} \cdot \binom{m}{i}} = \binom{n+m}{k}$

| Link                                        | Explanation            |
| ------------------------------------------- | ---------------------- |
| https://ac.nowcoder.com/acm/contest/89860/F | 利用公式减少了一层枚举 |



## 技巧类

#### 种类区分（并查集，建图（dfs，bfs））

| Link                                              | Explanation      |
| ------------------------------------------------- | ---------------- |
| https://www.luogu.com.cn/problem/P2024            |                  |
| https://atcoder.jp/contests/abc327/tasks/abc327_d |                  |
| https://atcoder.jp/contests/abc373/tasks/abc373_d | 权重并查集（可） |



#### 恰好 -> 最多（最少）

| Link                                                                                         | Explanation |
| -------------------------------------------------------------------------------------------- | ----------- |
| https://leetcode.cn/problems/count-of-substrings-containing-every-vowel-and-k-consonants-ii/ |             |



#### 记录 `不同` 元素的位置
```cpp []
vector<int> right(n, n);
for (int i = n - 2; i >= 0; --i) {
    if (vec[i] != vec[i + 1]) {
        right[i] = i + 1;
    } else {
        right[i] = right[i + 1];
    }
}
```

| Link                                         | Explanation |
| -------------------------------------------- | ----------- |
| https://codeforces.com/contest/622/problem/C |             |



#### 记录 `相同` 元素的位置
```cpp []
vector<int> right(n, n);
map<int, int> mp;
for (int i = n - 1; i >= 0; --i) {
    if (mp.contains(vec[i])) {
        right[i] = mp[vec[i]];
    }
    mp[vec[i]] = i;
}
```

| Link                                              | Explanation |
| ------------------------------------------------- | ----------- |
| https://atcoder.jp/contests/abc371/tasks/abc371_e |             |



#### 折线法（括号序列）

| Link                                          | Explanation |
| --------------------------------------------- | ----------- |
| https://codeforces.com/contest/1976/problem/D |             |



#### 拆环成链

| Link                                              | Explanation |
| ------------------------------------------------- | ----------- |
| https://atcoder.jp/contests/abc338/tasks/abc338_e | 区间交集    |
