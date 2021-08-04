
// https://www.geeksforgeeks.org/find-the-maximum-of-minimums-for-every-window-size-in-a-given-array/
// My own version
class Solution {
public:
    vector<int> findMaximums(vector<int>& nums) {
        const int n = nums.size();
        
        // Used to find previous and next smaller
        stack<int> s;
        
        // Arrays to store previous and next smaller
        vector<int> left(n+1, -1);
        vector<int> right(n+1, n);
        
        for (int i=0; i<n; i++) {
            while (!s.empty() && nums[s.top()] >= nums[i])
                s.pop();

            if (!s.empty())
                left[i] = s.top();

            s.push(i);
        }
        
        // reuse stack, clear
        while (!s.empty())
            s.pop();
        
        // Fill elements of right[] using same logic
        for (int i = n-1 ; i>=0 ; i--) {
            while (!s.empty() && nums[s.top()] >= nums[i])
                s.pop();

            if(!s.empty())
                right[i] = s.top();

            s.push(i);
        }
        
        // Create and initialize answer array
        vector<int> ans(n + 1, 0);

        // Fill answer array by comparing minimums of all
        // lengths computed using left[] and right[]
        for (int i = 0; i < n; i++) {
            // length of the interval
            int len = right[i] - left[i] - 1;

            // arr[i] is a possible answer for this length
            // 'len' interval, check if arr[i] is more than
            // max for 'len'
            ans[len] = max(ans[len], nums[i]);
        }

        // Some entries in ans[] may not be filled yet. Fill
        // them by taking values from right side of ans[]
        for (int i=n-1; i>=1; i--)
            ans[i] = max(ans[i], ans[i+1]);
        
        // Note that ans[0] or answer for length 0 is useless. we only care about len = 1, 2, etc
        ans.erase(ans.begin());

        // Print the result
        // for (int i=1; i<=n; i++)
        //     cout << ans[i] << " ";
        
        return ans;

    }
};
