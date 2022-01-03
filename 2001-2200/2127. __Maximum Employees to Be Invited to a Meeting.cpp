// https://leetcode.com/problems/maximum-employees-to-be-invited-to-a-meeting/discuss/1660944/C%2B%2B-DFS-with-illustration
class Solution {
public:
    int maximumInvitations(vector<int>& A) {
        int N = A.size();
        vector<int> m(N, -1); // m[i] is the depth of node i. -1 means unvisited
        vector<vector<int>> r(N); // The reverse graph
        for (int i = 0; i < N; ++i) r[A[i]].push_back(i);
        // handle case 1
        function<int(int)> dfs = [&](int u) {
            if (m[u] != -1) return m[u];
            int ans = 0;
            for (int v : r[u]) ans = max(ans, dfs(v));
            return m[u] = 1 + ans;
        };
        int ans = 0, free = 0;
        for (int i = 0; i < N; ++i) {
            if (m[i] != -1) continue; // skip visited nodes
            if (A[A[i]] == i) {
                m[i] = m[A[i]] = 0;
                int a = 0, b = 0; // find the length of the longest arms starting from `i` and `A[i]`
                for (int v : r[i]) {
                    if (v == A[i]) continue;
                    a = max(a, dfs(v));
                }
                for (int v : r[A[i]]) {
                    if (v == i) continue;
                    b = max(b, dfs(v));
                }
                free += a + b + 2; // this free component is of length `a+b+2`
            }
        }
        // handle case 2
        function<tuple<int, int, bool>(int)> dfs2 = [&](int u)->tuple<int, int, bool> {
            if (m[u] != -1) return {u, m[u], false}; // this is the merge point
            m[u] = 0;
            auto [mergePoint, depth, mergePointMet] = dfs2(A[u]);
            
            // Most hard to understand part, use original post's 6->5->4->3->2->1 as example.
            // 4->3->2->1 is a cycle, they won't goes into below if(mergePointMet) branch
            // for 6->5, it is not part of cycle, but they need to return the best results anyway, so we set it to depth=0 and return the "acutal" depth of cycle althogh it does 
            // not belong to it.
            if (mergePointMet) { // If we've met the merge point again already, this node is outside of the cycle and should be ignored.
                m[u] = 0;
                return {mergePoint, depth, true};
            }
            m[u] = 1 + depth; // If we haven't met the merge point, we increment the depth.
            return {mergePoint, m[u], u == mergePoint};
        };
        for (int i = 0; i < N; ++i) {
            if(m[i] != -1) continue;
            auto [mergePoint, depth, mergePointMet]= dfs2(i);
            if (mergePointMet) ans = max(ans, depth);
        }
        return max(ans, free);
    }
};
