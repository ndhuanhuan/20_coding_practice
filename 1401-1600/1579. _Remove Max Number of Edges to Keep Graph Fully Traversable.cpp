// https://zxi.mytechroad.com/blog/graph/leetcode-1579-remove-max-number-of-edges-to-keep-graph-fully-traversable/
class DSU {
public: 
  DSU(int n): p_(n + 1), e_(0) {
    iota(begin(p_), end(p_), 0);
  }
  
  int find(int x) {
    if (p_[x] == x) return x;
    return p_[x] = find(p_[x]);    
  }
  
  int merge(int x, int y) {
    int rx = find(x);
    int ry = find(y);
    if (rx == ry) return 1;
    p_[rx] = ry;
    ++e_;
    return 0;
  }  
  
  int edges() const { return e_; }
private:
  vector<int> p_;
  int e_;
};
 
class Solution {
public:
  int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
    int ans = 0;
    DSU A(n), B(n);
    for (const auto& e: edges) {
      if (e[0] != 3) continue;
      ans += A.merge(e[1], e[2]);
      B.merge(e[1], e[2]);
    }
    for (const auto& e: edges) {
      if (e[0] == 3) continue;
      DSU& d = e[0] == 1 ? A : B;
      ans += d.merge(e[1], e[2]);
    }
    return (A.edges() == n - 1 && B.edges() == n - 1) ? ans : -1;
  }
};
