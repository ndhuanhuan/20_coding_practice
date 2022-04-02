class Solution {
public:
    long long numberOfWays(string s) {
        long long a=0,b=0,ans=0;        // a and b are the number of occurances of '1' and '0' after the current building respectively.
        for(int i=0;i<s.length();i++){
            if(s[i]=='1')
                a++;
            else
                b++;
        }
        long long c=0,d=0;              // c and d are the number of occurances of '1' and '0' before the current building respectively.
        for(int i=0;i<s.length();i++){
            if(s[i]=='1'){               // Counting the sequences of "010"
                ans+=(d*b);
                a--;
                c++;
            }
            else{                        // Counting the sequences of "101"
                ans+=(a*c);
                b--;
                d++;
            }
        }
        return ans;
    }
};


class Solution {
public:
    long long numberOfWays(string s) {
        const int n = s.size();
        
        vector<long long> left0(n, 0);
        vector<long long> left1(n, 0);
        
        vector<long long> right0(n, 0);
        vector<long long> right1(n, 0);
        
        for(int i = 0; i < n; ++i) {
            if(s[i] == '0') {
                left0[i]  += (i == 0 ? 1 : left0[i-1] + 1);
                if(i > 0) left1[i] = left1[i-1];
            } else {
                left1[i]  += (i == 0 ? 1 : left1[i-1] + 1);
                if(i > 0) left0[i] = left0[i-1];
            }
        }
        
        for(int i = n-1; i >= 0; --i) {
            if(s[i] == '0') {
                right0[i]  += (i == n-1 ? 1 : right0[i+1] + 1);
                if(i < n-1) right1[i] = right1[i+1];
            } else {
                right1[i]  += (i == n-1 ? 1 : right1[i+1] + 1);
                if(i < n-1) right0[i] = right0[i+1];
            }
        }
        
        long long res = 0;
        
        for(int i = 1; i < n-1; ++i) {
            if(s[i] == '0') {
                // 101
                
                res += left1[i] * right1[i];
            } else {
                res += left0[i] * right0[i];
            }
        }
        
        return res;
    }
};
