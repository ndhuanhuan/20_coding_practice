class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_set<string> counter;
        unordered_set<string> res;
        
        if (s.size() < 10) return {};
        
        for (int i=0; i<s.size()-9; i++) {
            if(counter.count(s.substr(i, 10))) res.insert(s.substr(i, 10));
            counter.insert(s.substr(i, 10));
        }

        return vector<string>(res.begin(), res.end());
    }
};
