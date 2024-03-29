class Solution {
public:
    int minDeletion(vector<int>& nums) {
        bool even = true;
        int size = 0,c = 0;
        for(int i=0;i<nums.size();i++){
            while(i+1<nums.size() && even && nums[i] == nums[i+1]) i++,c++;
            size++;
            even = !even;
        }
        return c + size%2;
    }
};
