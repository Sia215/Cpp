
/*A technology firm aimed to develop a flexible and reusable solution for managing collections of various
data types, including integers, floating-point numbers, and characters. The system was intended to
perform fundamental operations on these collections, such as finding the maximum value, reversing
the collection, and displaying all elements. To achieve versatility and avoid redundancy in code, the
solution was designed to use function templates, allowing the same logic to be applied seamlessly to
different data types.
The team recognized the importance of using dynamic arrays to store the collections, enabling
efficient management of varying collection sizes. The design emphasized scalability and flexibility,
ensuring that the system could handle different data types and their associated operations with
minimal changes to the core logic.
In practice, the system allowed for the creation of collections for various data types, such as integers,
floating-point numbers, and characters. The operations on these collections included determining the
maximum value, reversing the order of elements, and printing the collection contents.*/


#include <iostream>
using namespace std;

template <typename T>
void displayElements(T arr[], int size)
{
    cout<<"Original elements: ";
    for(int i = 0; i < size; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

template <typename T>
void maxValue(T arr[], int size)
{
    T max = arr[0];
    for(int i = 0; i < size; i++)
    {
        if(max < arr[i]) max = arr[i];
    }
    cout<<"Max value: "<<max<<endl;
}

template <typename T>
void reverseCollection(T arr[], int size)
{
    for(int i = 0; i < size/2; i++)
    {
        T temp = arr[i];
        arr[i] = arr[size-i-1];
        arr[size-i-1] = temp;
    }

    cout<<"Reversed collection: ";
    for(int i = 0; i < size; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    int choice;

    do{
        cout<<"Select data type:\n1. Integer\n2. Float\n3. Character\n4 to exit\nEnter choice: ";
        cin>>choice;
        switch(choice)
        {
            case 1:
            {
                int arr[100], element;
                int i = 0;
                cout<<"Enter integers (enter 0 to stop):\n";
                while(true)
                {
                    cin>>element;
                    if(element == 0) break;
                    arr[i++] = element;
                }
                if(i == 0) break;
                displayElements(arr, i);
                maxValue(arr, i);
                reverseCollection(arr, i);
                break;
            }

            case 2:
            {
                float arr[100], element;
                int i = 0;
                cout<<"Enter float values (enter 0 to stop):\n";
                while(true)
                {
                    cin>>element;
                    if(element == 0.0) break;
                    arr[i++] = element;
                }
                if(i == 0) break;
                displayElements(arr, i);
                maxValue(arr, i);
                reverseCollection(arr, i);
                break;
            }

            case 3:
            {
                char arr[100], element;
                int i = 0;
                cout<<"Enter characters (enter ! to stop):\n";
                while(true)
                {
                    cin>>element;
                    if(element == '!') break;
                    arr[i++] = element;
                }
                if(i == 0) break;
                displayElements(arr, i);
                maxValue(arr, i);
                reverseCollection(arr, i);
                break;
            }

            case 4:
                cout<<"Thank you!"<<endl;
                break;
            default:
                cout<<"Invalid choice!"<<endl;
        }
    }while(choice!=4);
    cout<<"Siya 24ce125"<<endl;
    return 0;
}
