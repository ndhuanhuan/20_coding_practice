// https://zxi.mytechroad.com/blog/recursion/leetcode-1600-throne-inheritance/
class ThroneInheritance {
public:
  ThroneInheritance(string kingName): king_(kingName) {
    m_[kingName] = {};
  }
 
  void birth(string parentName, string childName) {
    m_[parentName].push_back(childName);
  }
 
  void death(string name) {
    dead_.insert(name);
  }
 
  vector<string> getInheritanceOrder() {
    vector<string> ans;
    function<void(const string&)> dfs = [&](const string& name) {
      if (!dead_.count(name)) ans.push_back(name);
      for (const string& child: m_[name]) dfs(child);
    };
    dfs(king_);
    return ans;
  }
private:  
  string king_;  
  unordered_map<string, vector<string>> m_; // parent -> list[children]
  unordered_set<string> dead_;
};
/**
 * Your ThroneInheritance object will be instantiated and called as such:
 * ThroneInheritance* obj = new ThroneInheritance(kingName);
 * obj->birth(parentName,childName);
 * obj->death(name);
 * vector<string> param_3 = obj->getInheritanceOrder();
 */
