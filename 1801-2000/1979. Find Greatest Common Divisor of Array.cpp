class Solution {
public:
    int findGCD(vector<int>& nums) {
        int great = INT_MIN;
        int small = INT_MAX;
        
        for(int num: nums) {
            great = max(great, num);
            small = min(small, num);
        }
        
        return gcd(great, small);
    }
    
    int gcd(int a, int b) {
        if (b == 0)
            return a;
        return gcd(b, a % b);
    }
};
