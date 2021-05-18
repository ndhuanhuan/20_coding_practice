// https://leetcode.com/problems/minimum-number-of-swaps-to-make-the-binary-string-alternating/discuss/1211069/simplest-explanation-with-java-solution-100-faster
// https://leetcode.com/problems/minimum-number-of-swaps-to-make-the-binary-string-alternating/discuss/1211263/Simple-C%2B%2B-Solution
class Solution {
    
    int minFillPos(string& s, char ch) {
        int count = 0;
        for(int i=0; i<s.size(); i+=2) {
            if(s[i] != ch) count++;
        }
        return count;
    }
    
public:
    int minSwaps(string s) {
        int oneCount = count(s.begin(), s.end(), '1');
        int zeroCount = count(s.begin(), s.end(), '0');
        if(abs(oneCount-zeroCount) > 1) return -1;
        if(oneCount > zeroCount) return minFillPos(s,'1');
        if(zeroCount > oneCount) return minFillPos(s,'0');
        return min(minFillPos(s,'0'), minFillPos(s,'1'));
    }
};
