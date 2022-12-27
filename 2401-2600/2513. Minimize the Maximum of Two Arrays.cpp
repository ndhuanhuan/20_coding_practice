// https://leetcode.com/problems/minimize-the-maximum-of-two-arrays/discuss/2946621/C%2B%2BorJavaorPython3-binary-search
class Solution {
public: 
	int minimizeSet(int divisor1, int divisor2, int uniqueCnt1, int uniqueCnt2) {
		long lo = 0, hi = INT_MAX, mult = lcm((long) divisor1, divisor2); 
		while (lo < hi) {
			int mid = lo + (hi-lo)/2; 
			if (uniqueCnt1 <= mid-mid/divisor1 && uniqueCnt2 <= mid-mid/divisor2 && uniqueCnt1+uniqueCnt2 <= mid-mid/mult) hi = mid; 
			else lo = mid+1; 
		}
		return lo; 
	}
};
