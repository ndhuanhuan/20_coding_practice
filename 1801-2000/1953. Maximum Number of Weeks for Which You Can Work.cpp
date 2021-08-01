// https://leetcode.com/problems/maximum-number-of-weeks-for-which-you-can-work/discuss/1375381/C%2B%2B-max-element-solution.-Greedy
class Solution {
public:
    long long numberOfWeeks(vector<int>& milestones) {
        int mx = *max_element(milestones.begin(), milestones.end());
        long long sum = 0;
        for(int i = 0; i < milestones.size(); i++) {
            sum += (long long) milestones[i];
        }
        long long rest = sum - (long long)mx;
        return min({rest * 2 + 1, sum});
    }
};
