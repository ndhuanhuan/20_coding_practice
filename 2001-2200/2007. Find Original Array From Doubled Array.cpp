// https://leetcode.com/problems/find-original-array-from-doubled-array/discuss/1470891/C%2B%2B-Frequency-Map
class Solution {
public:
    vector<int> findOriginalArray(vector<int>& A) {
        if (A.size() % 2) return {};
        unordered_map<int, int> m;
        for (int n : A) m[n]++;
        vector<int> nums;
        for (auto [n, cnt] : m) nums.push_back(n);
        sort(begin(nums), end(nums));
        vector<int> ans;
        for (int n : nums) {
            if (m[2 * n] < m[n]) return {};
            for (int i = 0; i < m[n]; ++i, --m[2 * n]) ans.push_back(n);
        }
        return ans;
    }
};
