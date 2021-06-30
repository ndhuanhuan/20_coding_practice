// https://leetcode.com/problems/game-of-nim/discuss/1295123/C%2B%2B-3-liners-concise-O(n)-solution-with-explanation-(classic-problem)
class Solution {
public:
    bool nimGame(vector<int>& piles) 
    {
        int result=0,n=piles.size();
        for(int i=0;i<n;i++) result^=piles[i];
        return result;
    }
};
