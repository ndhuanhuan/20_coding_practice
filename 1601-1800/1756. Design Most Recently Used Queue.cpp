
// https://leetcode.com/problems/design-most-recently-used-queue/discuss/1061478/C%2B%2B-beat-100-BIT-%2B-map
class MRUQueue {
private:
    const static int TOTAL = 4001;
    unordered_map<int, int> m;
    vector<int> datas;
    int last = 0;
    void set(int i, int diff) {
        while(i <= TOTAL) {
            datas[i] += diff;
            i += (i & -i);
        }
    }
    int get(int i) {
        int res = 0;
        while(i > 0) {
            res += datas[i];
            i -= (i & -i);
        }
        return res;
    }
public:
    MRUQueue(int n) : datas(TOTAL, 0) {
        for(int i = 1; i <= n; ++i) {
            set(i, 1);
            m[i] = i;
        }
        last = n + 1;
    }
    
    int fetch(int k) {
        int l = 0, r = last;
        //l < target <= r
        while(r - l > 1) {
            int mid = (r-l)/2 + l;
            if (get(mid) < k) {
                l = mid;
            } else r = mid;
        }
        int v = m[r];   // get mapped value
        m.erase(r);    // delete mapping
        m[last++] = v; // update map
        set(r, -1); // BIT set 1 to 0
        set(last-1, 1); // BIT set last element to 1
        return v;
    }
};
