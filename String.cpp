#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str = "NehaSingh";
    string s(5, 's');
    cout << "S: " << s << endl;

    string fname = "neha";
    string midname = "vinod";
    string lname = "singh";
    string surame = fname + " " + lname;
    string fullname = surame.append(midname);

    cout << "surame: " << surame << endl;
    cout << "fullname: " << fullname << endl;

    string x = "10";
    string y = "20";
    cout << "add(x+y): " << x + y << endl;

    string txt = "NehaSingh";
    cout << "length of txt: " << txt.length() << endl;
    cout << "size of txt: " << txt.size() << endl;

    string word = "specificcharacter";
    cout << "Access word: " << word[6] << endl;

    // Replace the character
    word[6] = 'O';
    cout << "Replace char: " << word << endl;

    // Strings - Special Characters
    string txt1 = "We are the so-called \"Vikings\" from the north.";
    cout << "Special Characters: " << txt1 << endl;

    // User Input Strings
    string firstName;
    string MiddleName;
    string lastName;
    cout << "Type your first name: ";
    cin >> firstName;
    cout << "Type your Middle Name : ";
    cin >> MiddleName;
    cout << "Type your last Name: ";
    cin >> lastName;

    cout << "Your Full Name is: " << firstName + " " + MiddleName + " " + lastName;

    return 0;
}




void rearrangeArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] += (arr[arr[i]] % n) * n;
    }
    for (int i = 0; i < n; i++) {
        arr[i] /= n;
    }
}