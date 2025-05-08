/*Imagine you're developing a financial calculator for a bank's system that allows users to calculate the

ratio of two monetary values they input. This tool must be reliable, as it's part of a crucial decision-
making process for loan eligibility.

A bank customer is required to enter two values directly into the system:
1. The first value represents the total loan amount they wish to apply for.
2. The second value represents their annual income.
The system will compute and display the ratio of the loan amount to the income, which helps the bank
assess the customer's loan-to-income ratio.
Major challenges that developer will face while developing the system would be, if the customer
mistakenly enters non-numerical characters (e.g., "abc"), the system should handle the situation
gracefully and prompt the user to correct their input. If the customer enters 0 as their annual income,
the system must identify this issue and avoid performing a division that would lead to an invalid result.*/

#include <iostream>
using namespace std;
int main() {
    float loanAmount;
    float income;
    cout << "Enter the loan amount: ";
    while (!(cin >> loanAmount) || loanAmount < 0) {
        cout << "Invalid input. Please enter a positive number: ";
        cin.clear();
        cin.ignore();
    }
    cout << "Enter your annual income: ";
    while (!(cin >> income) || income <= 0) {
        if (cin.fail()) {
            cout << "Invalid input. Please enter a positive number: ";
        } else if (income == 0) {
            cout << "Income cannot be zero. Enter a valid income: ";
        } else {
            cout << "Income must be a positive number: ";
        }
        cin.clear();
        cin.ignore();
    }
    float ratio = loanAmount / income;
    cout << "\nYour loan-to-income ratio is: " << ratio << endl;
    return 0;
}
