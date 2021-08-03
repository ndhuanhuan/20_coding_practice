// https://leetcode.com/problems/describe-the-painting/discuss/1359717/Python-Easy-solution-in-O(n*logn)-with-detailed-explanation
// https://leetcode.com/problems/describe-the-painting/discuss/1359815/JavaC%2B%2BPython-Sweep-Line
class Solution {
public:
    vector<vector<long long>> splitPainting(vector<vector<int>>& A) {
        map<int, long long> d;
        for (auto& a : A) {
            d[a[0]] += a[2];
            d[a[1]] -= a[2];
        }
        vector<vector<long long> > res;
        int i = 0;
        for (auto& it : d) {
            cout << it.first << " " << it.second << endl;
            if (d[i] > 0) { // if previous seg > 0, push
                // cout << "push" << endl;
                res.push_back({i, it.first, d[i]}); // previous segment location, current location
            }
                
            d[it.first] += d[i]; // d[current segment] update value
            i = it.first; // previous segment location = current location
        }
        return res;
    }
};

// https://leetcode.com/problems/describe-the-painting/discuss/1359720/Line-Sweep
class Solution {
public:
    vector<vector<long long>> splitPainting(vector<vector<int>>& segments) {
        long long mix[100002] = {}, sum = 0, last_i = 0;
        bool ends[100002] = {};
        vector<vector<long long>> res;
        for (auto &s : segments) {
            mix[s[0]] += s[2];
            mix[s[1]] -= s[2];
            ends[s[0]] = ends[s[1]] = true;
        }
        for (int i = 1; i < 100002; ++i) {
            if (ends[i] && sum)
                res.push_back({last_i, i, sum});
            last_i = ends[i] ? i : last_i;
            sum += mix[i];
        }
        return res;
    }
};
