#include <bits/stdc++.h>
using namespace std;

// abstraction --> happens during deisgn phase what has to be shown public
// Encapsulation --> happens during exceution phase the develoepr using encapulstion ti implement the code
// using private, public, protected
// Encapsulation --> implement --> Abstraction

// class and objects
class Patient
{
public:
    // attributes or properties
    string name = "Vivek";
    int age = 20;
    string address = "Mumbai";

    // methods or member functions
    void Displayinfo()
    {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Address: " << address << endl;
    }
};

class Doctor1
{
public:
    virtual void treatPatient()
    {
        cout << "General doctor treating a patient." << endl;
    }
};

class Cardiologist1 : public Doctor1
{
public:
    void treatPatient()
    {
        cout << "Cardiologist treating a patient." << endl;
    }
};

// Single Inheritance --> is-a relationship
// one parent and one child class
class Person
{
public:
    string name = "Vivek";
    int age = 20;
    string address = "Mumbai";

    void Displayinfo()
    {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Address: " << address << endl;
    }
};

class Employee1 : public Person
{
public:
    int salary = 20000;
    string department = "IT";

    void Displayinfoemployee()
    {
        cout << "Salary: " << salary << endl;
        cout << "Department: " << department << endl;
    }
};

// Multiple Inheritance
// two or more parent and one  child class
// Parent1 + Parent2 ---> child

class BasicDetails
{
public:
    string name;
    int yoe;
    string position;

    void BasicInfo()
    {
        cout << "Name: " << name << ", Position: " << position << "YOE: " << yoe << endl;
    }
};

class salaryDetails
{
public:
    int salary;

    void SalaryInfo()
    {
        cout << "Salary: $" << salary << endl;
    }
};

class employee : public BasicDetails, public salaryDetails
{
public:
    void showEmployeeInfo()
    {
        BasicInfo();
        SalaryInfo();
    }
};

// Multilevel Inheritance
// one parent and two or more child class
// Person  --> Student1 --> GradStd

class BookingData
{
public:
    string name;
    string bookID;
    string address;

    void BookingInfo()
    {
        cout << "Name: " << name << ", BookID: " << bookID << ", Address: " << address << endl;
    }
};

class HotelBooking : public BookingData
{
public:
    string roomType;
    int roomNumber;

    void BookingDetailsInfo()
    {
        BookingInfo();
        cout << "Room Type: " << roomType << ", Room Number: " << roomNumber << endl;
    }
};

class PaymentDetails : public BookingData
{
public:
    int amount;
    void PaymentInfo()
    {
        BookingInfo();
        cout << "Amount: " << amount << endl;
    }
};

// Hierarchical Inheritance
// two or more child class and one parent class
// Parent ---> child1 + child2

class Employee
{
public:
    string name;
    int salary;

    void EmployeeInfo()
    {
        cout << "Name: " << name << ", Salary: " << salary << endl;
    }
};

class Manager : public Employee
{
public:
    string department;
    void ManagerInfo()
    {
        cout << "Name: " << name << ", Department: " << department << ", Salary: " << salary << endl;
    }
};

class Developer : public Employee
{
public:
    string project;
    void DeveloperInfo()
    {
        cout << "Name: " << name << ", Project: " << project << ", Salary: " << salary << endl;
    }
};

// Hybrid Inheritance
// 2-3 types of inheritance

class Event
{
public:
    string eventName;
    string eventDate;

    void EventInfo()
    {
        cout << "Event Name: " << eventName << ", Event Date: " << eventDate << endl;
    }
};

class Wedding : public Event
{
public:
    string brideName;
    string groomName;

    void WeddingInfo()
    {
        EventInfo();
        cout << "Bride Name: " << brideName << ", Groom Name: " << groomName << endl;
    }
};

class Venue : public Wedding
{
public:
    string venueName;
    string venueLocation;

    void VenueInfo()
    {
        WeddingInfo();
        cout << "Venue Name: " << venueName << ", Venue Location: " << venueLocation << endl;
    }
};

// what is overloading?
// means same method name but different parameters

class Hospital
{
public:
    int consultationFee;
    int roomCharge;
    int medicineCharge;

    void calculateBill(int consultationFee)
    {
        cout << "Total Bill (Outpatient): " << consultationFee << " INR" << endl;
    }

    void calculateBill(int roomCharge, int medicineCharge)
    {
        cout << "Total Bill (Inpatient): " << roomCharge + medicineCharge << " INR" << endl;
    }

    void calculateBill(int roomCharge, int medicineCharge, int consultationFee)
    {
        cout << "Total Bill (Inpatient): " << roomCharge + medicineCharge + consultationFee << " INR" << endl;
    }
};

// Overloading --> same method name but different parameters
// Overriding --> same method name and same parameters, using virtual keyword and also comes under parent-child relationship

// Polymorphism --> Polymorphism means "many forms". It allows one function to behave differently based on the object calling it.
// Types of Polymorphism --> Compile-time/static Polymorphism (Method Overloading) and Runtime/dynamic Polymorphism (Method Overriding)
// Runtime Polymorphism --> using virtual keyword/overridding and also comes under parent-child relationship
// Compile-time Polymorphism --> using function overloading
// Operator Overloading --> using operator overloading we can change the behavior of operators

class Doctor
{
public:
    string name = "Vivek";
    int age = 20;
    string address = "Mumbai";

    virtual void GetInfo()
    {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Address: " << address << endl;
    }
};

class Cardiologist : public Doctor
{
public:
    string speciality = "Cardiologist";
    void GetInfo()
    {
        cout << "Speciality: " << speciality << endl;
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Address: " << address << endl;
    }
};

class Dentist : public Doctor
{
public:
    string speciality = "Dentist";
    void GetInfo()
    {
        cout << "Speciality: " << speciality << endl;
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Address: " << address << endl;
    }
};

// Abstraction --> hiding the details of the implementation and showing only the essential features of the object

class Room // can we craete a instance of abstract class? --> NO
{
public:
    virtual void CalculatePrice(int nights) = 0;
};

class ACRoom : public Room
{
public:
    void CalculatePrice(int nights) override // is it compulsory to use override keyword in child class of abstarct class? --> No, it is not compulsory to use the override keyword, but it is recommended.
    {
        cout << "AC Room Price: " << nights * 2000 << endl;
    }
};

class StandardRoom : public Room
{
public:
    void CalculatePrice(int nights) override
    {
        cout << "Standard Room Price: " << nights * 1000 << endl;
    }
};

// Interface --> is a collection of abstract methods. It is a blueprint of a class that has only abstract methods. An interface is a completely abstract class that cannot be instantiated.
// it is by default public can't define privtae
class Customer
{
public:
    virtual void GetInfo() = 0;
};

class Customer1 : public Customer
{
public:
    void GetInfo() override
    {
        cout << "Customer 1" << endl;
    }
};

class Customer2 : public Customer
{
public:
    void GetInfo() override
    {
        cout << "Customer 2" << endl;
    }
};

// Encapsulation
// wrapping up of data & member functions in single unit called class

class Account
{
private:
    int amount;

public:
    string name = "Neha Singh";
    int Accountid = 1234567890;

    void GetInfo()
    {
        cout << "Name: " << name << ", Account ID: " << Accountid << endl;
    }

    bool checkamount(int amount)
    {
        if (amount > 0)
        {
            cout << "Account is positive" << endl;
        }
        else
        {
            cout << "Account is negative" << endl;
        }
    }
};

// CONSTRUCTOR
// Special method invoked automatically at time of "OBJECT CREATION".
// used for initialisation
// "this" Special pointer in C++ that points to the current object
// member variable = parameter ----> this->name = name

class Student
{

private:
    int amount;

    // CONSTRUCTOR --> Non Parameterized CONSTRUCTOR
public:
    // Student()
    // {
    //     cout << "Constructor is called" << endl;

    //     Accountid = 1234;
    // }

    // CONSTRUCTOR --> Non Parameterized CONSTRUCTOR
    Student(string name, int Accountid)
    {
        cout << "Constructor is called" << endl;
        // object value = parameter value
        this->name = name;
        this->Accountid = Accountid;
    }

public:
    string name = "Neha Singh";
    int Accountid;

    void GetInfo()
    {
        cout << "Name: " << name << ", Account ID: " << Accountid << endl;
    }

    bool checkamount(int amount)
    {
        if (amount > 0)
        {
            cout << "Account is positive" << endl;
        }
        else
        {
            cout << "Account is negative" << endl;
        }
    }
};

// COPY CONSTRUCTOR
// used to copy the properties of one object to another

class Student1
{
public:
    string name;
    int Accountid;

    Student1(string name, int Accountid)
    {
        this->name = name;
        this->Accountid = Accountid;
    }

    void GetInfo()
    {
        cout << "Name: " << name << ", Account ID: " << Accountid << endl;
    }

    // Copy constructor
    Student1(Student1 &s)
    {
        cout << "Copy constructor is called" << endl;
        this->name = s.name;
        this->Accountid = s.Accountid;
    }
};

// deep copy
class Student2
{
public:
    string name;
    double *cgpaPtr;

    Student2(string name, double cgpa)
    {
        this->name = name;
        this->cgpaPtr = new double;
        *cgpaPtr = cgpa;
    }

    // deep Copy constructor
    Student2(Student2 &s)
    {
        cout << "Copy constructor is called" << endl;
        this->name = s.name;
        this->cgpaPtr = new double;
        *cgpaPtr = *(s.cgpaPtr);
    }

    void GetInfo()
    {
        cout << "Name: " << name << ", CGPA: " << *cgpaPtr << endl;
    }
};

// DESTRUCTOR

class Client
{
public:
    string name;
    int age;

    Client()
    {
        cout << "Constructor is called" << endl;
    }

    ~Client()
    {
        cout << "Destructor is called" << endl;
    }

    void GetInfo()
    {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};

int main()
{

    // objects
    // Patient p1;
    // p1.Displayinfo();
    // p1.name = "Neha";
    // p1.Displayinfo();

    // employee e1;
    // e1.name = "Neha Singh";
    // e1.yoe = 4;
    // e1.position = "Developer";
    // e1.salary = 200000;
    // e1.showEmployeeInfo();

    // BookingData b1;
    // b1.name = "Neha Singh";
    // b1.bookID = "12345hjk6";
    // b1.address = "Mumbai";
    // b1.BookingInfo();

    // HotelBooking h1;
    // h1.name = "Neha Singh";
    // h1.bookID = "12345hjk6";
    // h1.address = "Mumbai";
    // h1.roomNumber = 101;
    // h1.roomType = "AC";
    // h1.BookingDetailsInfo();

    // PaymentDetails p1;
    // p1.name = "Neha Singh";
    // p1.bookID = "12345hjk6";
    // p1.address = "Mumbai";
    // p1.amount = 1000;
    // p1.PaymentInfo();

    // Manager m1;
    // m1.name = "Neha Singh";
    // m1.salary = 20000;
    // m1.department = "HR";
    // m1.ManagerInfo();

    // Developer d1;
    // d1.name = "Neha Gupta";
    // d1.salary = 40000;
    // d1.project = "Project 5";
    // d1.DeveloperInfo();

    // Venue v1;
    // v1.eventName = "Wedding";
    // v1.eventDate = "2024-01-01";
    // v1.brideName = "Neha Singh";
    // v1.groomName = "Vivek Singh";
    // v1.venueName = "Hotel Taj";
    // v1.venueLocation = "Mumbai";
    // v1.VenueInfo();

    // Employee e1;
    // e1.Displayinfo();
    // e1.name = "Priya";
    // e1.age = 25;
    // e1.address = "Pune";
    // e1.Displayinfo();
    // e1.Displayinfoemployee();
    // e1.salary = 30000;
    // e1.department = "HR";
    // e1.Displayinfoemployee();

    // Doctor *d1;
    // Cardiologist c1;

    // d1 = &c1;
    // d1->treatPatient();

    // overloading
    // Hospital h1;
    // h1.calculateBill(1000);
    // h1.calculateBill(500, 200);
    // h1.calculateBill(500, 200, 1000);

    // polymorphism
    // Doctor *d1;
    // Cardiologist c1;
    // d1 = &c1;
    // d1->GetInfo();

    // cout << endl;
    // Dentist d2;
    // d1 = &d2;
    // d1->GetInfo();

    // Abstraction
    // ACRoom acrm;
    // acrm.CalculatePrice(10);

    // StandardRoom stdrm;
    // stdrm.CalculatePrice(10);

    // Customer *c1;
    // Customer1 c2;
    // c1 = &c2;
    // c1->GetInfo();

    // cout << endl;
    // Customer2 c3;
    // c1 = &c3;
    // c1->GetInfo();

    // Account a1;
    // a1.GetInfo();
    // a1.checkamount(-900);

    // Student1 s1("vivek Singh", 4444);
    // s1.GetInfo();

    // Student1 s2(s1);
    // s2.GetInfo();

    // Student2 s1("Priya Shah", 6.8);
    // s1.GetInfo();

    // Student2 s2(s1);
    // *s2.cgpaPtr = 9.8;
    // s2.name = "Neha Singh";
    // s1.GetInfo();
    // s2.GetInfo();

    Client c1;
    c1.name = "Neha Singh";
    c1.age = 20;
    c1.GetInfo();

    return 0;
}