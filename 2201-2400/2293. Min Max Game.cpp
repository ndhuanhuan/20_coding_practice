class Solution {
public:
    int minMaxGame(vector<int>& nums) {
        // int n = nums.size();
        vector<int> tmp = std::move(nums);
        vector<int> tmp2;
        while(tmp.size() > 1) {
            int n = tmp.size();
            for(int i = 0; i < n / 2; ++i) {
                if(i % 2 == 0) {
                    tmp2.push_back(min(tmp[i*2], tmp[i*2+1]));
                } else {
                    tmp2.push_back(max(tmp[i*2], tmp[i*2+1]));
                }

            }
            // for(auto nn: tmp2) {
            //     cout << nn << endl;
            // }
            if(tmp2.size() == 1) return tmp2[0];
            tmp.swap(tmp2);
            tmp2.clear();
        }
        return tmp[0];
    }
};
