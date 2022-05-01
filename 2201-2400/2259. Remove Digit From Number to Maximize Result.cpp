class Solution {
public:
    string removeDigit(string number, char digit) {
        const int n = number.size();
        
        string res = "";
        for(int i = 0; i < n; ++i) {
            if(number[i] == digit) {
                if(res == "") res = number.substr(0, i) + number.substr(i+1);
                else {
                    string tmp = number.substr(0, i) + number.substr(i+1);
                    if(tmp > res) {
                        res = tmp;
                    }
                }
            }    
        }
        
        
        return res;
    }
};
