// https://zxi.mytechroad.com/blog/leetcode/leetcode-weekly-contest-133/
class TrieNode {
public:        
  ~TrieNode() {
    for (auto node : next_)
      delete node;
  }
 
  void reverse_build(const string& s, int i) {
    if (i == -1) {
      is_word_ = true;
      return;
    }
    const int idx = s[i] - 'a';
    if (!next_[idx]) next_[idx] = new TrieNode();
    next_[idx]->reverse_build(s, i - 1);
  }
  
  bool reverse_search(const string& s, int i) {
    if (i == -1 || is_word_) return is_word_;
    const int idx = s[i] - 'a';
    if (!next_[idx]) return false;
    return next_[idx]->reverse_search(s, i - 1);
  }
 
private:
  bool is_word_ = false;
  TrieNode* next_[26] = {0};
};
 
class StreamChecker {
public:
  StreamChecker(vector<string>& words) {
    root_ = std::make_unique<TrieNode>();
    for (const string& w : words)
      root_->reverse_build(w, w.length() - 1);
  }
 
  bool query(char letter) {
    s_ += letter;
    return root_->reverse_search(s_, s_.length() - 1);    
  }
  
private:
  string s_;
  unique_ptr<TrieNode> root_;
};
