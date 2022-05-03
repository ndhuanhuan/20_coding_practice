//http://www.cnblogs.com/grandyang/p/5100098.html
class Solution {
public:
    int bulbSwitch(int n) {
        return sqrt(n);
    }
};

class Solution {
public:
    int bulbSwitch(int n) {
        int counts = 0;

        for (int i=1; i*i<=n; ++i) {
            ++counts;    
        }

        return counts;
    }
};
