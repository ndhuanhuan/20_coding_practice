class Solution {
public:
    int minMoves(int target, int maxDoubles) {
        int cur_d = 0;
        int cur_add = 0;
        int left = target; 
        
        while(left > 1) {
            if(cur_d < maxDoubles) {
                cur_add += left % 2 ? 1 : 0;
                cur_d++;
                left /= 2;
            } else {
                cur_add += (left-1);
                left = 1;
            }
        }
        
        return cur_d + cur_add;
    }
};
