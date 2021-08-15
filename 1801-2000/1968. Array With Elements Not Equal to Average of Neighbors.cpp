// https://leetcode.com/problems/array-with-elements-not-equal-to-average-of-neighbors/discuss/1403975/C%2B%2B-or-O(nlogn)-time-and-O(n)-complexity-using-sorting-or-Explanation-or-260-ms
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> ans;
        int smaller(0),larger(nums.size()-1);
        while(smaller<larger){
            ans.push_back(nums[smaller++]);// incr the left pointer to next minimum
            ans.push_back(nums[larger--]);// decr the right pointer to next maximum
        }
        if(nums.size()&1){// if array is odd lengthed then middle element has to be pushed also
            ans.push_back(nums[smaller]);// smaller=larger here
        }
        return ans;
    }
};
