/*A team of engineers was tasked with developing a program to calculate and manage the areas of

multiple circles for a design project. To achieve this, they devised a solution using a structured, object-
oriented approach. At the foundation of their solution was a base class that represented a generic

shape, responsible for storing and managing the radius of the circle. Building upon this, a specialized
class for circles was created to extend functionality by introducing a method for calculating the area
of a circle based on its radius. Using this framework, the team designed a system to handle multiple
circles, ensuring that the process of storing, calculating, and displaying the areas was efficient and
adaptable. They explored two different approaches for managing the collection of circles—one
focusing on flexibility and dynamic handling, while the other used a more static structure. By
implementing and comparing these methods, the engineers gained insights into the benefits of using
efficient techniques for organizing and processing geometric data, enhancing their problem-solving
capabilities.*/

#include<iostream>
using namespace std;
class Shape
{
private:
    string shape_name;
    float radius;
public:
    void Get_Data(string name,float radii)
    {
       shape_name=name;
       radius=radii;
    }
    void Display()
    {
        cout<<"The shape of the object: "<<shape_name<<endl;
        cout<<"Radius of th object: "<<radius<<endl;
    }
   inline float Radius_Of_Shape()
    {
        return radius;
    }
};
class Circle: public Shape
{
public:
    float Area_Of_Shape(){
    float Radius=Radius_Of_Shape();
    return 3.14*Radius*Radius;
    }
    void Display_Area()
    {
        cout<<"Area of the circle: "<< Area_Of_Shape()<<endl;
    }

};
int main()
{
    int num;
    cout<<"Enter the number of the circle: "<<endl;
    cin>>num;
    Circle *C1= new Circle[num];
    float radii;
    string name;
    for(int i=0;i<num;i++){
    cout<<"Enter the shape: ";
    cin.ignore();
    getline(cin,name);
    cout<<"Enter the radius: ";
    cin>>radii;
    C1[i].Get_Data(name,radii);
    C1[i].Display();
    C1[i]. Area_Of_Shape();
    C1[i].Display_Area();
    }
    return 0;
}
