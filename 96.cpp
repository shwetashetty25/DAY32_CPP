// create a simple bank account class with a method to withdraw money. Throw an exception if the withdrawal amount exceeds the account balance:
#include <iostream>
#include <stdexcept>

using namespace std;

class InsufficientFundsError : public exception
{
public:
    const char *what() const throw()
    {
        return "Insufficient funds in account";
    }
};
class BankAccount
{
private:
    double balance;

public:
    BankAccount(double initialBalance) : balance(initialBalance) {}

    double withdraw(double amount)
    {
        try
        {
            if (amount > balance)
            {
                throw InsufficientFundsError();
            }
            balance -= amount;
            cout << "Withdrawal successful. Remaining balance: " << balance << endl;
            return balance;
        }
        catch (const InsufficientFundsError &e)
        {
            cerr << "Error: " << e.what() << endl;
            return balance;
        }
        catch (const exception &e)
        {
            cerr << "An unexpected error occurred: " << e.what() << endl;
            return balance;
        }
    }
    double deposit(double amount)
    {
        balance += amount;
        cout << "Deposit successful. New balance: " << balance << endl;
        return balance;
    }
    double getBalance() const
    {
        return balance;
    }
};
int main()
{
    BankAccount account(1000.0);
    cout << "Initial balance: " << account.getBalance() << endl;
    account.withdraw(500.0);
    account.withdraw(600.0);

    return 0;
}