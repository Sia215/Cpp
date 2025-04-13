/*A university managing academic data for its students. The administration seeks to digitize the records
of student performance, including personal and academic details. The system must store each
student's roll number, name, and marks in three subjects. Additionally, it should provide
functionalities to calculate and display the average marks for performance analysis.
The institution's IT team proposed a solution where student records could be initialized in two ways:
either with default values for testing purposes or by accepting specific input details for each student.
Once initialized, the system would allow for viewing comprehensive student details, including their
roll number, name, marks, and calculated average. This functionality was designed to help faculty and
administrators track individual student performance efficiently.
To simulate real-world usage, the team decided to create multiple student records. They planned to
populate the system with a mix of students initialized using both default and specific values. The
system's ability to accurately calculate averages and display detailed student information was to be
tested with this data.*/

 #include<iostream>
 using namespace std;

class student
{
    int id;
    string name;
    int marks1,marks2,marks3;

public:

    student()
    {
        id=0;
        name="Default name";
        marks1,marks2,marks3=0;

    }

    student(int i,string n,int m1,int m2,int m3 )
    {
        id=i;
        name=n;
        marks1=m1;
        marks2=m2;
        marks3=m3;
    }
     float Cal_avg()
     {
         return (marks1+marks2+marks3)/3.0;
     }

     void display()

    {

         cout<<"Name: "<<name<<endl;
         cout<<"ID :"<<id<<endl;
         cout<<"Average marks "<<Cal_avg()<<endl;


     }

};

int main()
{
    int i;
    student s[3]={student(),student(2,"siya",98,99,96),student(4,"Vrinda",98,99,99)};

    for(i=0;i<3;i++)
    {
        s[i].display();
    }
    return 0;

}
