// https://leetcode.com/problems/minimum-initial-energy-to-finish-tasks/discuss/944376/Python-clean-greedy-solution-with-explanation
// https://leetcode.com/problems/minimum-initial-energy-to-finish-tasks/discuss/944473/JavaC%2B%2BPython-Sort-and-some-explanation
class Solution {
public:
    int minimumEffort(vector<vector<int>>& A) {
        int res = 0;
        for (auto &a : A)
            a[0] = a[1] - a[0]; // a[0] now is prev_saved
        sort(A.begin(), A.end());
        for (auto &a : A)
            res = max(res + a[1] - a[0], a[1]); // To start a new task, we need to add mmin - prev_saved energy. 
        return res;
    }
};
