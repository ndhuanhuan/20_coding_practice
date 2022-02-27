class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int cnt=0;
        int n=pref.size();
        for(auto s:words)
        {
            if(s.size()>=pref.size())
            {
                if(s.substr(0,n)==pref)
                    cnt++;
            }
        }
        return cnt;
    }
};
