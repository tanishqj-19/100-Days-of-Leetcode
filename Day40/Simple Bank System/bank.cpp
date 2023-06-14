class Bank {
    vector<long long> bal;
    int n = 0;
public:
    Bank(vector<long long>& balance) {
        bal = balance;
        n = balance.size();
    }
    
    bool transfer(int account1, int account2, long long money) {
        if(account1 <= n && account2 <= n && bal[account1-1] >= money){
            bal[account1-1] -= money;
            bal[account2 -1] += money;
            return true;

        }

        return false;
    }
    
    bool deposit(int account, long long money) {
        if(account <= n){
            bal[account-1] += money;
            return true;
        }
        return false;
    }
    
    bool withdraw(int account, long long money) {
        if(account <= n && bal[account-1] >= money){
            bal[account-1] -= money;
            return true; 
        }
        return false;
    }
};
