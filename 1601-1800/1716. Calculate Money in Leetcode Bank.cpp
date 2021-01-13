class Solution {
public:
    int totalMoney(int n) {
        int a = n/7, b = n%7;
        int sum = 0;
        sum += a * 28;
        for(int i = a + 1; i <= a +b; ++i) {
            sum += i;
        }
        if(a > 1) {
          int tmp = a * (a-1)/2 * 7;
          sum += tmp;
        } 
        return sum;
        
    }
};
