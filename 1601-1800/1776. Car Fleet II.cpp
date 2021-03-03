// https://leetcode.com/problems/car-fleet-ii/discuss/1085987/JavaC%2B%2BPython-O(n)-Stack-Solution
// 这道题目最核心的逻辑就是如果没有从右往左的扫描的过程中，扫到了第i个，然后往右计算是否碰撞中，如果没法在第i + 1追上i + 2以前追上i + 1，那么其实可以把i + 2车当作i的右边第一辆车，以此类推
class Solution {
public:
    vector<double> getCollisionTimes(vector<vector<int>>& A) {
        int n = A.size();
        vector<int> stack;
        vector<double> res(n, -1);
        for (int i = n - 1; i >= 0; --i) {
            int p = A[i][0], s = A[i][1];
            while (!stack.empty()) {
                int j = stack.back(), p2 = A[j][0], s2 = A[j][1];
                if (s <= s2 || 1.0 * (p2 - p) / (s - s2) >= res[j] && res[j] > 0)
                    stack.pop_back();
                else
                    break;
            }
            if (!stack.empty())
                res[i] = 1.0 * (A[stack.back()][0] - p) / (s - A[stack.back()][1]);
            stack.push_back(i);
        }
        return res;
    }
};
