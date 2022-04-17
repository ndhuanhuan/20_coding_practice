class Solution {
public:
    string digitSum(string s, int k) {
        string tmp = s;
        while(tmp.size() > k) {
            int sum = 0;
            string res = "";
            for(int i = 0; i < tmp.size(); i += k) {
                string tmp3 = tmp.substr(i, k);
                //cout << tmp3 << endl;
                for(auto c: tmp3) {
                    sum += (c-'0');
                }
                res += to_string(sum);
                sum = 0;
                //cout << res <<endl;
            }
            tmp = res;
        }
        
        return tmp;
    }
};
