// https://leetcode.com/problems/find-the-winner-of-the-circular-game/discuss/1152585/O(n)-(no-stimulation)(onelinear)-py-The-classic-josephus-problem-with-explanation
// https://leetcode.com/problems/find-the-winner-of-the-circular-game/discuss/1152617/Josephus-Problem(C%2B%2B)
// https://zhuanlan.zhihu.com/p/114391147
class Solution {
public:
    int solve(int n,int k)
    {
        if(n==1) return 0;
        int x=solve(n-1,k);
        int y=(x+k)%n;
        return y;
    }
    int findTheWinner(int n, int k) {
       if(k>n) k=k%n;
        return solve(n,k)+1;
    }
};
