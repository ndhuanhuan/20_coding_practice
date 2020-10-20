// https://zxi.mytechroad.com/blog/graph/leetcode-1627-graph-connectivity-with-threshold/
class UnionFind {
    vector<int> parent, size;
public:
    UnionFind(int n) {
        parent.resize(n); size.resize(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i; size[i] = 1;
        }
    }
    int find(int x) {
        if (x == parent[x]) return x;
        return parent[x] = find(parent[x]); // Path compression
    }
    bool Union(int u, int v) {
        int pu = find(u), pv = find(v);
        if (pu == pv) return false;
        if (size[pu] > size[pv]) { // Union by larger size
            size[pu] += size[pv];
            parent[pv] = pu;
        } else {
            size[pv] += size[pu];
            parent[pu] = pv;
        }
        return true;
    }
};

class Solution {
public:
    vector<bool> areConnected(int n, int threshold, vector<vector<int>>& queries) {
        UnionFind uf(n+1);
        for (int i = 1; i <= n; i++)
            for (int j = i * 2; j <= n; j += i)
                if (i > threshold)
                    uf.Union(i, j);
        vector<bool> ans;
        for (auto& q : queries) {
            int pa = uf.find(q[0]);
            int pb = uf.find(q[1]);
            ans.push_back(pa == pb);
        }
        return ans;
    }
};
