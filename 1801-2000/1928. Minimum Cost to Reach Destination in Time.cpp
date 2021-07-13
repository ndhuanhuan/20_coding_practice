// https://leetcode.com/problems/minimum-cost-to-reach-destination-in-time/discuss/1329145/C%2B%2B-Dijkstra
class Solution {
    typedef array<int, 3> Node; // node, time, cost
public:
    int minCost(int maxTime, vector<vector<int>>& E, vector<int>& F) {
        int N = F.size();
        vector<unordered_map<int, int>> G(N);
        vector<int> cost(N, INT_MAX), minTime(N, INT_MAX);
        for (auto &e : E) {
            int u = e[0], v = e[1], t = e[2];
            if (G[u].count(v)) { // For duplicated edges, we just need to keep track of the edge with smallest time.
                G[u][v] = min(G[u][v], t);
                G[v][u] = min(G[v][u], t);
            } else {
                G[u][v] = t;
                G[v][u] = t;
            }
        }
        auto cmp = [](auto &a, auto &b) { return a[1] > b[1]; }; // min-heap: Heap top is the node with the smallest time to reach
        priority_queue<Node, vector<Node>, decltype(cmp)> pq(cmp);
        pq.push({0, 0, F[0]}); // we start from node `0` whose time is 0 and cost is fee[0]
        cost[0] = F[0];
        minTime[0] = 0;
        while (pq.size()) {
            auto [u, time, c] = pq.top();
            pq.pop();
            for (auto &[v, t] : G[u]) {
                int nt = time + t, nc = c + F[v];
                if (nt > maxTime) continue; // if time is out of range, skip
                if (nc < cost[v]) { // less cost
                    cost[v] = nc;
                    minTime[v] = min(minTime[v], nt);
                    pq.push({v, nt, nc});
                } else if (nt < minTime[v]) { // less time
                    minTime[v] = nt;
                    pq.push({v, nt, nc});
                }
            }
        }
        return cost[N - 1] == INT_MAX ? -1 : cost[N - 1];
    }
};
