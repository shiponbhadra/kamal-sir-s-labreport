/* PROBLEM
CSE department wants to select Programming Coach for its students. Any student of the department can be a coach.
He need to have high profile at least three ACM regional contest participation and number of problem solutions of ACM need to more 300.
Students need to apply in the department, if anyone’s performance is below the requirement he will discard automatically.
As a student of CSE, write OOP code for the project. All the communications will be held by message.
*/


#include<iostream>
using namespace std;


class Department
{
    public:
        string dName;
        Department() {};
        Department(string dName)
        {
            this->dName = dName;
        }
};

class Student
{
    public:
        int sId,pAcm,pSolve;
        string sName;
        Department dept;

        Student() {};
        Student(int sId,string sName,Department *dept,int pAcm,int pSolve)
        {
            this->sId = sId;
            this->sName = sName;
            this->dept=*dept;
            this->pAcm=pAcm;
            this->pSolve=pSolve;
        }
        void studentsDetails()
        {
            cout<<"Student Id: "<<sId<<endl;
            cout<<"Student Name: "<<sName<<endl;
            cout<<"Department: "<<dept.dName<<endl;
            cout<<"Numbers of ACM contest participation: "<<pAcm<<endl;
            cout<<"Numbers of ACM problem solved: "<<pSolve<<endl;
        }
};


int main()
{
    const int deptSize = 3, stdSize = 5;

    Department *dept[deptSize] =
    {
        new Department("CSE"),
        new Department("ICT"),
        new Department("BBA")
    };


    Student *stdnt[stdSize]=
    {
        new Student(4001,"ABC",dept[0],1,500),
        new Student(4002,"XYZ",dept[0],2,200),
        new Student(4003,"PQR",dept[0],1,100),
        new Student(4004,"STR",dept[0],4,700),
        new Student(4005,"MNO",dept[0],3,1000)
    };


    cout<<endl<<"== STUDENTS DETAILS: =="<<endl<<endl;

    for(int i=0; i<stdSize; i++)
    {
        stdnt[i]->studentsDetails();
        cout<<endl;
    }

    cout<<endl<<endl<<"== COACH SELECTION == "<<endl<<endl;

    for(int i=0;i<stdSize;i++)
    {
        if(stdnt[i]->pAcm >= 3 && stdnt[i]->pSolve > 300)
        {
           cout<<"THIS STUDENT IS SELECTED AS A COACH"<<endl;

        }
        else
        {
           cout<<"THIS STUDENT IS NOT SELECTED AS A COACH "<<endl;
        }

        cout<<"STUDENT DETAILS: "<<endl;
        stdnt[i]->studentsDetails();
        cout<<endl<<endl;
    }
    return 0;
}
