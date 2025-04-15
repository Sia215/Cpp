/*A community bank sought to enhance its account management system with a digital solution to
improve efficiency and provide better customer service. The system was required to manage the
essential details of each account, including the account number, account holder’s name, and balance.
Additionally, the bank wanted to provide a secure mechanism for transferring money between
accounts, allowing customers to easily manage their funds.
The bank also needed a way to track the total number of accounts created, which would be important
for generating reports and understanding the growth of their customer base. This feature was aimed
at helping the bank maintain an overview of their account portfolio and analyze trends over time.
To ensure smooth and reliable operations, the system was designed to store account information in a
way that would allow easy access and updates. When new accounts were created, they would be
added to the system dynamically. The management team planned for future scalability and
performance improvements by considering more efficient storage and retrieval methods after the
initial system was built, ensuring that the bank could easily accommodate more accounts and
transactions as the customer base grew.*/

#include <iostream>
using namespace std;

class BankAccount {
private:
    int accountNumber;
    string name;
    double balance;
    static int totalAccounts;

public:
    BankAccount() {
        accountNumber = 0;
        name = "";
        balance = 0.0;
        totalAccounts++;
    }

    BankAccount(int accNum, string accName, double accBalance){
        accountNumber=accNum;
        name=accName;
        balance=accBalance;
        totalAccounts++;
    }
    void displayDetails() {
        cout<<"Account Number: "<<accountNumber<<"\nName: "<<name<<"\nBalance: "<<balance<<endl;
    }

    static void displayTotalAccounts() {
        cout<<"Total Accounts Created: "<<totalAccounts<<endl;
    }

    friend void transferMoney(BankAccount &from, BankAccount &to, double amount);
};

int BankAccount::totalAccounts = 0;

void transferMoney(BankAccount &from, BankAccount &to, double amount) {
    if (amount > from.balance) {
        cout<<"Transfer Failed! Insufficient Balance in Account: "<<from.accountNumber<<endl;
    } else {
        from.balance -= amount;
        to.balance += amount;
        cout<<"Transfer Successful! "<<amount<<" transferred from Account "<<from.accountNumber<<" to Account "<<to.accountNumber<<endl;
    }
}

int main() {
    BankAccount *accounts[20];
    int count = 0;
    int accountNumber,balance;
    string name;
    char choice;

    do {
        cout<<"Enter details for Account "<<count + 1<<endl;
        cout<<"Enter Account Number: ";
        cin>>accountNumber;
        cout<<"Enter Account Holder Name: ";
        cin.ignore();
        getline(cin, name);
        cout<<"Enter Initial Balance: ";
        cin>>balance;
        accounts[count] = new BankAccount(accountNumber, name, balance);
        count++;
        cout<<"Do you want to add another account? (Y/N): ";
        cin>>choice;
        cout<<endl;
    } while (choice == 'Y' || choice == 'y');

    cout<<"\nACCOUNT DETAILS\n";
    for (int i = 0; i < count; i++) {
        accounts[i]->displayDetails();
    }

    BankAccount::displayTotalAccounts();

    int fromIndex, toIndex;
    double amount;

    cout<<"\nMONEY TRANSFER\n";
    cout<<"Enter Sender Account index (1 to "<<count<<"): ";
    cin>>fromIndex;
    cout<<"Enter Receiver Account index (1 to "<<count<<"): ";
    cin>>toIndex;
    cout<<"Enter Amount to Transfer: ";
    cin>>amount;

    if (fromIndex >=1 && fromIndex <=count && toIndex >=1 && toIndex <=count) {
        transferMoney(*accounts[fromIndex - 1], *accounts[toIndex - 1], amount);
    } else {
        cout<<"Invalid account index!"<<endl;
    }

    cout<<"\nUPDATED ACCOUNT DETAILS\n";
    for (int i = 0; i < count; i++) {
        accounts[i]->displayDetails();
    }

    BankAccount::displayTotalAccounts();

    for (int i = 0; i < count; i++) {
        delete accounts[i];
    }

    cout<<"Siya 24ce125"<<endl;
    return 0;
}
