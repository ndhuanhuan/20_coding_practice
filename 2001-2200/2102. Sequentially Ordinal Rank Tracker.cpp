// https://leetcode.com/problems/sequentially-ordinal-rank-tracker/discuss/1623288/Decrement-Iterator-(4-lines)
class SORTracker {
public:
    set<pair<int, string>> s;
    set<pair<int, string>>::iterator it = end(s);    
    void add(string name, int score) {
        auto it1 = s.insert({-score, name}).first;
        if (it == end(s) || *it1 < *it)
            --it;
    }
    string get() {
        return (it++)->second;
    }
};
/**
 * Your SORTracker object will be instantiated and called as such:
 * SORTracker* obj = new SORTracker();
 * obj->add(name,score);
 * string param_2 = obj->get();
 */
