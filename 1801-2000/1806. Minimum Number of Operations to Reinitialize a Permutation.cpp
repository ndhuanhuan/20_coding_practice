class Solution {
public:
    int reinitializePermutation(int n) {
        vector<int>perm(n), arr(n), original_perm(n);
        for(int i = 0; i < n; i++) perm[i] = i;
        original_perm = perm;
        int cnt = 0;
        while(1){		
            for(int i = 0; i < n; i++) // perform operation as per given rules			
                arr[i] = (i & 1 ? perm[n/2 + (i - 1) / 2] : perm[i / 2]);            
                //                        ^odd case       :  ^even case
            cnt++;  // operation count increases by 1
            if(arr == original_perm) break; // when the permutation becomes to what it originally was, just break and return count
            perm = arr; // repeat till the above condition is satisfied
        }
        return cnt;
    }
};
