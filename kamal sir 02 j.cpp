/* Like Uber, CNG owners want to develop a software which can communicate with customer and driver.
A customer needs to say his/her destination and nearer CNG driver will get message from the Uber company with name and mobile number of the customer.
The driver can make a direct call and if the customer confirms the ride then driver will come to spot and carry the passenger.
As a student of CSE,write OOP code for the project.
You need to pass message from one end to another end to make communications.*/
#include<iostream>
using namespace std;
class Bus
{
    int busnumber;
    string route;
public:
    string busposition;
    Bus() {}
    Bus(int bn,string r,string bp)
    {
        busnumber=bn;
        route=r;
        busposition=bp;
    }
    void displaybusnum()
    {
        cout<<busnumber;
    }
    void displayBus()
    {
        cout<<"\nBus information "<<endl;
        cout<<"__________________"<<endl;
        cout<<"Bus number : "<<busnumber<<endl;
        cout<<"Route : "<<route<<endl;
        cout<<"Busposition :"<<busposition<<endl;
    }
};
class BusDriver
{
    int mobilenumber;
    string name;
    int personnumber;
public:
    BusDriver() {}
    BusDriver(int mbn,string n,int p)
    {
        mobilenumber=mbn;
        name=n;
        personnumber=p;
    }
    void displayBusDriver()
    {
        cout<<"\nBusDriver information "<<endl;
        cout<<"______________________"<<endl;
        cout<<"name : "<<name<<endl;
        cout<<"mobile number : "<<mobilenumber<<endl;
        cout<<"person number :  "<<personnumber<<endl;
    }
    string locate_bus(Bus &x)
    {
        return x.busposition;
    }
    void seatbooking(Bus &b1)
    {
        cout<<"\n\nA seat is booked at ";
        b1.displaybusnum();
        cout<<" number bus"<<endl;
    }
};
class Student
{
    string name;
    int id;
public:
    Student () {}
    Student (string s,int i)
    {
        name=s;
        id=i;
    }
    void displaystudent()
    {
        cout<<"Name : "<<endl;
        cout<<"id : "<<id<<endl;
    }
    string contact_to_busdriver(BusDriver &bd1,Bus &b1)
    {
        return bd1.locate_bus(b1);
    }
    void Book_a_seat(BusDriver &bd1,Bus &b1)
    {
        bd1.seatbooking(b1);
    }
};
int main()
{
    BusDriver bd1(1111,"ABC",15);
    Bus b1(123,"Dhaka-to-CoxBazar","Chittagong");
    string a;
    bd1.displayBusDriver();
    b1.displayBus();
    Student s1("BCD",000000);
    a=s1.contact_to_busdriver(bd1,b1);
    s1.Book_a_seat(bd1,b1);
}


