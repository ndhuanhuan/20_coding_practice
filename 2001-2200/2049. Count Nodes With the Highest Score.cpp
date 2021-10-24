// https://leetcode.com/problems/count-nodes-with-the-highest-score/discuss/1537494/C%2B%2B-Post-order-Traversal
class Solution {
public:
    int countHighestScoreNodes(vector<int>& P) {
        long N = P.size(), ans = 0, maxScore = 0;
        vector<vector<int>> G(N); // build the graph -- G[i] is a list of the children of node `i`.
        for (int i = 1; i < N; ++i) G[P[i]].push_back(i);
        function<int(int)> dfs = [&](int u) { // Post-order traversal. Returns the size of the subtree rooted at node `u`.
            long score = 1, cnt = 1;
            for (int v : G[u]) {
                int c = dfs(v);
                cnt += c;
                score *= c;
            }
            long other = N - cnt; // The count of nodes not in this subtree rooted at node `u`.
            if (other) score *= other;
            if (score > maxScore) {
                maxScore = score;
                ans = 0;
            }
            if (score == maxScore) ++ans;
            return cnt;
        };
        dfs(0);
        return ans;
    }
};
