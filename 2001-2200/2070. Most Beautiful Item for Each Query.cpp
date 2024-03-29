// https://leetcode.com/problems/most-beautiful-item-for-each-query/discuss/1576065/C%2B%2B-Offline-Query
class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& A, vector<int>& Q) {
        vector<pair<int, int>> queries;
        for (int i = 0; i < Q.size(); ++i) queries.push_back({Q[i],i});
        sort(begin(queries), end(queries));
        sort(begin(A), end(A));
        int i = 0, N = A.size(), maxBeauty = 0;
        vector<int> ans(Q.size());
        for (auto q : queries) {
            auto &[query, index] = q;
            for (; i < N && A[i][0] <= query; ++i) maxBeauty = max(maxBeauty, A[i][1]);
            ans[index] = maxBeauty;
        }
        return ans;
    }
};
