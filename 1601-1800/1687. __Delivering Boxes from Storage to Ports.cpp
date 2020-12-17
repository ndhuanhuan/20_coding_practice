
class Solution {
public:
  int boxDelivering(vector<vector<int>>& A, int portsCount, int B, int W) {
        int n = A.size(), need = 0, j = 0, lastj = 0;
        vector<int> dp(n + 1, 200000);
        dp[0] = 0;
        for (int i = 0; i < n; ++i) {
            while (j < n && B > 0 && W >= A[j][1]) {
                B -= 1;
                W -= A[j][1];
                if (j == 0 || A[j][0] != A[j - 1][0]) {
                    lastj = j;
                    need++;
                }
                j++;
            }
            dp[j] = min(dp[j], dp[i] + need + 1);
            dp[lastj] = min(dp[lastj], dp[i] + need);
            B += 1;
            W += A[i][1];
            if (i == n - 1 || A[i][0] != A[i + 1][0]) {
                need--;
            }
        }
        return dp[n];
    }
};



class Solution:
	def boxDelivering(self, A, portsCount, B, W):
		n = len(A)
		
		# need: needed trips from i to j for this shipment
		need = j = lastj = 0
		
		# dp records the minimal number of the trips to deliver i box
		# dp[1] means we delivered the first (0th) box
		dp = [0] + [float('inf')] * n
		
		# i is left pointer, j is the right pointer
		for i in range(n):
			
			# while we haven't run out of boxes and weight capacity
			# we can keep expanding the right pointer j
			while j < n and B > 0 and W >= A[j][1]:
				
				# we reduce the box and weight capacity
				B -= 1
				W -= A[j][1]
				
				# if the port is different from the previous port
				if j == 0 or A[j][0] != A[j - 1][0]:
					# we need to add the number of needed trip by 1
					# lastj moves to current position to mark the start of boxes with different ports
					lastj = j
					need += 1
				
				# keep expanding the right pointer when we can
				j += 1
			
			# greedies solution: if we keep loading as far right as we can
			dp[j] = min(dp[j], dp[i] + need + 1)
			
			# second greedies solution: if we decide to sacrifice a little weight to save a trip
			dp[lastj] = min(dp[lastj], dp[i] + need)
			
			# now as we move the left pointer i forward (don't put the ith box in this trip), 
			# we increase the number of available boxes and available weights
			B += 1
			W += A[i][1]
			
			# if this box is different from the prior box
			# we removed the prior box, so the needed trip is reduced by 1.
			if i == n - 1 or A[i][0] != A[i + 1][0]:
				need -= 1
				
		return dp[-1]
