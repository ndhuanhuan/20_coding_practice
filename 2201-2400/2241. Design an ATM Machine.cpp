class ATM {
public:
    ATM() {
        for(int i =0 ; i < 5; ++i) {
            cnt.push_back(0);
        }
    }
    
    void deposit(vector<int> banknotesCount) {
        for(int i = 0; i < banknotesCount.size(); ++i) {
            cnt[i] += banknotesCount[i];
        }
        
    }
    
    vector<int> withdraw(int amount) {
        // for(auto ele: cnt) {
        //     cout << ele << endl;
        // }
        // cout << endl;
        
        int left = amount;
        vector<int> tmp(5, 0);
        for(int i = 4; i >= 0; --i) {
            if(cnt[i] > 0) {
                int deduct = left / v[i];
                tmp[i] = min((long long)deduct, (long long)cnt[i]);
                left -= tmp[i] * v[i];  
            }
            if(left == 0) {
                for(int i = 0; i < 5; ++i) {
                    cnt[i] -= tmp[i];
                }
                return tmp;
            }
        }
        return {-1};
    }

private:
    vector<long long> cnt;
    vector<int> v{20, 50, 100, 200, 500};
};


class ATM {
public:
    long long bank[5] = {}, val[5] = {20, 50, 100, 200, 500};
    void deposit(vector<int> banknotesCount) {
        for (int i = 0; i < 5; ++i)
            bank[i] += banknotesCount[i];
    }
    vector<int> withdraw(int amount) {
        vector<int> take(5);
        for (int i = 4; i >= 0; --i) {
            take[i] = min(bank[i], amount / val[i]);
            amount -= take[i] * val[i];
        }
        if (amount)
            return { -1 };
        for (int i = 0; i < 5; ++i)
            bank[i] -= take[i];            
        return take;
    }
};
/**
 * Your ATM object will be instantiated and called as such:
 * ATM* obj = new ATM();
 * obj->deposit(banknotesCount);
 * vector<int> param_2 = obj->withdraw(amount);
 */
