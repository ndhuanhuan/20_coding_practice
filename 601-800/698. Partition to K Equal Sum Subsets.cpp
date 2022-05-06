class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = 0;
        sum = accumulate(nums.begin(), nums.end(), sum);
        if (nums.size() < k || sum % k) return false;
        
        vector<bool> visited(nums.size(), false);
        int univisited = nums.size();
        return backtrack(nums, visited, sum / k, 0, 0, k, univisited);
    }
    
    bool backtrack(vector<int>& nums, vector<bool> &visited, int target, int curr_sum, int i, int k, int &unvisited) {
        if (k == 1) 
            return true;
        
        if(unvisited == 0 || i >= nums.size())
            return false;
        
        if (curr_sum == target) 
            return backtrack(nums, visited, target, 0, 0, k-1, unvisited);
        
        for (int j = i; j < nums.size(); j++) {
            if (visited[j] || curr_sum + nums[j] > target) continue;
            
            visited[j] = true;
            unvisited--;
            if (backtrack(nums, visited, target, curr_sum + nums[j], j+1, k, unvisited)) return true;
            visited[j] = false;
            unvisited++;
        }
        
        return false;
    }
};


//http://www.cnblogs.com/grandyang/p/7733098.html
class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % k != 0) return false;
        vector<bool> visited(nums.size(), false);
        return helper(nums, k, sum / k, 0, 0, visited);
    }
    bool helper(vector<int>& nums, int k, int target, int start, int curSum, vector<bool>& visited) {
        if (k == 1) return true;
        if (curSum == target) return helper(nums, k - 1, target, 0, 0, visited);
        for (int i = start; i < nums.size(); ++i) {
            if (visited[i]) continue;
            visited[i] = true;
            if (helper(nums, k, target, i + 1, curSum + nums[i], visited)) return true;
            visited[i] = false;
        }
        return false;
    }
};
