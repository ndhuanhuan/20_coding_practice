// https://leetcode.com/problems/positions-of-large-groups/discuss/128957/C%2B%2BJavaPython-Straight-Forward
class Solution {
public:
    vector<vector<int>> largeGroupPositions(string S) {
        vector<vector<int>> res;
        for (int i = 0, j = 0; i < S.size(); i = j) {
            while (j < S.size() && S[j] == S[i]) ++j;
            if (j - i >= 3)
                res.push_back({i, j - 1});
        }
        return res;
    }
};
