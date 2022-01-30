class Solution {
public:
    vector<int> maxScoreIndices(vector<int>& nums) {
        vector<int> left_sum, right_sum;
        left_sum.push_back(0);
        right_sum.push_back(0);
        int maxTotal = 0;
        vector<int> res;
        const int n = nums.size();
        for(int i = 0; i < n; ++i) {
            left_sum.push_back(left_sum.back() + (nums[i] == 0 ? 1 : 0));
            right_sum.push_back(right_sum.back() + (nums[n-i-1] == 1 ? 1 : 0));
        }
        
        reverse(right_sum.begin(), right_sum.end());
        
        for(int i = 0; i < left_sum.size(); ++i) {
            if(left_sum[i] + right_sum[i] > maxTotal) {
                maxTotal = left_sum[i] + right_sum[i];
                res = {i};
            } else if (left_sum[i] + right_sum[i] == maxTotal) {
                res.push_back(i);
            }
        }
        
        return res;
        
    }
};
