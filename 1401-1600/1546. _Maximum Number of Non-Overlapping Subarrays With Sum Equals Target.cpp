// https://leetcode.com/problems/maximum-number-of-non-overlapping-subarrays-with-sum-equals-target/discuss/780887/Java-Detailed-Explanation-DPMapPrefix-O(N)
class Solution {
public:
    int maxNonOverlapping(vector<int>& nums, int target) {
        int n = nums.size();
        /*
        unordered_map's search/insertion/deletion time: 
        average O(1), worst O(n)
        */
        unordered_map<int, int> sum2count;
        int sum = 0;
        int count = 0;
        
        /*
        if we can find a i s.t. nums[0...i] = target,
        count should be sum2count[0]+1 = 1
        */
        sum2count[0] = 0;
        
        for(int i = 0; i < n; ++i){
            //sum: accumulate sum of nums[0...i]
            sum += nums[i];
            
            if(sum2count.find(sum-target) != sum2count.end()){
                /*
                we can find a j s.t. nums[0...j] + target = nums[0...i],
                so nums[j+1...i] sums to target
                */
                //choose btw original count and current found count
                count = max(count, sum2count[sum-target] + 1);
            }
            
            sum2count[sum] = count;
        }
        
        return count;
    }
};
