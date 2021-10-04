class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        const int m = rolls.size();
        vector<int> res;
        int total = mean * (m + n);
        int sum = 0;
        for(int i = 0; i < m; ++i) {
            sum += rolls[i];
        }
        
        int diff = total - sum;
        
        // cout << diff << endl;
        
        if(n * 6 < diff || diff < 0 || diff < n) return res;
        int avg = diff/n;
        int residual = diff - avg*n;
        
        for(int i = 0; i < n; ++i) {
            if(i < residual) {
                res.push_back(avg + 1);
            } else {
                res.push_back(avg);
            }
        }
        
        return res;
    }
};
