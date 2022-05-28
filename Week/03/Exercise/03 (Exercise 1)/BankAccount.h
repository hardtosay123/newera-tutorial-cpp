class BankAccount
{
    private:
        double balance;
        double interest_rate;
    public:
        void set(int, int);
        void update();
        double get_balance();
        double get_rate();
        void set_rate(int);
};
void BankAccount::set(int dollars, int cents)
{
    balance = dollars + cents/100.0;
}
void BankAccount::update()
{
    balance *= (interest_rate/100);
}
double BankAccount::get_balance()
{
    return balance;
}
double BankAccount::get_rate()
{
    return interest_rate;
}
void BankAccount::set_rate(int rate)
{
    interest_rate = (double) rate;
}