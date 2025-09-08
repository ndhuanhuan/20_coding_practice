// https://leetcode.cn/problems/count-bowl-subarrays/solutions/3774499/dan-diao-zhan-pythonjavacgo-by-endlessch-y64n/
class Solution {
public:
    long long bowlSubarrays(vector<int>& nums) {
        int ans = 0;
        stack<int> st;
        for (int i = 0; i < nums.size(); i++) {
            int x = nums[i];
            while (!st.empty() && nums[st.top()] < x) {
                // j=st.top() 右侧严格大于 nums[j] 的数的下标是 i
                if (i - st.top() > 1) { // 子数组的长度至少为 3
                    ans++;
                }
                st.pop();
            }
            // i 左侧大于等于 nums[i] 的数的下标是 st.top()
            if (!st.empty() && i - st.top() > 1) { // 子数组的长度至少为 3
                ans++;
            }
            st.push(i);
        }
        return ans;
    }
};

