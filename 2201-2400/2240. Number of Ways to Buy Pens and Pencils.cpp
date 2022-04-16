class Solution {
public:
    long long waysToBuyPensPencils(int total, int cost1, int cost2) {
        const int maxPen = total / cost1;
        long long res = 0;
        for(int i = 0; i <= maxPen; ++i) {
            int totalLeft = total - cost1* i;
            res += totalLeft / cost2 + 1;
        }
        
        return res;
    }
};
