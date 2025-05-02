/*A software development team aimed to design a versatile utility that could perform basic arithmetic

operations while demonstrating the concept of function overloading. This effort resulted in a class-
based calculator system capable of handling various combinations of input types, such as integers and

floating-point numbers. The system includes multiple overloaded add functions, each tailored to
accept distinct input types and perform addition operations accordingly. This approach ensures the
calculator is adaptable and provides consistent functionality regardless of the input types.
The case revolves around testing and validating the versatility of this calculator. Participants are
expected to create instances of the calculator, invoke the appropriate overloaded functions for various
input scenarios, and store the resulting values for further analysis. To organize and display these
results, the system incorporates methods to sequentially process and present the outcomes.*/


#include<iostream>
#include<vector>

using namespace std;

class calculator
{
public:
    int add(int a, int b)
    {
        return a + b;
    }

    double add(double x, double y)
    {
        return x + y;
    }

    double add(int aa, double bb)
    {
        return aa + bb;
    }
};

int main()
{
    calculator calc;

    vector<double> vec;

    vec.push_back(calc.add(2, 3));
    vec.push_back(calc.add(2.3, 3.3));
    vec.push_back(calc.add(2, 3.5));

    cout << endl << "Using STL approach (vector):";
    for (double element : vec)
    {
        cout << endl << element;
    }

    cout << endl << "Using array:";

    double cal[3];

    cal[0] = calc.add(2, 3);
    cal[1] = calc.add(2.4, 3.3);
    cal[2] = calc.add(2, 3.5);

    for (int i = 0; i < 3; i++)
    {
        cout << endl << cal[i];
    }


    return 0;
}
