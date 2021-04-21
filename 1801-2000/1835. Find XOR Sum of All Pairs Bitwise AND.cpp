// https://zxi.mytechroad.com/blog/bit/leetcode-1835-find-xor-sum-of-all-pairs-bitwise-and/
class Solution {
public:
  int getXORSum(vector<int>& A, vector<int>& B) {
    int ans = 0;    
    int xora = 0;
    for (int a : A) xora ^= a;    
    for (int b : B) ans ^= (xora & b);
    return ans;
  }
};
