// https://leetcode.cn/problems/find-the-k-th-character-in-string-game-ii/solutions/2934284/liang-chong-zuo-fa-di-gui-die-dai-python-5f6z/
class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        int n = min((int) operations.size(), (int) __lg(k - 1) + 1);
        int inc = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (k > (1LL << i)) { // k 在右半边
                inc += operations[i];
                k -= (1LL << i);
            }
        }
        return 'a' + inc % 26;
    }
};

