// https://leetcode.com/problems/the-earliest-and-latest-rounds-where-players-compete/discuss/1268539/Recursion-(500ms)-%2B-Memo-(0ms)
class Solution {
public:
    int min_r = INT_MAX, max_r = INT_MIN;
    unordered_set<int> visited;
    int getGapMask(int mask, int first, int second) {
        int res = 0;
        for (auto i = 0; mask > 0; ++i, mask >>= 1) {
            res += mask & 1 && i < first ? 1 : 0;
            res += mask & 1 && i > first && i < second ? 26 : 0;
            res += mask & 1 && i > second ? 26 * 26 : 0;
        }
        return res;
    }
    void dfs(int mask, int round, int i, int j, int first, int second) {
        if (i >= j)
            dfs(mask, round + 1, 0, 27, first, second);
        else if ((mask & (1 << i)) == 0)
            dfs(mask, round, i + 1, j, first, second);
        else if ((mask & (1 << j)) == 0)
            dfs(mask, round, i, j - 1, first, second);
        else if (i == first && j == second) {
            min_r = min(min_r, round);
            max_r = max(max_r, round);
        }
        else if (visited.insert(getGapMask(mask, first, second)).second) { // if value not exist in visited set, then this condition will be true, we should dfs
            if (i != first && i != second)
                dfs(mask ^ (1 << i), round, i + 1, j - 1, first, second);
            if (j != first && j != second)
                dfs(mask ^ (1 << j), round, i + 1, j - 1, first, second);
        }
    }
    vector<int> earliestAndLatest(int n, int first, int second) {
        dfs((1 << n) - 1, 1, 0, 27, first - 1, second - 1);
        return { min_r, max_r };
    }
};
