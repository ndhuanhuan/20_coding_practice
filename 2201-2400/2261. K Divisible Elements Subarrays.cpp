class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        unordered_set<string> res;
        for(int i = 0; i< nums.size(); ++i) {
            int count =0;
            string tmp = "";
            for(int j = i; j < nums.size(); ++j) {
                if(nums[j] % p == 0) {
                    ++count;
                }
                
                if(count > k) break;
                
                tmp += "-";
                tmp+= to_string(nums[j]);
                res.insert(tmp);
            }
            
            
        }
        
        return res.size();
    }
};
