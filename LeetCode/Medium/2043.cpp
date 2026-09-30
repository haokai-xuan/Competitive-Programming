class Bank {
    vector<long long> b;
    int n;
public:
    Bank(vector<long long>& balance) {
        b = balance;
        n = balance.size();
    }
    
    bool transfer(int account1, int account2, long long money) {
        if (account1 >= n + 1 || account2 >= n + 1 || b[account1 - 1] < money)
            return false;
        b[account1 - 1] -= money;
        b[account2 - 1] += money;
        return true;
    }
    
    bool deposit(int account, long long money) {
        if (account >= n + 1)
            return false;
        b[account - 1] += money;
        return true;
    }
    
    bool withdraw(int account, long long money) {
        if (account >= n + 1 || b[account - 1] < money)
            return false;
        b[account - 1] -= money;
        return true;
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */