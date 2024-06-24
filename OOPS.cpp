#include <bits/stdc++.h>
using namespace std;

// ENCAPSULATION/NORMAL CLASS
class Teacher
{
private:
    double salary; // data hiding

public:
    // CONSTRUCTOR --> Non Parameterized CONSTRUCTOR
    // Teacher()
    // {
    //     cout << "Teacher CONSTRUCTOR" << endl;
    //     dept = "AI&DS";
    //     address = "Mumbai";
    // }

    // CONSTRUCTOR -->  Parameterized CONSTRUCTOR
    // Teacher(string Incomingname, string Incomingsubject, string Incomingaddress, int Incomingage, double Incomingsalary)
    // {
    //     name = Incomingname;
    //     age = Incomingage;
    //     subject = Incomingsubject;
    //     dept = "Comps";
    //     address = "New Delhi";
    // }

    // there can be same name constructor just the name of the parameter should be different
    // Teacher(string Incomingname1, string Incomingsubject1, int Incomingage1)
    // {
    //     name = Incomingname1;
    //     age = Incomingage1;
    //     subject = Incomingsubject1;
    //     dept = "Comps";
    //     address = "NCR";
    // }

    // // need fo "this" so that we can give same name in paramters as delcared in the class
    Teacher(string name, string subject, int age)
    {
        this->name = name;
        this->age = age;
        this->subject = subject;
        dept = "Civil";
        address = "USA";
    }

    // Copy constructor
    Teacher(Teacher &Orgobj) // pass by referce
    {
        cout << "Teacher copy CONSTRUCTOR" << endl;
        this->name = Orgobj.name;
        this->age = Orgobj.age;
        this->subject = Orgobj.subject;
        dept = "EXTC";
        address = "Swiss";
    }

    // Propteries/ attributes
    string name;
    string dept;
    string subject;
    string address;
    int age;

    // Methods/memeber functions
    void chnageDept(string newdept)
    {
        dept = newdept;
    }

    void changeAge(int newage)
    {
        age = newage;
    }

    void changeAddress(string newaddress)
    {
        address = newaddress;
    }

    double calculateTaxes(double calSalary, int per, int months)
    {
        salary = calSalary;
        return salary - per - months;
    }

    // setter --> set private values
    void setSalary(double s)
    {
        salary = s;
    }

    // getter --> get private values
    double getSalary()
    {
        return salary;
    }

    void getConstInfo()
    {
        cout << "Teacher Name: " << name << endl;
        cout << "Teacher subject: " << subject << endl;
        cout << "Teacher age: " << age << endl;
        cout << "Teacher salary: " << salary << endl;
    }
};

// ENCAPSULATION

class Student
{
public:
    // CONSTRUCTOR
    Student()
    {
        cout << "Student CONSTRUCTOR" << endl;
    }

    string sname;
    string sdept;
    int srollno;
    int smarks;
    string saddress;

    // Methods/memeber functions
    bool passorfail(int smarks)
    {
        if (smarks < 35)
        {
            return 0;
        }
        else
        {
            return 1;
        }
    }
};

class bankAccount
{
private:
    double balance;
    string pincNumber; // data hiding

public:
    string ActId;
    string Accname;
};

// Deep Copy Constructor

class collegeStudent
{
public:
    string name;
    double *Cgpaptr; // data hiding

    // // shallow copy issue
    collegeStudent(string name, double cgpa)
    {
        this->name = name;    // static memeory delacre in complie time
        Cgpaptr = new double; // heap memory dynamic
        *Cgpaptr = cgpa;
    }

    // DEEP copy --> not default we need to write it
    // collegeStudent(collegeStudent &obj)
    // {
    //     this->name = obj.name;    // static memeory delacre in complie time
    //     Cgpaptr = new double; // heap memory dynamic
    //     *Cgpaptr = *obj.Cgpaptr;
    // }

    // collegeStudent(collegeStudent &OrgObj)
    // {
    //     this->name = OrgObj.name;
    //     this->Cgpaptr = OrgObj.Cgpaptr;
    // }

    // DESTRUCTOR
    // Normal static memory deallocate
    // ~collegeStudent()
    // {
    //     cout << "Hii, I'm deleting.. I'm DESTRUCTOR" << endl;
    // }

    // Dynamic static memory deallocate
    ~collegeStudent()
    {
        cout << "Hii, I'm deleting.. I'm DESTRUCTOR" << endl;
        delete (Cgpaptr); // if not delete then lead to memory leak/wastage

        // 01.:14:41
    }

    void getInfo()
    {
        cout << "clg std name: " << name << endl;
        cout << "clg std cgpa: " << *Cgpaptr << endl;
    }
};

int main()
{
    // Teacher t1("Mr. Aditya Yadav", "OOPs", "Pune", 30, 10000.00); // Automatically CONSTRUCTOR Call
    // Teacher t1("neha", "CN", 50); // Automatically CONSTRUCTOR Call
    // Teacher t2(t1);                   // refercing to t1
    // t1.setSalary(10000.00);           // Set salary since it's private

    // Student s1; // Automatically CONSTRUCTOR Call

    // t1.name = "Mrs. Sneha Yadav";
    // // t1.dept = "CSE&DS";
    // t1.subject = "OOPs";
    // t1.address = "Mumbai";
    // t1.age = 35;
    // t1.setSalary(700000.00);

    // s1.sname = "Neha Singh";
    // s1.sdept = "AI&DS";
    // s1.saddress = "Virar";
    // s1.smarks = 80;
    // s1.srollno = 56;

    // cout << "Teacher t1 Name: " << t2.name << endl;
    // cout << "Department: " << t2.dept << endl;
    // cout << "Subject: " << t2.subject << endl;
    // cout << "Address: " << t2.address << endl;
    // cout << "Age: " << t2.age << endl;

    // double getprivateSalary = t1.getSalary();

    // double afterTaxesSalary = t1.calculateTaxes(getprivateSalary, 10, 12);
    // cout << "Salary after taxes: " << afterTaxesSalary << endl;

    // cout << "***************************************************" << endl;

    // cout << "Student t1 Name: " << s1.sname << endl;
    // cout << "Department: " << s1.sdept << endl;
    // cout << "Address: " << s1.saddress << endl;
    // cout << "Roll No: " << s1.srollno << endl;
    // cout << "Marks: " << s1.smarks << endl;

    // int marksresult = s1.passorfail(s1.smarks);
    // if (marksresult == 1)
    // {
    //     cout << "Passed!" << endl;
    // }
    // else
    // {
    //     cout << "Failed!" << endl;
    // }

    // Copy Constructor
    collegeStudent clgstd1("Alice Deo", 9.1);

    // Deep Copy Constructor

    // collegeStudent clgstd2(clgstd1);
    // *clgstd2.Cgpaptr = 5.6;
    // clgstd2.name = "Neha Singh";
    // clgstd2.getInfo();
    clgstd1.getInfo();

    return 0;
}