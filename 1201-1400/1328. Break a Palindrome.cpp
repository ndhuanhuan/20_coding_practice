// https://zxi.mytechroad.com/blog/greedy/leetcode-1328-break-a-palindrome/
class Solution {
public:
  string breakPalindrome(string palindrome) {
    const int n = palindrome.length();
    if (n == 1) return "";
    for (int i = 0; i < n / 2; ++i) {
      if (palindrome[i] != 'a') {
        palindrome[i] = 'a';
        return palindrome;
      }
    }
    palindrome.back() = 'b';
    return palindrome;
  }
};
