// https://leetcode.com/problems/number-of-visible-people-in-a-queue/discuss/1363940/C%2B%2BJavaPython-Monotonic-stack-Visualize-picture-Clean-and-Concise
class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        int n = heights.size();
        vector<int> ans(n);
        stack<int> st;
        for (int i = n - 1; i >= 0; --i) {
            while (!st.empty() && heights[i] >= st.top()) {
                st.pop();
                ++ans[i];
            }
            if (!st.empty())
                ++ans[i];
            st.push(heights[i]);
        }
        return ans;
    }
};
