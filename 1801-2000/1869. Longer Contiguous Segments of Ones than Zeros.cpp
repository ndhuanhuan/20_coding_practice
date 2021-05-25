class Solution {
public:
    bool checkZeroOnes(string s) {
        int maxOnes=0,maxZeros=0,ones=0,zeros=0,n=s.length();
        for(int i=0;i<n;i++)
        {
            if(s[i]=='1') ones++,zeros=0;
            else zeros++,ones=0;

            maxOnes=max(maxOnes,ones);
            maxZeros=max(maxZeros,zeros);
        }
        return maxOnes>maxZeros;
    }
};
