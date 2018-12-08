#include<bits/stdc++.h>
#include<string>
using namespace std;
class Person
{
public:
   string NID,DOB,name;
    void getInfo(string p,string q,string r)
    {
        name=p;
        NID=q;
        DOB=r;
    }
    void putInfo()
    {
        cout<<"Name : "<<name<<endl;
    }
};
class Student:public Person
{
public:
   int ID,ACMSolved;
    double gpa;
    void getData(string p,string q,string r,int s,int t,double u)
    {
        getInfo(p,q,r);
        ID=s;
        ACMSolved=t;
        gpa=u;
    }
    void putData()
    {
        putInfo();
        cout<<"ID of the student : "<<ID<<endl;
    }
    int qualify()
    {
        if(ACMSolved>=100 && gpa>=3.5)
            return 1;
        else
            return 0;
    }
    bool operator < (Student X)
    {
        if((((gpa*10)/4.0)+((ACMSolved*10)/100.0)) > (((X.gpa*10)/4.0)+((X.ACMSolved*10)/100.0)))
            return 1;
        return 0;
    }
};

int main()
{
   system("color f0");
    int i,j,number,t=0,temp;
    cout<<"Please enter the number of students : ";
    cin>>number;
    Student obj[number];
    for(i=0; i<number; i++)
    {
        string p,q,r;
        int s,t;
        double u;
        cout<<"Information about Student : "<<i+1<<endl;
        cout<<"Student name,NID & Date of birth: \n";
        cin>>p>>q>>r;
        cout<<"Student's academic ID, problem Solved & GPA: \n";
        cin>>s>>t>>u;
        obj[i].getData(p,q,r,s,t,u);
    }
    sort(obj,obj+number);
    cout<<"\n"<<endl;
    j=0;
    while(1)
    {
        if(t>4 || j>=number)
            break;
        if(obj[j].qualify())
        {
            cout<<"Rank : "<<t+1<<endl;
            obj[j].putData();
            cout<<endl;
            t+=1;
        }
        j++;
    }
    return 0;
}
