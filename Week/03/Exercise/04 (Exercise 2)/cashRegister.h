class cashRegister
{
    private:
        double cashOnHand;
    public:
        cashRegister();
        void acceptAmount(double);
        double printBalance();
};
cashRegister::cashRegister()
{
    cashOnHand = 500.00;
}
void cashRegister::acceptAmount(double amount)
{
    cashOnHand += amount;
}
double cashRegister::printBalance()
{
    return cashOnHand;
}