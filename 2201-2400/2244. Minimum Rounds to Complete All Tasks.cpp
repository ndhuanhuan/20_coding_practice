class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        sort(tasks.begin(), tasks.end());
        
        const int n = tasks.size();
        
        int res = 0;
        int cur = tasks[0];
        if(n == 1) return -1;
        for(int i = 1; i < n; ++i) {
            int cnt = 1;
            while(i < n && tasks[i] == cur) {++cnt; ++i;}
            int step = helper(cnt);
            if(step == -1) return -1;
            res += helper(cnt);
            if(i < n) cur = tasks[i];
        }
        
        return res;
    }
    
    int helper(int cnt) {
        int total = 0;
        int maxThree = cnt/3;
        int left = cnt - maxThree * 3;
        // cout << left << endl;
        while(maxThree >=0) {
            
            int two = left / 2;
            if(two * 2 == left) return two + maxThree;
            maxThree--;
            left += 3;
        }
        
        return -1;
    }
};
