/*In a growing city, a newly established bank sought to streamline its operations by implementing a
digital system to manage customer accounts. The management envisioned a system where each
account would store details about the account holder, their unique account number, and the current
balance. To ensure flexibility and accuracy, they required functionalities for creating accounts with
varying initial balances, depositing money, withdrawing funds (with checks for sufficient balance), and
generating detailed account summaries.
The bank's IT team faced the challenge of developing a robust solution. They began by sketching out
the essential features of the system. The team highlighted that new accounts could be created in two
ways: one with no initial balance, and another with specified account details and a starting amount.
Additionally, they recognized the need for reliable mechanisms to handle deposits and withdrawals,
ensuring proper validation to prevent overdrafts. Displaying account details in a clear format was also
prioritized for customer communication.
To ensure scalability, the team decided to simulate the system by creating multiple accounts using the
proposed methods. They tested various scenarios, such as depositing and withdrawing different
amounts, handling edge cases like insufficient funds, and verifying that the account summaries were
accurate. This iterative approach helped them refine the system and ensure its readiness for
deployment.*/

#include <iostream>
using namespace std;

class Account_Details {
    string holder_name;
    int account_no;
    int current_bal;

public:
    void get_data(string n, int id, int bal) {
        holder_name = n;
        account_no = id;
        current_bal = bal;
    }

    int search_id(int id) {
        if (account_no == id) {
            return 1;
        } else {
            return 0;
        }
    }

    void deposit(int amt) {
        current_bal += amt;
        cout << "Amount deposited successfully!";
    }

    void withdraw(int amt) {
        if (amt < current_bal) {
            current_bal -= amt;
            cout << "Sucessful Transition";
        } else {
            cout << "Sufficient balance not available.";
        }
    }

    void display() {
        cout << "Account Holder Name : " << holder_name<<endl;
        cout << "Account Number : " << account_no<<endl;
        cout << "Current Balance : " << current_bal<<endl;
        cout << "\n----------------------------------------------";
    }
};

int main() {
    Account_Details c[50];
    int counter = 0, id, bal, choice, choice1, choice2, amt;
    string n;

add_more:
    cout << "Enter the account number : ";
    cin >> id;
    cout << "Enter the current account balance : ";
    cin >> bal;
    cout << "Enter the account holder name : ";
    cin >> n;
    c[counter].get_data(n, id, bal);
    counter++;

    cout << "\nEnter 1 to add more else 0 to proceed : ";
    cin >> choice;
    if (choice == 1) {
        goto add_more;
    } else {
        while (true) {
            cout << "\nEnter 1 to withdraw\nEnter 2 to deposit\nEnter 3 to display account details\nEnter 4 to exit : ";
            cin >> choice1;
            switch (choice1) {
                case 1:
                    cout << "Enter the account number : ";
                    cin >> id;
                    for (int i = 0; i < counter; i++) {
                        if (c[i].search_id(id) == 1) {
                            cout << "Enter the amount to withdraw :";
                            cin >> amt;
                            c[i].withdraw(amt);
                            break;
                        } else if (c[i].search_id(id) == 0) {
                            if (i == counter - 1) {
                                cout << "Account number not found.";
                            } else {
                                continue;
                            }
                        }
                    }
                    break;

                case 2:
                    cout << "Enter the account number : ";
                    cin >> id;
                    for (int i = 0; i < counter; i++) {
                        if (c[i].search_id(id) == 1) {
                            cout << "Enter the amount to deposit  :";
                            cin >> amt;
                            c[i].deposit(amt);
                            break;
                        } else if (c[i].search_id(id) == 0) {
                            if (i == counter - 1) {
                                cout << "Account number not found.";
                            } else {
                                continue;
                            }
                        }
                    }
                    break;

                case 3:
                    cout << "Enter 1 to display a specific account's details or 0 to show all: ";
                    cin >> choice2;
                    if (choice2 == 1) {
                        cout << "Enter the account number : ";
                        cin >> id;
                        for (int i = 0; i < counter; i++) {
                            if (c[i].search_id(id) == 1) {
                                c[i].display();
                                break;
                            } else if (c[i].search_id(id) == 0) {
                                if (i == counter - 1) {
                                    cout << "Account Number Not Found.";
                                } else {
                                    continue;
                                }
                            }
                        }
                    } else {
                        for (int i = 0; i < counter; i++) {
                            c[i].display();
                        }
                    }
                    break;

                case 4:
                    cout << "Thank you, visit again!\n";
                    goto end;
                    break;

                default:
                    cout << "Invalid choice provided.";
            }
        }
    }

end:
    cout << endl << "Siya Thakkar 24ce125";
    return 0;
}
