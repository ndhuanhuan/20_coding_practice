class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        map<long long, int> m;
        int j = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (i - j > k && m[nums[j]] == j) m.erase(nums[j++]);
            auto a = m.lower_bound(static_cast<long long>(nums[i]) - static_cast<long long>(t));
            if (a != m.end() && abs(static_cast<long long>(a->first) - static_cast<long long>(nums[i])) <= t) return true;
            m[nums[i]] = i;
        }
        return false;
    }
}; 
