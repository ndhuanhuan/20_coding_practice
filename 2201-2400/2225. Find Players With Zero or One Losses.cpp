class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int, int> m;
        set<int> candidates;
        for(int i = 0; i < matches.size(); ++i) {
            m[matches[i][1]]++;
            candidates.insert(matches[i][0]);
            candidates.insert(matches[i][1]);
        }
        
        vector<int> res1, res2;
        for(auto c : candidates) {
            if(!m.count(c)) {
                res1.push_back(c);
            } else if(m.count(c) && m[c] == 1) {
                res2.push_back(c);
            }
        }
        
        vector<vector<int>> res;
        res.push_back(res1);
        res.push_back(res2);
        
        return res;
    }
};
