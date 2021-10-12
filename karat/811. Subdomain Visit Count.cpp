class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        unordered_map<string, int> m;
        vector<string> res;
        for(string cp: cpdomains) {
            int pos = cp.find(" ");
            int count = stoi(cp.substr(0, pos));
            m[cp.substr(pos + 1)] += count;
            for(int i = pos+1; i < cp.size(); ++i) {
                if(cp[i] == '.') {
                    m[cp.substr(i+1)] += count;
                }
            }
        }
        
        for(auto x: m) {
            res.push_back(to_string(x.second) + " " + x.first);
        }
        
        return res;
    }
};
