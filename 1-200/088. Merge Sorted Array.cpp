class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int pa=m-1,pb=n-1,pc=m+n-1;
        while(pa>=0&&pb>=0)
        {
            if(nums1[pa]>nums2[pb])
            {
                nums1[pc--] = nums1[pa--];
            }
            else
            {
                nums1[pc--] = nums2[pb--];
            }
        }
        while(pa>=0) nums1[pc--] = nums1[pa--];
        while(pb>=0) nums1[pc--] = nums2[pb--];
    }
};
