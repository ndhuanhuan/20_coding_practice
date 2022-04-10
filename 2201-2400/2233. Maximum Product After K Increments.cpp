class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {
        const int mod = 1000000007;
        priority_queue<int, vector<int>, greater<int>> q;
        for(auto num: nums) {
            q.push(num);
        }
        
        long long res = 1;
        while(k > 0) {
            int cur = q.top();
            q.pop();
            q.push(cur+1);
            --k;
        }
        
        while(!q.empty()) {
            res *= q.top();
            res %= mod;
            q.pop();
        }
        
        return res;
    }
};
