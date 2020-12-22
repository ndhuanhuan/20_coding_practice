// https://zxi.mytechroad.com/blog/string/leetcode-1694-reformat-phone-number/
class Solution {
public:
  string reformatNumber(string number) {
    string ans;
    const int total = count_if(begin(number), end(number), 
                               [](char c) { return isdigit(c); });
    int l = 0;
    for (char c : number) {
      if (!isdigit(c)) continue;      
      ans += c;
      ++l;
      if ((l % 3 == 0 && total - l >= 4) ||
          (total % 3 != 0 && total - l == 2)
          || (total % 3 == 0 && total - l == 3))
        ans += "-";
    }
    return ans;
  }
};
