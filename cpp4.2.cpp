/*A growing organization wanted to develop a system to manage its hierarchy and represent its
structure in a programmatic way. To achieve this, a multilevel approach was designed, reflecting the
natural progression of roles within the organization. At the foundation, a class was created to
represent a person, capturing the basic details such as name and age. Building on this, an intermediate
level was introduced to represent employees, adding a unique identifier for each. Finally, at the
topmost level, a class for managers was created, which included additional details such as the
department they oversee.
The system needed to handle the initialization of all these attributes through constructors at each
level, ensuring the proper propagation of information across the hierarchy. Additionally, the
functionality to display details at every level was included to provide clear insights into the
organization's structure. Two approaches were explored for managing multiple managers: one relied
on an efficient method for retrieval and organization based on employee identifiers, while the other
used a straightforward and static method for storage.*/

#include<iostream>
using namespace std;
class Person
{
    protected:
    int person_age;
    string person_name;
public:
    Person(string name,int age)
    {
        person_age=age;
        person_name=name;
    }
    void Display_Data()
    {
        cout<<"Name: "<<person_name<<endl;
        cout<<"Age: "<<person_age<<endl;
    }
};
class Manager: public Person
{
protected:
    int  manager_id;
    string department;
public:
    Manager(string name, int age, int id, string dept) : Person(name, age)
    {
        manager_id=id;
        department=dept;
    }
    void Display()
    {
        cout<<"Manager id: "<<manager_id<<endl;
        cout<<"Department: "<<department<<endl;
    }
};
class Employee: public Manager
{

    public:
         Employee(string name,int age,int id,string dept)
        : Manager(name,age,id,dept) {}

    void Show_Details() {
        Display_Data();
        Display();
    }
};
int main()
{
    int age,id,num,i;
    string name,dept;
    cout<<"Enter the number of employee: "<<endl;
    cin>>num;
    Employee **E=new Employee*[num];
    for(i=0;i<num;i++)
    {
    cout<<"Enter the name: ";
    cin.ignore();
    getline(cin,name);
    cout<<"Enter the age: ";
    cin>>age;
    cout<<"Enter the id: ";
    cin>>id;
    cout<<"Enter the department: ";
    cin.ignore();
    getline(cin,dept);
    E[i]=new Employee(name,age,id,dept);
    }
    for(i=0;i<num;i++)
    {
        cout<<"--------------------------"<<endl;
        E[i]->Show_Details();
    }
    return 0;
}
