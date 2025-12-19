# 📘 C++ 程序设计竞赛速查手册（高级数据结构篇）

> 适用于校赛 / 省赛 | 可带入考场的纸质资料 | 所有模板可直接使用

---

## 🔹 并查集（Union-Find / DSU）

**用途**：判断连通性、合并集合（如“朋友关系”、“岛屿数量”）

```cpp
const int N = 100010;
int parent[N];

// 初始化
void init(int n) {
    for (int i = 0; i <= n; i++) parent[i] = i;
}

// 查找根（带路径压缩）
int find(int x) {
    return parent[x] == x ? x : parent[x] = find(parent[x]);
}

// 合并
void unite(int a, int b) {
    parent[find(a)] = find(b);
}

// 判断是否同集合
bool same(int a, int b) {
    return find(a) == find(b);
}
```
💡 路径压缩后效率接近 O(α(n)) ≈ O(1)，足够应付 `n ≤ 1e5`。

---

## 🔹 单调队列（滑动窗口最值）

**用途**：求固定长度窗口内的最大/最小值（O(n)）

```cpp
// 求滑动窗口最小值（deque 存下标）
deque dq;
vector min_in_window(vector& a, int k) {
    vector res;
    for (int i = 0; i < a.size(); i++) {
        while (!dq.empty() && dq.front() <= i - k) dq.pop_front(); // 出界
        while (!dq.empty() && a[dq.back()] >= a[i]) dq.pop_back(); // 维护单调增
        dq.push_back(i);
        if (i >= k - 1) res.push_back(a[dq.front()]);
    }
    return res;
}
```
✅ 最大值：把 `>=` 改成 `<=`，维护**单调递减队列**。

---

## 🔹 ST 表（Sparse Table）—— 静态 RMQ

**用途**：多次查询静态数组的区间最值（预处理 O(n log n)，查询 O(1)）

```cpp
const int MAXN = 100010;
const int LOG = 17; // 2^17 > 1e5

int st[MAXN][LOG];
int lg[MAXN]; // 预处理 log2

void build_st(vector& a) {
    int n = a.size();
    for (int i = 0; i < n; i++) st[i][0] = a[i];
    for (int j = 1; j < LOG; j++) {
        for (int i = 0; i + (1 << j) <= n; i++) {
            st[i][j] = max(st[i][j-1], st[i + (1 << (j-1))][j-1]);
        }
    }
    lg[1] = 0;
    for (int i = 2; i <= n; i++) lg[i] = lg[i/2] + 1;
}

// 查询 [l, r] 区间最大值（闭区间）
int query_max(int l, int r) {
    int k = lg[r - l + 1];
    return max(st[l][k], st[r - (1 << k) + 1][k]);
}
```
⚠️ 仅支持**不可变数组**。若需修改，请用线段树。

---

## 🔹 树状数组（Binary Indexed Tree, BIT）

**用途**：单点修改 + 前缀和查询（O(log n)）

```cpp
const int N = 100010;
int bit[N];

// 从 1 开始索引！
void add(int i, int delta) {
    for (; i < N; i += i & -i) bit[i] += delta;
}

int sum(int i) { // 前缀和 [1, i]
    int s = 0;
    for (; i > 0; i -= i & -i) s += bit[i];
    return s;
}

// 区间和 [l, r]
int range_sum(int l, int r) {
    return sum(r) - sum(l - 1);
}
```
✅ 初始化：先 `memset(bit, 0, sizeof bit)`，再 `add(i, a[i])`。

---

## 🔹 线段树（Segment Tree）—— 区间和 + 懒标记

**用途**：支持区间修改与查询

```cpp
const int N = 100010;
long long seg[N * 4], lazy[N * 4];

void push_up(int rt) {
    seg[rt] = seg[rt << 1] + seg[rt << 1 | 1];
}

void build(int rt, int l, int r, vector& a) {
    lazy[rt] = 0;
    if (l == r) {
        seg[rt] = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(rt << 1, l, mid, a);
    build(rt << 1 | 1, mid + 1, r, a);
    push_up(rt);
}

void push_down(int rt, int len) {
    if (lazy[rt]) {
        lazy[rt << 1] += lazy[rt];
        lazy[rt << 1 | 1] += lazy[rt];
        seg[rt << 1] += lazy[rt] * (len - len / 2);
        seg[rt << 1 | 1] += lazy[rt] * (len / 2);
        lazy[rt] = 0;
    }
}

void update(int rt, int l, int r, int L, int R, long long val) {
    if (L <= l && r <= R) {
        seg[rt] += val * (r - l + 1);
        lazy[rt] += val;
        return;
    }
    push_down(rt, r - l + 1);
    int mid = (l + r) >> 1;
    if (L <= mid) update(rt << 1, l, mid, L, R, val);
    if (R > mid) update(rt << 1 | 1, mid + 1, r, L, R, val);
    push_up(rt);
}

long long query(int rt, int l, int r, int L, int R) {
    if (L <= l && r <= R) return seg[rt];
    push_down(rt, r - l + 1);
    int mid = (l + r) >> 1;
    long long res = 0;
    if (L <= mid) res += query(rt << 1, l, mid, L, R);
    if (R > mid) res += query(rt << 1 | 1, mid + 1, r, L, R);
    return res;
}
```
⚠️ 校赛极少考，优先掌握前缀和或 ST 表。

---

## 🔹 二叉搜索树（BST）—— 用 STL 代替！

C++ STL 已提供高效实现：

```cpp
#include 
set s;           // 有序、去重
multiset ms;     // 有序、可重复

s.insert(10);
s.erase(10);
auto it = s.lower_bound(5); // 第一个 ≥5 的元素
if (it != s.end()) cout << *it;
```

---

## 🔹 图（Graph）—— 邻接表 + 遍历

### 邻接表存储
```cpp
const int N = 100010;
vector g[N]; // 无权图
// vector<pair> g[N]; // 带权图：{to, weight}
```

### DFS（递归）
```cpp
bool vis[N];
void dfs(int u) {
    vis[u] = true;
    for (int v : g[u]) {
        if (!vis[v]) dfs(v);
    }
}
```

### BFS（无权最短路）
```cpp
queue q;
vector dist(N, -1);
q.push(start);
dist[start] = 0;
while (!q.empty()) {
    int u = q.front(); q.pop();
    for (int v : g[u]) {
        if (dist[v] == -1) {
            dist[v] = dist[u] + 1;
            q.push(v);
        }
    }
}
```

### 拓扑排序（DAG）
```cpp
vector indeg(N), topo;
for (int u = 1; u <= n; u++)
    for (int v : g[u]) indeg[v]++;

queue q;
for (int i = 1; i <= n; i++)
    if (indeg[i] == 0) q.push(i);

while (!q.empty()) {
    int u = q.front(); q.pop();
    topo.push_back(u);
    for (int v : g[u]) {
        if (--indeg[v] == 0) q.push(v);
    }
}
```

# 📘 C++ 程序设计竞赛速查手册（完整版）

> 适用于校赛 / 省赛 | 可带入考场的纸质资料 | 所有模板可直接使用

---

## 🔹 一、基础技巧 & 输入输出

### 快速读写（防 TLE）
```cpp
ios::sync_with_stdio(false);
cin.tie(nullptr);
// 或用 scanf/printf（更稳，尤其大数据）
```

### 多组测试数据
```cpp
int T; cin >> T;
while (T--) {
    // solve one test case
}

// 或读到文件末尾（EOF）
while (cin >> n) {
    // process
}
```

### 初始化常量
```cpp
const int INF = 0x3f3f3f3f;        // ≈ 1e9，可 memset
const long long INF_LL = 1e18;
const int MOD = 1000000007;        // 常见取模数
```

---

## 🔹 二、数学 & 数论（校赛高频）

### GCD / LCM
```cpp
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
int lcm(int a, int b) { return a / gcd(a, b) * b; }
```

### 快速幂（模意义下）
```cpp
long long qpow(long long a, long long b, long long mod) {
    long long res = 1;
    while (b) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}
```

### 判断素数（试除法）
```cpp
bool isPrime(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0) return false;
    return true;
}
```

### 进制转换（十进制 → 任意进制）
```cpp
string toBase(int n, int base) {
    if (n == 0) return "0";
    string s;
    while (n) {
        int r = n % base;
        s += (r < 10 ? '0' + r : 'A' + r - 10);
        n /= base;
    }
    reverse(s.begin(), s.end());
    return s;
}
```

---

## 🔹 三、字符串处理（除了 string）

### 字符判断（需 `<cctype>`）
```cpp
isdigit(c)   // 是否数字
isalpha(c)   // 是否字母
islower(c)   // 是否小写
toupper(c), tolower(c) // 转大小写
```

### 分割字符串（按分隔符）
```cpp
vector split(const string& s, char delim) {
    vector res;
    stringstream ss(s);
    string item;
    while (getline(ss, item, delim)) {
        if (!item.empty()) res.push_back(item);
    }
    return res;
}
```

---

## 🔹 四、前缀和 & 差分（O(1) 区间操作）

### 一维前缀和（求区间和）
```cpp
vector pre(n + 1);
for (int i = 1; i <= n; i++) 
    pre[i] = pre[i - 1] + a[i];
int sum_l_r = pre[r] - pre[l - 1]; // [l, r]
```

### 一维差分（区间加，最后还原）
```cpp
vector diff(n + 2);
diff[l] += x;
diff[r + 1] -= x;
// 最后还原：
for (int i = 1; i <= n; i++) 
    a[i] = a[i - 1] + diff[i];
```
✅ 二维版本校赛极少考，可暂不记。

---

## 🔹 五、二分答案（不是二分查找！）

**适用场景**：求“最小的最大值”或“最大的最小值”

```cpp
int left = 0, right = 1e9;
while (left < right) {
    int mid = (left + right) / 2;
    if (check(mid)) {      // check: 能否满足条件？
        right = mid;       // 求最小可行解
    } else {
        left = mid + 1;
    }
}
cout << left;
```
💡 `check()` 是你根据题意写的函数（如：能否在 ≤mid 时间内完成任务？）

---

## 🔹 六、贪心策略（常见模型）

|
 问题类型         
|
 贪心策略 
|
|
------------------
|
--------
|
|
 活动选择         
|
 按结束时间升序 
|
|
 区间覆盖         
|
 按左端点排序，每次选能延伸最远的 
|
|
 排队打水 / 分糖果 
|
 按服务时间/需求升序 
|
|
 分数背包         
|
 按性价比（价值/重量）降序 
|

✅ 贪心无通用模板，但 **排序 + 模拟** 是核心。

---

## 🔹 七、动态规划（DP）入门模板

### 0-1 背包（空间优化）
```cpp
vector dp(W + 1, 0);
for (int i = 0; i < n; i++) {
    for (int j = W; j >= weight[i]; j--) {
        dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
    }
}
```

### 最长递增子序列（LIS，O(n log n)）
```cpp
vector d;
for (int x : a) {
    auto it = lower_bound(d.begin(), d.end(), x);
    if (it == d.end()) d.push_back(x);
    else *it = x;
}
int lis_len = d.size();
```

### 线性 DP（如爬楼梯、打家劫舍）
```cpp
dp[0] = ..., dp[1] = ...;
for (int i = 2; i <= n; i++) {
    dp[i] = max(dp[i - 1], dp[i - 2] + a[i]); // 示例
}
```
⚠️ 校赛 DP 通常为一维，状态转移简单。

---

## 🔹 八、模拟 & 边界处理（最容易 WA！）

### 常见陷阱
- 数组越界（`i < n` vs `i <= n`）
- 整数溢出 → 用 `long long`
- 空输入 / 单元素特判
- 字符串含空格 → 用 `getline(cin, s)`
- 浮点比较 → 用 `abs(a - b) < 1e-6`

### 安全写法示例
```cpp
if (n == 0) { cout << 0; return 0; }
vector a(n);
for (int i = 0; i < n; i++) cin >> a[i]; // 下标从 0 开始！
```