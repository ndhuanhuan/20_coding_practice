class Solution {
public:
    int digArtifacts(int n, vector<vector<int>>& artifacts, vector<vector<int>>& dig) {
        unordered_map<string, bool> m;
        for(auto d: dig) {
            string key = to_string(d[0]) + " " + to_string(d[1]);
            m[key] = true;
        }
        
        int res = 0;
        for(auto a: artifacts) {
            bool valid = true;
            for(int i = a[0]; i <= a[2]; ++i) {
                for(int j = a[1]; j <= a[3]; ++j) {
                    string key = to_string(i) + " " + to_string(j);
                    if(!m.count(key)) {
                        valid = false;
                        break;
                    }
                }
            }
            if(valid) res++;
        }
        
        return res;
    }
};
