/*A data analytics company was tasked with developing a unique digital signature system based on the
concept of "super digits." The system required finding a single-digit representation of a given number
through recursive digit summation. The algorithm was defined as follows:
If the number has only one digit, it is its super digit. Otherwise, the super digit is the super digit of the
sum of its digits, repeated recursively until a single digit is obtained.
The challenge involved an additional complexity—constructing the number by concatenating a given
string representation of an integer multiple times. For example, if the number n was represented as a
string and concatenated k times, the super digit of the resulting number needed to be calculated.
For instance:
Given n = 9875 and k = 4, the number is represented as 9875987598759875.
The sum of digits in this number is calculated recursively until a single digit remains:
9 + 8 + 7 + 5 + 9 + 8 + 7 + 5 + 9 + 8 + 7 + 5 + 9 + 8 + 7 + 5 = 116
1 + 1 + 6 = 8
The super digit is 8.
The system was required to handle large numbers efficiently by leveraging mathematical insights
rather than explicitly constructing large concatenated strings. This case study called for implementing
a recursive solution to calculate the super digit, supported by a mathematical approach to optimize
the handling of repeated sums.*/


#include<iostream>
using namespace std;
int Super_Digit(long s) {
    if(s<10)
    {
        return s;
    }
    long sum=0;
    while(s>0)
    {
        sum+=s%10;
        s/=10;
    }
    return Super_Digit(sum);
}

int main() {
    int size;
    cout<<"Enter the size: "<<endl;
    cin>>size;
    char* n=new char[size];
    int k;
    cout<<"Enter the number string: ";
    cin>>n;
    cout<<"Enter the repetition count: ";
    cin>>k;
    long Digit_Sum=0;
    for (int i=0;n[i]!='\0';++i)
    {
        Digit_Sum+=n[i]-'0';
    }
    Digit_Sum*=k;

    int result=Super_Digit(Digit_Sum);

    cout<<"Super Digit: "<<result<<endl;

    delete[] n;

    cout<<"Siya thakkar 24ce125"<<endl;

    return 0;
}

