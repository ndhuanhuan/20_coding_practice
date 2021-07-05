// https://leetcode.com/problems/build-array-from-permutation/discuss/1315705/Python-and-C%2B%2B-Solution-for-both-O(n)-and-O(1)-space-complexity.
class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            nums[i]=nums[i]+(n*(nums[nums[i]]%n));
        }
        for(int i=0;i<n;i++){
            nums[i]/=n;
        }
        return nums;
    }
};
