## 动态规划

#### 思维题

| Link                                   | Explanation |
| -------------------------------------- | ----------- |
| https://www.luogu.com.cn/problem/P4310 | 二进制      |


## 数学类

#### 范德蒙恒等式:  $\sum{\binom{n}{i} \cdot \binom{m}{i}} = \binom{n+m}{k}$

| Link                                        | Explanation            |
| ------------------------------------------- | ---------------------- |
| https://ac.nowcoder.com/acm/contest/89860/F | 利用公式减少了一层枚举 |



#### GCD 问题

| Link                                                  | Explanation          |
| ----------------------------------------------------- | -------------------- |
| https://leetcode.cn/problems/sorted-gcd-pair-queries/ | 倒序枚举，容斥，二分 |



#### 整除问题

| Link                                              | Explanation |
| ------------------------------------------------- | ----------- |
| https://atcoder.jp/contests/abc356/tasks/abc356_e | 注意去重    |


## 图论

#### 多源 BFS

> 开始就把所有源头压入队列，其余同单源 BFS，借助 dis 判断重复访问

| Link                                              | Explanation |
| ------------------------------------------------- | ----------- |
| https://atcoder.jp/contests/abc383/tasks/abc383_c |             |


## 数据结构

## 线段树

| Link                                            | Explanation            |
| ----------------------------------------------- | ---------------------- |
| https://www.luogu.com.cn/problem/solution/P1438 | 利用线段树维护差分序列 |



## 思维技巧类

#### 杂项

| Link                                                                                         | Explanation                   |
| -------------------------------------------------------------------------------------------- | ----------------------------- |
| https://atcoder.jp/contests/abc379/tasks/abc379_c                                            | 考虑每次操作给 sum 带来的影响 |
| https://codeforces.com/contest/1976/problem/D                                                | 折线法（括号序列）            |
| https://leetcode.cn/problems/count-of-substrings-containing-every-vowel-and-k-consonants-ii/ | 恰好 -> 最多（最少）          |
| https://codeforces.com/contest/2027/problem/C                                                | 图的建模                      |


#### 换位置  Pi =  P_(pi)

| Link                                              | Explanation |
| ------------------------------------------------- | ----------- |
| https://atcoder.jp/contests/abc367/tasks/abc367_e | B = A_(xi)  |
| https://atcoder.jp/contests/abc371/tasks/abc371_g |             |
| https://atcoder.jp/contests/abc377/tasks/abc377_e |             |


#### 种类区分（并查集，建图（dfs，bfs））

| Link                                              | Explanation      |
| ------------------------------------------------- | ---------------- |
| https://www.luogu.com.cn/problem/P2024            |                  |
| https://atcoder.jp/contests/abc327/tasks/abc327_d |                  |
| https://atcoder.jp/contests/abc373/tasks/abc373_d | 权重并查集（可） |


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


#### 拆环成链

| Link                                              | Explanation |
| ------------------------------------------------- | ----------- |
| https://atcoder.jp/contests/abc338/tasks/abc338_e | 区间交集    |
