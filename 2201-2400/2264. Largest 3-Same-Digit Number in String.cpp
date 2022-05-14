class Solution {
public:
    string largestGoodInteger(string num) {
        const int n = num.size();
        
        string res = "";
        
        for(int i = 0; i < n - 2; ++i) {
            if(num[i] == num[i+1] && num[i+1] == num[i+2]) {
                if(res == "" || num.substr(i, 3) > res) {
                    cout << "here";
                    res = num.substr(i, 3);
                }
            }
        }
        
        return res;
    }
};
