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
