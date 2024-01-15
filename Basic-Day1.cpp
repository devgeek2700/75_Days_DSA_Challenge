#include <iostream>
#include <string>
// #include <bits/stdc++.h>

using namespace std;

void printName(string name)
{ // ------> Parameters
    cout << "My name is: " << name << endl;
}

int sum(int a, int b)
{
    return (a + b);
}

int maxNum(int a, int b)
{
    if (a >= b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

// Pass by value  -----> sends the copy not org

void num(int a, string fname)
{
    cout << a << endl;
    a += 5;
    cout << a << endl;
    a += 5;
    cout << a << endl;
    fname = "Neha";
    cout << fname << endl;
}

// refernce by value  -----> sends the org value

void changeVal(int &a)
{
    cout << a << endl;
    a = 100;
    cout << a << endl;
}

void printArr(int arr[], int n)
{

    for (int j = 0; j < n; j++)
    {
        cout << arr[j] << "  ";
    }
}

void show2dmatrix(int arr[3][3])  // arr is alays send by pass by reference
{

    for (int j = 0; j < 3; j++)
    {
        for (int k = 0; k < 3; k++)
        {
            int add = arr[j][k] += 100 ;
            cout << add<< "  ";
        }
        cout<<endl;
    }
}

int main()
{
    // int x,y;
    // cin>>x>>y;
    // cout<<"Value of x: "<<x<<" and y : "<<y<<endl;

    int x = 10;                      //	4 bytes
    int long y = 6789392;            //	4 bytes
    int long long z = 3235457766567; // 8 bytes

    float f = 4.56;        //  4 bytes
    double d = 456.789234; // 8 bytes

    // string s1,s2;
    // cin>>s1>>s2;
    // cout<<"s1: "<<s1<<" s2: "<<s2<<endl;

    // to pick up every word in string

    // string str;
    // getline(cin, str);
    // cout<<"Str: "<<str<<endl;

    char ch = '{'; // 1 bytes
    cout << ch << endl;

    // int -----> 10^-9 to 10^9
    // long -----> 10^-12 to 10^12
    // long long -----> 10^-18 to 10^918

    // if-else

    // int age;
    // cin>>age;

    // if(age < 18){
    //     cout<<"You're Child"<<endl;
    // }
    // else if(age == 18){
    //     cout<<"You're Teeneger"<<endl;
    // }
    // else{
    //     cout<<"You're Adult"<<endl;
    // }

    // int mrks;
    // cin>>mrks;

    // if(mrks < 25){
    //     cout<<"You're FAIL!"<<endl;
    // }
    // else if(mrks >= 25 && mrks <= 44){
    //     cout<<"You got E"<<endl;
    // }
    // else if(mrks >= 45 && mrks <= 49){
    //     cout<<"You got D"<<endl;
    // }
    // else if(mrks >= 50 && mrks <= 59){
    //     cout<<"You got C"<<endl;
    // }
    // else if(mrks >= 60 && mrks <= 79){
    //     cout<<"You got B"<<endl;
    // }
    // else if(mrks >= 80 && mrks <= 100){
    //     cout<<"You got A"<<endl;
    // }

    // int age;
    // cin >> age;

    // if (age < 18)
    // {
    //     cout << "not eligile for job" << endl;
    // }
    // else if (age <= 54)
    // {
    //     cout << "elgible for job" << endl;
    //     if (age <= 57)
    //     {
    //         cout << " retirement soon" << endl;
    //     }
    // }

    // else
    // {
    //     cout << "retirement time" << endl;
    // }

    // Switch case

    // int day;
    // cin >> day;

    // switch (day)
    // {
    // case 1:
    //     cout << "Monday" << endl;
    //     break;
    // case 2:
    //     cout << "Tuesday" << endl;
    //     break;
    // case 3:
    //     cout << "Wednesday" << endl;
    //     break;
    // case 4:
    //     cout << "Thursday" << endl;
    //     break;
    // case 5:
    //     cout << "Friday" << endl;
    //     break;
    // case 6:
    //     cout << "Saturday" << endl;
    //     break;
    // case 7:
    //     cout << "Sunday" << endl;
    //     break;

    // default:
    //     cout << "Invalid Number!!1" << endl;
    //     break;
    // }

    // Array 1D

    // int arr[5] = {1,2,3,4,5};
    // cout<<arr[2];

    int arr2[5];
    // cin>>arr2[0]>>arr2[1]>>arr2[2]>>arr2[3]>>arr2[4];
    // cout<<arr2[0]<<arr2[1]<<arr2[2]<<arr2[3]<<arr2[4]<<endl;

    arr2[2] = 10;
    // cout<<arr2[2];

    // Array 2D

    int mat[2][2];
    mat[0][0] = 33;
    //    cout<<mat[0][0]<<endl;

    // string
    string s = "Devgeek";
    cout << s[5] << endl;
    int len = s.length();
    s[len - 1] = 'o';
    cout << s[len - 1] << endl;
    cout << s[len - 5] << endl;

    // for loop:-

    for (int i = 1; i <= 10; i++)
    {
        cout << "Devgeek" << i << endl;
    }

    cout << endl;

    for (int i = 10; i >= 1; i--)
    {
        cout << "Devgeek" << i << endl;
    }

    cout << endl;

    // While loop:-

    int i = 1;
    while (i <= 10)
    {
        cout << "DSA" << i << endl;
        i++;
    }

    cout << endl;

    // D0-while loop:-

    int j = 1;
    do
    {
        cout << "DSA" << j << endl;
        j++;
    } while (j == -2);

    cout << endl;

    // Functions:-
    //  Void ----> not return anything

    string name;
    // getline(cin, name);

    // printName(name);  // -----> Arguments

    int a, b;
    cin >> a >> b;

    cout << "Sum is: " << sum(a, b) << endl;
    // 1:10:54

    int minval = min(a, b);
    cout << "Min is: " << minval << endl;

    int maxval = max(a, b);
    cout << "Max is: " << maxval << endl;

    cout << "Max2 is: " << maxNum(a, b) << endl;

    int l = 10;
    string fname = "Devgeek";
    num(l, fname);

    cout << l << endl;
    cout << fname << endl;

    int n1 = 20;
    changeVal(n1);
    cout << n1 << endl;

    int marks[6] = {19, 10, 8, 17, 9, 15};

    printArr(marks, 6);

    cout<<endl;

    int matrix[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    show2dmatrix(matrix);

        cout<<endl;

     for (int j = 0; j < 3; j++)
    {
        for (int k = 0; k < 3; k++)
        {
            cout << matrix[j][k]<< "  ";
        }
        cout<<endl;
    }

    return 0;
}
