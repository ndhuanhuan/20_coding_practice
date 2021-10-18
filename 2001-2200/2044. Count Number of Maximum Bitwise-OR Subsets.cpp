// https://leetcode.com/problems/count-number-of-maximum-bitwise-or-subsets/discuss/1526221/C%2B%2B-Simple-and-Short-Solution-No-Recursion-Faster-than-100
// https://leetcode.com/problems/count-number-of-maximum-bitwise-or-subsets/discuss/1525309/JavaC%2B%2BPython-DP-solution
class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int res = 0, mx_or = 0, curr, sz;
        vector<int> ors = {0};
        
        for (auto n : nums) mx_or |= n;
        
        for (auto num : nums) {
            sz = ors.size();
            
            for (int i = 0; i < sz; i++) {
                curr = ors[i] | num;
                ors.push_back(curr);
                if (curr == mx_or) res++;
            }
        }
        
        return res;
    }
};
