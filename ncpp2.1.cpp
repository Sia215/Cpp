/*A local construction company frequently deals with rectangular plots and structures of varying
dimensions. To streamline their planning and estimation processes, the company requires a simple
system to manage and analyze rectangular shapes efficiently.
The system must be able to handle multiple rectangles, each with distinct dimensions. For each
rectangle, the length and width need to be defined and stored securely. Additionally, the company
needs the ability to calculate two key metrics for any given rectangle:
The area, to estimate usable space or material coverage. The perimeter, to estimate boundary lengths
or material requirements for edges. To make this system functional, there should be a way to define
or update the dimensions of any rectangle as required. The system should be capable of creating and
managing multiple rectangle records, performing calculations for each, and displaying the results
clearly for analysis and planning purposes.*/

#include<iostream>
using namespace std;

class rectangle
{
    int length,width;

public:

    void Dimensions(int l,int w)
    {
        length=l;
        width=w;
    }
     int area()
     {
         return length*width;
     }

     int perimeter()
     {
         return 2*(length+width);
     }

};
 int main()
 {
     int i,l,w,n;
     cout<<"Enter the number of rectangles you want to calculate:"<<endl;
     cin>>n;

     rectangle r[n];




     for(i=0;i<n;i++)
     {
        cout<<"Enter the length : "<<endl;
        cin>>l;
        cout<<"Enter the width :"<<endl;
        cin>>w;

        r[i].Dimensions(l,w);
        cout<<"Area of rectangle :"<<r[i].area()<<endl;
        cout<<"Perimter of rectangle :"<<r[i].perimeter()<<endl;
        cout<<"--------------------------------"<<endl;
     }
 }

