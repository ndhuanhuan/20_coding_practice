class Solution {
public:
    int largestInteger(int num) {
        vector<int> all(10, 0);
        
        string str = to_string(num);
        
        for(int j = 0; j < str.size(); ++j) {
            int left = str[j] - '0';
            all[left]++;
            cout << left << endl;
        }
        
        
    
        
        int res = 0;
        for(int j = 0; j < str.size(); ++j) {
            int left = str[j] - '0';
            cout << left << endl;
            if(left % 2) {
                // cout << "odd" << endl;
                for(int i = 9; i >=1; i-=2) {
                    // cout << "haha" << all[i] << endl;
                    if(all[i]) {
                        all[i]--;
                        res = res * 10 + i;
                        break;
                    }
                }
            } else {
                // cout << "even" << endl;
                for(int i = 8; i >=0; i-=2) {
                    
                    if(all[i]) {
                        
                        all[i]--;
                        res = res * 10 + i;
                        break;
                    }
                }
            }
        }
        
        return res;
    }
};
