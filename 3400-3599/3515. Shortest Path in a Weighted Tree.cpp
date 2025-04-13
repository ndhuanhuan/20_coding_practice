// https://leetcode.cn/problems/shortest-path-in-a-weighted-tree/solutions/3649372/dfs-shi-jian-chuo-chai-fen-shu-zhuang-sh-h8q3/
template<typename T>
class FenwickTree {
    vector<T> tree;

public:
    // 使用下标 1 到 n
    FenwickTree(int n) : tree(n + 1) {}

    // a[i] 增加 val
    // 1 <= i <= n
    void update(int i, T val) {
        for (; i < tree.size(); i += i & -i) {
            tree[i] += val;
        }
    }

    // 求前缀和 a[1] + ... + a[i]
    // 1 <= i <= n
    T pre(int i) const {
        T res = 0;
        for (; i > 0; i &= i - 1) {
            res += tree[i];
        }
        return res;
    }
};

class Solution {
public:
    vector<int> treeQueries(int n, vector<vector<int>>& edges, vector<vector<int>>& queries) {
        vector<vector<int>> g(n + 1);
        for (auto& e : edges) {
            int x = e[0], y = e[1];
            g[x].push_back(y);
            g[y].push_back(x);
        }

        vector<int> in(n + 1), out(n + 1);
        int clock = 0;
        auto dfs = [&](this auto&& dfs, int x, int fa) -> void {
            in[x] = ++clock; // 进来的时间
            for (int y : g[x]) {
                if (y != fa) {
                    dfs(y, x);
                }
            }
            out[x] = clock; // 离开的时间
        };
        dfs(1, 0);

        // 对于一条边 x-y（y 是 x 的儿子），把边权保存在 weight[y] 中
        vector<int> weight(n + 1);
        FenwickTree<int> diff(n);
        auto update = [&](int x, int y, int w) {
            // 保证 y 是 x 的儿子
            if (in[x] > in[y]) {
                y = x;
            }
            int d = w - weight[y]; // 边权的增量
            weight[y] = w;
            // 把子树 y 中的最短路长度都增加 d（用差分树状数组维护）
            diff.update(in[y], d);
            diff.update(out[y] + 1, -d);
        };

        for (auto& e : edges) {
            update(e[0], e[1], e[2]);
        }

        vector<int> ans;
        for (auto& q : queries) {
            if (q[0] == 1) {
                update(q[1], q[2], q[3]);
            } else {
                ans.push_back(diff.pre(in[q[1]]));
            }
        }
        return ans;
    }
};
