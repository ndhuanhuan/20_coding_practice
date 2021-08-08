class Solution {
public:
    bool isPrefixString(string s, vector<string>& words) {
        string check = "";
        
        for(const string &word : words) {
            check += word;
            
			if(check == s)                   return true;
			if(check.length() >= s.length()) return false;
        }
        
        return false;
    }
};
