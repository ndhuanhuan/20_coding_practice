class Solution {
public:
    string largestTimeFromDigits(vector<int>& A) {
        sort(A.begin(), A.end());
        
        string res = "";
        do {
            int hour = A[0] * 10 + A[1];
            int min = A[2] * 10 + A[3];
            res = hour <= 23 && min <= 59 ? to_string(A[0]) + to_string(A[1]) + ":" + to_string(A[2]) + to_string(A[3]) : res;
        } while (next_permutation(A.begin(), A.end()));
        
        return res;
    }
};
