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
    }

    void getInfo()
    {
        cout << "clg std name: " << name << endl;
        cout << "clg std cgpa: " << *Cgpaptr << endl;
    }
};

// INHERITANCE
// single Inheritance
// Person  --> Student1
class Person
{
public:
    string name;
    int age;

    // Person(string name, int age)
    // {
    //     // member variable = parameter
    //     this->name = name;
    //     this->age = age;
    // }

    // Person()
    // {
    //     cout << "I'm Parent(Person) Class Constructor" << endl;
    // }

    // ~Person()
    // {
    //     cout << "I'm Person(parent) Class destrcutor" << endl;
    // }
};

class Student1 : public Person
{
public:
    // name, age, rollno

    int rollno;

    // Student1(string name, int age, int rollno) : Person(name, age)
    // {
    //     this->rollno = rollno;
    //     cout << "I'm Student1(child) Class Constructor" << endl;
    // }

    // ~Student1()
    // {
    //     cout << "I'm Student1(child) Class destrcutor" << endl;
    // }

    // void getInfoStd()
    // {
    //     cout << "std Name: " << name << endl;
    //     cout << "std age: " << age << endl;
    //     cout << "std rollno: " << rollno << endl;
    // }
};

// Multi-level Inheritance
// Person  --> Student1 --> GradStd
class GradStd : public Student1
{
public:
    string reserachTopic;

    void getInfoStd()
    {
        cout << " Name: " << name << endl;
        cout << " age: " << age << endl;
        cout << " rollno: " << rollno << endl;
        cout << " reserachTopic: " << reserachTopic << endl;
    }
};

// Multiple Inheritance
// Parent1 + Parent2 ---> child
class Student2
{
public:
    string name;
    int rollno;
};

class Teacher2
{
public:
    string subject;
    double salary;
};

class TeacherAssistant : public Student2, public Teacher2
{
public:
    int stdYr;

    void getInfoStd()
    {
        cout << "Name: " << name << endl;
        cout << "Roll No: " << rollno << endl;
        cout << "Year: " << stdYr << endl;
        cout << "Subject: " << subject << endl;
        cout << "Salary: " << salary << endl;
    }
};

// Hierarchial Inheritance
// Parent ---> child1 + child2
class Person2
{
public:
    string name;
    int age;
};

class student3 : public Person2
{
public:
    int stdYr;
    void getInfoStd()
    {
        cout << "Name: " << name << endl;
        cout << "age: " << age << endl;
        cout << "Year: " << stdYr << endl;
    }
};

class Teacher3 : public Person2
{
public:
    double salary;

    void getInfoStd()
    {
        cout << "Name: " << name << endl;
        cout << "age: " << age << endl;
        cout << "Salary: " << salary << endl;
    }
};

// Hybrid Inheritance
// Parent1 ---> child1 + child2
//                    |
//                    |
//                Grandchild

class HPerson
{
public:
    string name;
    int age;
};

// Derived class from HPerson
class HStudent : virtual public HPerson
{
public:
    int rollNo;
};

// Derived class from HPerson
class HTeacher : virtual public HPerson
{
public:
    string subject;
    double salary;
};

// Derived class from HStudent and HTeacher (Multiple Inheritance)
class HTeachingAssistant : public HStudent, public HTeacher
{
public:
    int year;

    void displayTAInfo()
    {
        cout << "Name: " << name << endl; // Resolving ambiguity
        cout << "Age: " << age << endl;   // Resolving ambiguity
        cout << "Roll No: " << rollNo << endl;
        cout << "Subject: " << subject << endl;
        cout << "Salary: " << salary << endl;
        cout << "Year: " << year << endl;
    }
};

// Constructor Overloading
class Animal
{
public:
    string name;
    string subject;
    int age;

    Animal()
    {
        cout << "non-paramtized constructor" << endl;
    }

    Animal(string name)
    {
        this->name = name;
        cout << "paramtized constructor" << endl;
    }

    void displayInfo()
    {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Subject: " << subject << endl;
    }

    void displayInfo(string name, string subject, int age)
    {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Subject: " << subject << endl;
    }

    void show(int x)
    {
        cout << "Value of x: " << x << endl;
    }

    void show(char ch)
    {
        cout << "Value of ch: " << ch << endl;
    }
};

// Function Overidding
class Parent
{
public:
    void show()
    {
        cout << "Parent Class" << endl;
    }

    virtual void Hello()
    {
        cout << "Parent Class Virtual Function" << endl;
    }
};

class child
{
public:
    void show()
    {
        cout << "Child Class Overidded Parent Class" << endl;
    }

    void Hello()
    {
        cout << "Child Class Virtual Function" << endl;
    }
};

// ABSTRACTION
// objects can't be created
class Shape
{
    virtual void draw() = 0; // pure virtual function it automatically becomes Abstract
};

class Circle
{
public:
    void draw()
    {
        cout << "Drawing a Circle" << endl;
    }
};

// static keyword
// static function
void Function()
{
    int x = 0;
    cout << "X: " << x << endl;
    x++;
}

void staticFunction()
{
    static int x = 0; // this statement will run only one time rest all code will run evrytime
    cout << "X: " << x << endl;
    x++;
}

// static class

class IncX
{
public:
    int x;

    void incx()
    {
        x = x + 1;
    }
};

class ABC
{
public:
    ABC()
    {
        cout << "Constructor" << endl;
    }

    ~ABC()
    {
        cout << "destructor" << endl;
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
    // collegeStudent clgstd1("Alice Deo", 9.1);

    // Deep Copy Constructor

    // collegeStudent clgstd2(clgstd1);
    // *clgstd2.Cgpaptr = 5.6;
    // clgstd2.name = "Neha Singh";
    // clgstd2.getInfo();
    // clgstd1.getInfo();

    // INHERITANCE

    // Student1 s1("Neha Singh", 20, 12876);
    // s1.getInfoStd();

    // GradStd gd1;
    // gd1.name = "Vivek Singh";
    // gd1.age = 20;
    // gd1.rollno = 4567;
    // gd1.reserachTopic = "AI&ML";
    // gd1.getInfoStd();

    // TeacherAssistant ta;
    // ta.name = "John Doe";
    // ta.age = 20;
    // ta.stdYr = 3;
    // ta.subject = "Mathematics";
    // ta.salary = 35000.00;

    // ta.getInfoStd();

    // student3 s3;
    // s3.name = "John Doe";
    // s3.age = 20;
    // s3.stdYr = 3;
    // s3.getInfoStd();

    // Teacher3 t3;
    // t3.name = "lida young";
    // t3.age = 20;
    // t3.salary = 35000.00;
    // t3.getInfoStd();

    // HTeachingAssistant Hdta;
    // Hdta.name = "Ruchi Singh";
    // Hdta.rollNo = 456;
    // Hdta.subject = "Maths";
    // Hdta.salary = 50000;
    // Hdta.year = 2;
    // Hdta.displayTAInfo();

    // POLYMORPHISM
    // compile time polymorphism
    // Constructor Overloading
    // Animal a;
    // // Animal a("Bird");
    // a.name = "Neha Singh";
    // a.age = 67;
    // a.subject = "Science";

    // // function Overloading
    // a.displayInfo();
    // a.displayInfo("Vivek Gupta", "Biology", 89);
    // a.show(1);
    // a.show('h');

    // Run time polymorphism
    // Function Overidding
    // child ch;
    // Parent p;

    // ch.show();
    // p.show();

    // virtual Function Overidding
    // child ch;
    // ch.Hello();

    // Circle c;
    // c.draw();

    // normal function
    // Function();

    // static function
    // staticFunction();
    // staticFunction();
    // staticFunction();

    // IncX ix;
    // IncX ix1;
    // ix.x = 100;
    // ix1.x = 200;
    // cout << "obj: " << ix1.x << endl;
    // ix1.incx();
    // cout << "obj after: " << ix1.x << endl;

    if (true)
    {
        ABC abj;
    }

    cout << "end of main" << endl;
    cout << "*******************************" << endl;

    if (true)
    {
       static ABC abj;
    }

    cout << "end of main" << endl;

    return 0;
}