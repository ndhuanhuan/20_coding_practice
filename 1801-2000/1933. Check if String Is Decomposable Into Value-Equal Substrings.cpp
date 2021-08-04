class Solution {
public:
    bool isDecomposable(string s) {
        s.push_back('_');
        int num2s=0, count=1;
        for (int i=1; i<s.length(); i++) {
            if (s[i]==s[i-1])
                count++;
            else {
                if (count%3==1)
                    return false;
                else if (count%3==2) {
                    num2s++;
                    if (num2s>1)
                        return false;
                }
                count = 1;
            }
        }
        return num2s==1;
    }
};
