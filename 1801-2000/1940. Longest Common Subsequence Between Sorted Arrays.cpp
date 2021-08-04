// https://leetcode.com/problems/longest-common-subsequence-between-sorted-arrays/discuss/1354008/Counting-Numbers-(one-liner)
class Solution {
public:
    vector<int> longestCommomSubsequence(vector<vector<int>>& arrays) {
        vector<int> cnt(101), res;
        for (auto &arr : arrays)
            for (int n : arr)
                if (++cnt[n] == arrays.size())
                    res.push_back(n);
        return res;
    }
};
