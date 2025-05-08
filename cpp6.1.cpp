/*In a rapidly growing software development firm, a team of engineers is tasked with building a
lightweight, custom memory management system for handling dynamic datasets. The existing
framework lacks flexibility in managing arrays, often leading to inefficient memory usage and
performance bottlenecks. To address this, the engineers need to develop a solution that allows
seamless insertion and deletion of elements while ensuring efficient memory utilization.
The primary challenge is to design a structure that supports adding new data points dynamically at
the end of the dataset and removing specific elements based on their position. Since the system
operates in a resource-constrained environment, using standard template libraries is not an option,
and direct dynamic memory management must be implemented using pointers. The solution should
ensure that memory is allocated and deallocated appropriately to prevent leaks and unnecessary
overhead.
The development team must carefully decide on the structure of their implementation, defining how
data will be stored, accessed, and modified efficiently. They need to outline the appropriate class
design, determine essential data members, and define necessary member functions to handle the
operations effectively.*/


#include<iostream>
using namespace std;

class Dynamic_memory
{
    int size,capacity;
    int *data;

    void resize()
    {

    cout<<"Resize arrray";
    capacity*=2;
    int *newdata=new int[capacity];
    for(int i=0;i<size;i++)
    {
        newdata[i]=data[i];
    }
    delete[] data;
    data=newdata;
    }



  public:

    Dynamic_memory(int Initialcapacity=4)
    {
        size=0;
        capacity=Initialcapacity;
        data=new int[capacity];
    }
    ~Dynamic_memory()
    {
       delete[] data;
    }
    void insert(int val)
    {
        if(size==capacity)
        {
            resize();
        }
        else
        {
            data[size++]=val;
        }
    }

    void remove(int index)
    {
        if(index<0 ||  index>=size)
        {
            cout<<"Invalid Index";

        }
        for(int i=index;i<size-1;i++)
        {
            data[i]=data[i+1];

        }
        size--;
    }

        int get(int index)
        {
           if(index<0 || index>=size)
           {
               cout<<"invalid index";
               return -1;
           }
           else
           {
               return data[index];
           }

        }
        void printarray()
        {
            for(int i=0;i<size;i++)
            {
                cout<<data[i]<<" ";
            }
            cout<<endl;
        }



};
int main()
{
    Dynamic_memory arr;

    arr.insert(10);
    arr.insert(20);
    arr.insert(30);
    arr.insert(40);

    arr.printarray();

    arr.insert(10);
    arr.insert(20);
    arr.insert(30);

    cout<<"Get element at index 1  "<<arr.get(1)<<endl;
    arr.printarray();
    cout<<"Remove element at index 1  "<<endl;
    arr.remove(1);
    arr.printarray();




}

