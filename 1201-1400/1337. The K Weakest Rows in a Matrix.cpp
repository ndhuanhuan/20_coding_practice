// https://leetcode.com/problems/the-k-weakest-rows-in-a-matrix/discuss/496490/C%2B%2B-Set
class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        set<pair<int, int>> m;
        for (auto i = 0; i < mat.size(); ++i) {
            auto p = accumulate(begin(mat[i]), end(mat[i]), 0);
            m.insert({p, i});
        }
        vector<int> res;
        for (auto it = begin(m); k > 0; ++it, --k)
            res.push_back(it->second);
        return res;
    }
};
