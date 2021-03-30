// https://zxi.mytechroad.com/blog/hashtable/leetcode-1805-number-of-different-integers-in-a-string/
class Solution {
public:
  int numDifferentIntegers(string word) {
    word += "$";
    unordered_set<string> s;
    deque<char> cur;
    for (char c : word) {
      if (isdigit(c)) {       
        cur.push_back(c);
      } else if (!cur.empty()) {      
        while (cur.size() > 1 && cur[0] == '0')
          cur.pop_front();
        s.insert({begin(cur), end(cur)});
        cur.clear();
      }
    }
    return s.size();
  }
};
