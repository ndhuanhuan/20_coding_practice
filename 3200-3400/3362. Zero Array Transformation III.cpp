// https://leetcode.cn/problems/zero-array-transformation-iii/solutions/2998650/tan-xin-zui-da-dui-chai-fen-shu-zu-pytho-35o6/
class Solution {
public:
    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
        ranges::sort(queries, {}, [](auto& q) { return q[0]; });
        int n = nums.size(), j = 0, sum_d = 0;
        vector<int> diff(n + 1, 0);
        priority_queue<int> pq;
        for (int i = 0; i < n; i++) {
            sum_d += diff[i];
            while (j < queries.size() && queries[j][0] <= i) {
                pq.push(queries[j][1]);
                j++;
            }
            while (sum_d < nums[i] && !pq.empty() && pq.top() >= i) {
                sum_d++;
                diff[pq.top() + 1]--;
                pq.pop();
            }
            if (sum_d < nums[i]) {
                return -1;
            }
        }
        return pq.size();
    }
};
