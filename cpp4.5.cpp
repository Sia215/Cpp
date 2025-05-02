/*In an educational setting, an advanced grading system was conceptualized to accommodate the
diverse evaluation criteria for students at different academic levels. At the heart of the system is an
abstract base class that defines the grading framework. This class includes a protected member to
store marks and declares a pure virtual function for computing grades, ensuring that specific grading
logic is implemented by derived classes.
Two distinct derived classes were introduced to handle the unique grading needs of undergraduate
and postgraduate students. Each class defines its own implementation of the grade computation
method, reflecting the varying academic expectations for these groups. The system enables users to
input student data, compute grades based on the respective criteria, and manage a collection of
student records.*/


#include<iostream>
#include<vector>
using namespace std;
class student
{
    protected:
    float marks;

    public:
    void setmarks(float m)
    {
        marks =m;
    }
    virtual string computegrade() =0;
    ~student() {}
};
class undergraduate : public student
{
   public:
   string computegrade() override{
    if (marks>=85) return "A";
    else if(marks>=70) return"B";
    else if(marks>50) return "C";
    else return"F";
   }
};

class postgraduate : public student
{
    public:
    string computegrade() override
    {
        if(marks>=90) return"A";
        else if(marks>=80) return"B";
        else if(marks>=65) return"C";
        else if(marks>=50) return"D";
        else return "F";
    }
};
int main()
{
    vector<student*>students;

    int n;
    cout<<"Enter number of students:";
    cin>> n;

    for(int i=0;i<n;i++)
    {
        int type;
        float m;
        cout<<"\nEnter student type(1 for UG 2 for PG): ";
        cin>>type;
        cout<<"enter marks:";
        cin>> m;
        student * s = nullptr;
        if(type==1)
        {
            s = new undergraduate();
        }
        else if (type==2){
            s = new postgraduate();
        }
        else{
            cout<<"invalid student type. skipping....";
            continue;
        }
        s->setmarks(m);
        students.push_back(s);

    }
    cout<<"\nstudentgrades:\n";
    for(size_t i=0;i<students.size();++i)
    {
        cout<<"student"<<i+1<<"grade:"<<students[i]->computegrade()<<endl;
    }
    for(size_t i=0;i<students.size();++i)
    {
        delete students[i];
    }


    return 0;
}
