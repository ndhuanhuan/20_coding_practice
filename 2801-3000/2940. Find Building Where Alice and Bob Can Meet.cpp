class Solution {
public:
    vector<int> leftmostBuildingQueries(vector<int> &heights, vector<vector<int>> &queries) {
        vector<int> ans(queries.size(), -1);
        vector<vector<pair<int, int>>> left(heights.size());
        for (int qi = 0; qi < queries.size(); qi++) {
            int i = queries[qi][0], j = queries[qi][1];
            if (i > j) {
                swap(i, j); // 保证 i <= j
            }
            if (i == j || heights[i] < heights[j]) {
                ans[qi] = j; // i 直接跳到 j
            } else {
                left[j].emplace_back(heights[i], qi); // 离线
            }
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        for (int i = 0; i < heights.size(); i++) { // 从小到大枚举下标 i
            while (!pq.empty() && pq.top().first < heights[i]) {
                ans[pq.top().second] = i; // 可以跳到 i（此时 i 是最小的）
                pq.pop();
            }
            for (auto &p: left[i]) {
                pq.emplace(p); // 后面再回答
            }
        }
        return ans;
    }
};
