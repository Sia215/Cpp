/*A vehicle manufacturing company sought to create a robust system to organize and manage the
details of various cars produced under its brand. To accomplish this, a hierarchical structure was
conceptualized, reflecting the essential components of a vehicle. At the foundation, a class was
designed to represent the type of fuel a vehicle uses. Another class was created to capture the brand
name of the vehicle. These two foundational elements were then combined into a derived class
specifically representing cars, integrating both fuel type and brand information.
Constructors were used at each level to ensure proper initialization of attributes, allowing seamless
integration of all details. Additionally, the ability to display complete information about a car, including
its fuel type and brand, was incorporated into the system. To simulate a real-world scenario such as a
service queue, multiple cars were organized and processed sequentially using a structured approach.
This not only streamlined the handling of cars but also provided an opportunity to compare different
methods of managing the collection and processing of vehicle data.*/

#include<iostream>
using namespace std;
class Fuel_type
{
private:
    string Fuel;
public:
    Fuel_type(string f)
    {
        Fuel=f;
    }
    void Display_Fuel()
    {
        cout<<"Fuel: "<<Fuel<<endl;
    }
};
class Brand
{
private:
    string brand;
public:
    Brand(string b)
    {
        brand=b;
    }
    void Display_Brand()
    {
        cout<<"Brand: "<<brand<<endl;
    }
};
class Car: public Fuel_type, public Brand
{
private:
    string car;
public:
    Car(string f,string b,string c): Fuel_type(f),Brand(b)
    {
        car=c;
    }
    void Display_Car()
    {
        cout<<"Car: "<<car<<endl;
       Display_Fuel();
       Display_Brand();
        cout<<"-------------------------------"<<endl;
    }
};
int main()
{
    int number,i;
    string fuel,brand,car;
    cout<<"Enter the number of cars: "<<endl;
    cin>>number;
    Car** c = new Car*[number];
    for(i=0;i<number;i++)
    {
         cout<<"Enter fuel type: ";
         cin.ignore();
        getline(cin,fuel);
        cout<<"Enter brand: ";
        cin.ignore();
        getline(cin,brand);
        cout<<"Enter car: ";
        cin.ignore();
        getline(cin,car);
        c[i]=new Car(fuel,brand,car);
        c[i]->Display_Car();
    }
    for (i=0;i<number;i++) {
        delete c[i];
    }
    delete[] c;
    return 0;
}
