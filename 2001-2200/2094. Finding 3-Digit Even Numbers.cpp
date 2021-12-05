
class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int> res;
        vector<int> cnt(10);
        
        for(int d: digits) {
            cnt[d]++;
        }
        
        for(int x = 100; x < 1000; ++x) {
            bool isvalid = false;
            int three = x / 100;
            int two = x%100/10;
            int one = x%10;
            
            if(three == 0) continue;
            if(one%2) continue;
            
            cnt[three]--;
            cnt[two]--;
            cnt[one]--;
            if(cnt[three] >=0 && cnt[two] >= 0 && cnt[one] >= 0) {
                isvalid = true;
            }
            
            cnt[three]++;
            cnt[two]++;
            cnt[one]++;
            
            if(isvalid) res.push_back(x);
        }
        
        return res;
    }
};
