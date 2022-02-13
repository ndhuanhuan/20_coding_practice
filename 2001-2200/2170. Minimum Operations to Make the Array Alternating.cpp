class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        const int n = nums.size();
        const int odd = (n + 1) / 2;
        const int even = n / 2;
        
        unordered_map<int, int> oddM;
        unordered_map<int, int> evenM;
        
        for(int i = 0; i < n; ++i) {
            if(i % 2) {
                oddM[nums[i]]++;
            } else {
                evenM[nums[i]]++;
            }
        }
        
        int maxOddCnt = 0, secondOddCnt = 0;
        int maxOddNum = -1, secondOddNum = -1;
        int maxEvenCnt = 0, secondEvenCnt = 0;
        int maxEvenNum = -1, secondEvenNum = -1;
        
        for(auto kv: oddM) {
            if(kv.second >= maxOddCnt) {
                secondOddCnt = maxOddCnt;
                secondOddNum = maxOddNum;
                maxOddCnt = kv.second;
                maxOddNum = kv.first;
            } else if(kv.second >= secondOddCnt) {
                secondOddCnt = kv.second;
                secondOddNum = kv.first;
            }
        }
        
        for(auto kv: evenM) {
            // cout << kv.first << " " << kv.second <<endl;
            if(kv.second >= maxEvenCnt) {
                secondEvenCnt = maxEvenCnt;
                secondEvenNum = maxEvenNum;
                maxEvenCnt = kv.second;
                maxEvenNum = kv.first;
                // cout << maxEvenNum << "=>" << maxEvenCnt <<endl;
            } else if(kv.second >= secondEvenCnt) {
                secondEvenCnt = kv.second;
                secondEvenNum = kv.first;
            }
        }
        
        // cout << maxEvenNum << endl;
        // cout << secondEvenNum << endl;
        // cout << maxOddNum << endl;
        // cout << secondOddNum << endl;
        
        int res = 0;
        if(maxEvenNum != maxOddNum) {
            res = n - maxEvenCnt - maxOddCnt;
        } else {
            int candidate1 = n - maxEvenCnt - secondOddCnt;
            int candidate2 = n - maxOddCnt - secondEvenCnt;
            res = candidate1>= candidate2 ? candidate2 : candidate1;
        }
        
        return res;
    }
};
