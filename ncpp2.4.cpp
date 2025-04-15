
/*A mid-sized retail store faced challenges in efficiently managing its inventory of items. The store's
management sought to build a system that could keep track of individual items, including details like
a unique item ID, item name, price, and the quantity available in stock. The need for a streamlined
process arose due to frequent stock discrepancies, which led to issues with customer satisfaction and
operational efficiency.
To address this, the store hired a team of developers to create a digital inventory management system.
The envisioned solution would allow for the initialization of item details, either with default values or
specific attributes like ID, name, price, and starting quantity. This system needed to handle operations
like increasing stock levels when new shipments arrived and decreasing stock when items were sold,
ensuring sufficient inventory was available for each transaction. Additionally, the system would
provide clear, detailed summaries of each item's status, aiding in decision-making and reporting.
The developers faced real-world scenarios where they had to manage multiple inventory items
simultaneously. They planned to design an array of inventory items and simulate common tasks such
as adding stock, processing sales transactions, and displaying the current inventory details. Handling
edge cases, such as attempting to sell more items than available in stock, became a critical part of the
implementation to ensure reliability.*/

#include<iostream>
#include<string>
using namespace std;
class item_data
{

    int item_id;
    string item_name;
    float item_prize;
    int item_quantity;

    public:

        void get_data(int id,string name,int quantity,float prize)
        {
          item_id=id;
          item_name=name;
          item_prize=prize;
          item_quantity=quantity;
        }
        int buy(int ID,int Q)
        {
           if(item_id==ID)
           {
               if(item_quantity>=Q)
               {
               item_quantity=item_quantity-Q;
               }
               else{
                   cout<<"SORRY FOR THE INCONVINENCE BUT WE ONLY HAVE "<<item_quantity<<"QUANTITY AVAILABLE."<<endl;
               }
           }
               else{
                cout<<"NO SUCH PRODUCT FOUND"<<endl;
               }

        }
          void display()
          {
              cout<<"The product id is : "<<item_id<<endl;
              cout<<"The quantity of the product is: "<<item_quantity<<endl;
          }


};
int main()
{
    int id,quantity,i;
    float prize;
    string name;
    char input;
    item_data I[100];
    cout<<"WELCOME TO THE STORE"<<endl;
    do{
    cout<<"Enter A to add data in stock \nEnter B to buy something\n Enter D to display current data \n Enter E to exit: \n";
    cin>>input;
    switch(input)
    {
    case 'A':
        cout<<"Enter the ID number of the product: ";
        cin>>id;
        cout<<"Enter the Name of the product: ";
        cin.ignore();
        getline(cin,name);
        cout<<"Enter the quantity of the product: ";
        cin>>quantity;
        cout<<"Enter the prize of the quantity: ";
        cin>>prize;
        cout<<"----------------------------------------------"<<endl;
        for(i=0;i<100;i++)
        {
        I[i].get_data(id,name,quantity,prize);
        }
        break;
    case 'B':
        cout<<"Enter the ID number of the product to buy: ";
        cin>>id;
        cout<<"Enter the quantity of the product to buy: ";
        cin>>quantity;
        for(i=0;i<100;i++)
        {
        I[i].buy(id,quantity);
        }
        break;
    case 'D':
          cout<<"HERE IS YOUR DATA: "<<endl;
          for(i=0;i<100;i++)
          {
        I[i].display();
          }
        break;

}
    }while(input!='E');
    cout<<endl<<"Siya thakkar 24ce125";
}
