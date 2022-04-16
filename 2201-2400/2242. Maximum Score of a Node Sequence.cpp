// https://leetcode.com/problems/maximum-score-of-a-node-sequence/discuss/1953681/C%2B%2B-O(E)-Try-every-edge-%2B-find-2-more-best-nodes-(one-per-each-edge-side)
class Solution {
public:
    int maximumScore(vector<int>& scores, vector<vector<int>>& edges) {
        const int n = scores.size();
        
        vector<vector<int>> adj(n);
        
        for(const auto& e: edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        
        for(auto& v: adj) {
            sort(v.begin(), v.end(), [&scores](const int l, const int r) { return scores[l] > scores[r];});
        }
        
        int res = -1;
        
        for(const auto& e: edges) {
            const int u = e[0];
            const int v = e[1];
            
            for(int i = 0; i < min((int)adj[u].size(), 3); ++i) {
                int x = adj[u][i];
                if(x == v) continue;
                
                for(int j = 0; j < min((int)adj[v].size(), 3); ++j) {
                    int y = adj[v][j];
                    if(y == u || x == y) continue;
                    res = max(res, scores[x] + scores[y] + scores[u] + scores[v]);
                }
            }
            
        }
        
        return res;
    }
};
