class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int> res;
        for (int i = 0; i < nums.size(); ++i)
            if (nums[i] == key) {
                int start = max(res.empty() ? 0 : res.back() + 1, i - k);
                for (int j = start; j <= i + k && j < nums.size(); ++j)
                    res.push_back(j);
            }
        return res;
    }
};
