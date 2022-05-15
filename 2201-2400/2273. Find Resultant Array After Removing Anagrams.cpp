class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> res;
        unordered_set<string> ss;
        
        int left = 0;
        
        for(int i = 0; i < words.size(); ++i) {
            if(i == 0) {
                res.push_back(words[i]);
                continue;
            }
            
            string prev = words[i-1];
            string cur = words[i];
            
            string prev_sorted = prev;
            string cur_sorted = cur;
            
            sort(prev_sorted.begin(), prev_sorted.end());
            sort(cur_sorted.begin(), cur_sorted.end());
            
            if(prev_sorted == cur_sorted) continue;
            else res.push_back(cur);
            
        }
        return res;
    }
};
