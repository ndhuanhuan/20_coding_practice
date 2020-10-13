// https://zxi.mytechroad.com/blog/greedy/leetcode-1616-split-two-strings-to-make-palindrome/
class Solution {
public:
  bool checkPalindromeFormation(string a, string b) {
    auto isPalindrome = [](const string& s, int i, int j) {
      while (i < j && s[i] == s[j]) ++i, --j;        
      return i >= j;
    };
    auto check = [&isPalindrome](const string& a, const string& b) {
      int i = 0;
      int j = a.length() - 1;
      while (a[i] == b[j]) ++i, --j;
      return isPalindrome(a, i, j) || isPalindrome(b, i, j);
    };
    return check(a, b) || check(b, a);
  }
};
