// https://leetcode.com/problems/count-special-quadruplets/discuss/1445269/C%2B%2B-Time%3A-O(n3)-Space%3A-O(n).-Similar-to-2sum
class Solution {
public:
    int countQuadruplets(vector<int>& nums) {
        const auto n = nums.size();
        unordered_map<int, int> freq;
        
        freq[nums[n - 1]] = 1;
        size_t answ = 0;
        for (int i = n - 2; i > 1; --i)
        {
            for (int j = i - 1; j > 0; --j)
            {
                for (int k = j - 1; k >= 0; --k)
                {
                    if (freq.count(nums[i] + nums[j] + nums[k]))
                    {
                        answ += freq[nums[i] + nums[j] + nums[k]];
                    }
                }
            }
            freq[nums[i]] += 1;
        }
        return answ;
    }
};
