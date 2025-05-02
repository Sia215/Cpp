/*In a bid to design an efficient and user-friendly banking system, a structure was proposed that mirrors
the real-world operations of various account types. The foundation of the system is a base class
representing a generic bank account, encapsulating essential details such as account number and
balance. Building on this foundation, two specialized account types were created: a savings account,
which includes an interest rate as an additional feature, and a current account, which allows an
overdraft limit to accommodate specific customer needs.
To ensure proper initialization and cleanup of account objects, constructors and destructors were
implemented. Essential banking operations such as deposits and withdrawals were made available for
both account types, allowing users to perform and manage their transactions effectively. The system
also accounted for the need to track and manage transaction history, enabling operations such as
undoing the last transaction. This was achieved by simulating a mechanism to store a sequence of
transactions for each account type, providing insight into different ways of managing and organizing
data.*/

#include<iostream>
using namespace std;
const int Max_Transaction=6;
class Current_Account;
class Saving_Account;
class Bank_Account {
protected:
    string account_number;
    char transaction_type[Max_Transaction];
    double transaction_amount[Max_Transaction];
    int transaction_count;
    double balance;
public:
    Bank_Account(string acc_number, double bal) {
        account_number = acc_number;
        balance = bal;
        transaction_count = 0;
    }

    virtual ~Bank_Account() {
    }

    virtual void Deposit_Amount(double amount) {
        balance += amount;
        if (transaction_count < Max_Transaction) {
            transaction_type[transaction_count] = 'D';
            transaction_amount[transaction_count] = amount;
            transaction_count++;
        }
    }

    virtual int Withdraw_Amount(double amount) {
        if (balance >= amount) {
            balance -= amount;
            if (transaction_count < Max_Transaction) {
                transaction_type[transaction_count] = 'W';
                transaction_amount[transaction_count] = amount;
                transaction_count++;
            }
            return 1;
        } else {
            cout << "Insufficient balance." << endl;
            return 0;
        }
    }
    virtual void Undo_Last_Transaction() {
        if (transaction_count == 0) {
            cout << "No transaction to undo." << endl;
            return;
        }

        transaction_count--;
        if (transaction_type[transaction_count] == 'D') {
            balance -= transaction_amount[transaction_count];
        } else if (transaction_type[transaction_count] == 'W') {
            balance += transaction_amount[transaction_count];
        }
    }

    virtual void Display_Data() {
        cout << "Account Number: " << account_number << endl;
        cout << "Current Balance: " << balance << endl;
    }
};
class Saving_Account : public Bank_Account {
private:
    double interest_rate;
public:
    Saving_Account(string acc_number, double bal, double rate)
        : Bank_Account(acc_number, bal) {
        interest_rate = rate;
    }

    void Apply_Interest()
    {
        double interest = balance * interest_rate;
        Deposit_Amount(interest);
    }

    void Display_Data() {
        Bank_Account::Display_Data();
        cout << "Interest Rate: " << interest_rate * 100<< endl;
    }
};
class Current_Account : public Bank_Account {
private:
    double over_draft_limit;

public:
    Current_Account(string acc_number, double bal, double overdraft)
        : Bank_Account(acc_number, bal) {
        over_draft_limit = overdraft;
        cout << "CurrentAccount created with overdraft limit: " << over_draft_limit << endl;
    }

    int Withdraw_Amount(double amount) {
        if (balance + over_draft_limit >= amount) {
            balance -= amount;
            if (transaction_count < Max_Transaction) {
                transaction_type[transaction_count] = 'W';
                transaction_amount[transaction_count] = amount;
                transaction_count++;
            }
            return 1;
        } else {
            cout<<"Exceeded overdraft limit." << endl;
            return 0;
        }
    }
    void Display_Data() {
        Bank_Account::Display_Data();
        cout << "Overdraft Limit: " << over_draft_limit << endl;
    }
};
int main() {
    Bank_Account* account = NULL;
    int account_type;
    string acc_number;
    double initial_balance;
    int choice;
    double amount;
    cout<<"Choose account type:\n1. Savings Account\n2. Current Account\nChoice: ";
    cin>>account_type;
    cout<<"Enter account number: ";
    cin>>acc_number;
    cout<<"Enter initial balance: ";
    cin>>initial_balance;
    if (account_type == 1) {
        double rate;
        cout<<"Enter interest rate: ";
        cin>>rate;
        account=new Saving_Account(acc_number, initial_balance, rate);
    }
    else if (account_type == 2) {
        double overdraft;
        cout<<"Enter overdraft limit:";
        cin>>overdraft;
        account= new Current_Account(acc_number, initial_balance, overdraft);
    }
     else {
        cout<<"Invalid type" << endl;
        return 1;
    }
    do {
        cout<<"\nChoose an operation:\n 1. Deposit Amount\n 2. Withdraw Amount\n 3. Undo Last Transaction\n 4. Display Data Account Details\n 5. Apply Interest\n 0. Exit\n";
        cout<<"Choice: ";
        cin>>choice;
        switch(choice) {
            case 1:
                cout<<"Enter Deposit amount: ";
                cin>>amount;
                account->Deposit_Amount(amount);
                break;
            case 2:
                cout<<"Enter Withdraw amount:";
                cin>> amount;
                account->Withdraw_Amount(amount);
                break;
            case 3:
                account->Undo_Last_Transaction();
                break;
            case 4:
                account->Display_Data();
                break;
            case 5:
                if (account_type==1) {
                    ((Saving_Account*)account)->Apply_Interest();
                }
                else {
                    cout<<"Invalid choice."<<endl;
                }
                break;
        }
    } while(choice != 0);
    delete account;
    return 0;
}
