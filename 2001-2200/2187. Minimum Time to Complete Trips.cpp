class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        int maxV = *max_element(time.begin(), time.end());
        long long int l = 1;
        long long int r = 1e14;
        while(l < r) {
            
            long long int mid = l + (r - l) / 2;
            // cout << "l:" << l << endl;
            // cout << "r:" << r << endl;
            // cout << "mid:" << mid << endl;
            long long int curTrip = check(time, mid);
            // cout << "curTrip:" << curTrip << endl;

            if(curTrip >= totalTrips) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        
        return l;
    }
    
    long long int check(vector<int>& time, long long int mid) {
        long long int res = 0;
        for(auto t: time) {
            long long int x = t;
            res += mid / x;
        }
            
        return res;
    }
};
