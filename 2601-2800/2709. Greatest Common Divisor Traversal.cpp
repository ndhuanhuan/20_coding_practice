// https://leetcode.cn/problems/greatest-common-divisor-traversal/solution/c-bing-cha-ji-zhi-yin-shu-fen-jie-by-liu-i2xf/

/* 并查集模板 */
class UnionFind {
public:
    vector<int> parent;
    vector<int> size;
    int n;
    // 当前连通分量数目
    int setCount;
    
public:
    UnionFind(int _n): n(_n), setCount(_n), parent(_n), size(_n, 1) {
        iota(parent.begin(), parent.end(), 0);  /* 赋值0-n-1 */
    }
    
    int findset(int x) {
        return parent[x] == x ? x : parent[x] = findset(parent[x]);
    }
    
    bool unite(int x, int y) {
        x = findset(x);
        y = findset(y);
        if (x == y) {
            return false;
        }
        if (size[x] < size[y]) {
            swap(x, y);
        }
        parent[y] = x;
        size[x] += size[y];
        --setCount;
        return true;
    }
    
    bool connected(int x, int y) {
        x = findset(x);
        y = findset(y);
        return x == y;
    }
};

class Solution {
public:
    bool canTraverseAllPairs(vector<int>& nums) {
        int n = nums.size();
        UnionFind uf(n);
        unordered_map<int, int> pos;

        auto f = [&](int d, int i) -> void {
            if (pos.count(d) == 0) { /* 第一个有该质数记录下标 */
                pos[d] = i;
            } else {  /* 含有相同质数, 进行连通 */
                uf.unite(pos[d], i);
            }
        };

        for (int i = 0; i < n; i++) {
            int x = nums[i];
            /* 质因数分解, 连通 */
            for (int d = 2; d * d <= x; d++) {
                if (x % d == 0) {
                    f(d, i);
                    x /= d;
                    while (x % d == 0) {
                        x /= d;
                    }
                }
            }
            if (x > 1) {
                f(x, i);
            }
        }
        return uf.setCount == 1;
    }
};


