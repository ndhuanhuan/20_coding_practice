class Solution {
public:
    int widestPairOfIndices(vector<int>& nums1, vector<int>& nums2) {
        int ans = 0, prefix = 0; 
        unordered_map<int, int> seen = {{0, -1}}; 
        for (int i = 0; i < nums1.size(); ++i) {
            prefix += nums1[i] - nums2[i]; 
            if (seen.count(prefix)) ans = max(ans, i - seen[prefix]); 
            else seen[prefix] = i; 
        }
        return ans; 
    }
};
