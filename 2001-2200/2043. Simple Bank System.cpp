class Bank {
public:
    vector<long long> b;
    Bank(vector<long long>& balance) { swap(b, balance); }
    bool transfer(int account1, int account2, long long money) {
        if (account2 <= b.size() && withdraw(account1, money))
            return deposit(account2, money);
        return false;
    }
    bool deposit(int account, long long money) {
        if (account <= b.size()) {
            b[account - 1] += money;
            return true;
        }
        return false;
    }
    bool withdraw(int account, long long money, bool check = false) {
        if (account <= b.size() && b[account - 1] >= money) {
            b[account - 1] -= money;
            return true;
        }
        return false;
    }
};
/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */
