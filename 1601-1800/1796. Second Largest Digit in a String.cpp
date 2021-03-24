
class Solution {
public:
  int secondHighest(string s) {
    vector<int> d(10);
    for (char c : s)
      if (c >= '0' && c <= '9')
        d[c - '0'] = 1;
    int order = 0;
    for (int i = 9; i >= 0; --i)
      if (d[i] && ++order == 2)
        return i;
    return -1;
  }
};
