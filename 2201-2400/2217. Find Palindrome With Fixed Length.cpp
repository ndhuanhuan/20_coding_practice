class Solution {
public:
    vector<long long> kthPalindrome(vector<int>& queries, int intLength) {
        vector<long long> res;
        for(auto q: queries) {
            res.push_back(getkthPalindrome(q, intLength));
        }
        
        return res;
    }
    
    long long getkthPalindrome(int k, int length) {
        // k = 35, lenth = 10 (Even)
        // 1st half number = 9999+35 = 10034         // minVal = 9999+1, maxVal = 99999
        // 2nd half number = reverse(10034) = 43001
        // Number = 1003443001

        // k = 35, lenth = 11 (Odd)
        // 1st half number = 99999+35 = 100034       // minVal = 99999+1, maxVal = 999999
        // 2nd half number = reverse(10003) = 30001
        // Number = 10003430001
        
        int minDigits = (length%2 == 0)? (length/2 - 1): (length/2);
        int maxDigits = (length%2 == 0)? (length/2): (length/2 + 1);
        
        long long minVal = 0;
        long long maxVal = 0;
        
        while (minDigits-- > 0) minVal = minVal*10 + 9;
        while (maxDigits-- > 0) maxVal = maxVal*10 + 9;
        
        if (k > (maxVal - minVal))
            return -1;
        
        string s1 = to_string(minVal + k);
        string s2 = (length%2 == 0)? s1: s1.substr(0, length/2);        
        reverse(s2.begin(), s2.end());
                
        return stoll(s1+s2);
    }
};
