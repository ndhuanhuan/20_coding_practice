// https://leetcode.com/problems/max-stack/discuss/108962/C%2B%2B-O(logN)-for-write-ops-O(1)-for-reads
class MaxStack {
public:
    list<int> v;
    map<int, vector<list<int>::iterator>, greater<int>> mp;
    
    MaxStack() { 
    }
    
    void push(int x) {
        v.push_front(x);
        mp[x].push_back(v.begin());
    }
    
    int pop() {
        int x = *v.begin();
        mp[x].pop_back();
        if (mp[x].empty()) mp.erase(x);
        v.erase(v.begin());
        return x;
    }
    
    int top() {
        return *v.begin();
    }
    
    int peekMax() {
        return mp.begin()->first;
    }
    
    int popMax() {
        int x = mp.begin()->first;
        auto it = mp[x].back();
        mp[x].pop_back();
        if (mp[x].empty()) mp.erase(x);
        v.erase(it);
        return x;
    }
};
