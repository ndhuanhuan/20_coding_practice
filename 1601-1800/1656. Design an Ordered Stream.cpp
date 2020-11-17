// https://zxi.mytechroad.com/blog/data-structure/leetcode-1656-design-an-ordered-stream/
class OrderedStream {
public:
  OrderedStream(int n): data_(n + 1) {}
 
  vector<string> insert(int id, string value) {
    data_[id] = value;
    vector<string> ans;
    if (ptr_ == id)
      while (ptr_ < data_.size() && !data_[ptr_].empty())
        ans.push_back(data_[ptr_++]);
    return ans;
  }
private:
  int ptr_ = 1;
  vector<string> data_;
};
/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(id,value);
 */
