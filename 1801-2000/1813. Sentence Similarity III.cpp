// https://zxi.mytechroad.com/blog/string/leetcode-1813-sentence-similarity-iii/
class Solution {
public:
  bool areSentencesSimilar(string s1, string s2) {    
    auto getWords = [](const string& s) {
      stringstream ss(s);
      deque<string> words;
      while (ss) {
        words.emplace_back("");
        ss >> words.back();
      }
      return words;
    };
    deque<string> w1 = getWords(s1), w2 = getWords(s2);
    while (w1.size() && w2.size() && w1.front() == w2.front())
      w1.pop_front(), w2.pop_front();
    while (w1.size() && w2.size() && w1.back() == w2.back())
      w1.pop_back(), w2.pop_back();
    return w1.empty() || w2.empty();
  }
};
