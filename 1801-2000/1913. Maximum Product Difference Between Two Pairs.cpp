class Solution {
public:
  int maxProductDifference(vector<int>& nums){
    sort(nums.begin(), nums.begin() + 4);              //sorting ONLY FIRST FOUR NUMBERS               
    int mm = nums[0], m = nums[1], M = nums[2], MM = nums[3];
    
    for(int i = 4; i != nums.size(); i++)
      if     (nums[i] >= MM) M = MM, MM = nums[i];     //for case: mm , m , M, MM, number , else =>
      else if(nums[i] >   M)          M = nums[i];     //for case: mm , m , M, number, MM , else =>
      else if(nums[i] <= mm) m = mm, mm = nums[i];     //for case: number, mm , m , M, MM , else =>
      else if(nums[i] <   m)          m = nums[i];     //for case: mm , number, m , M, MM 
    
    return MM*M - mm*m;
  }
};
