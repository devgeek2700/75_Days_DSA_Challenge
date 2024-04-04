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



#include <bits/stdc++.h> 
vector<int> searchInSortedArray(vector<int> &arr, int n, vector<int> &queries, int q) {
    vector<int> result;
    // Iterate through each query
    for (int i = 0; i < q; i++) {
        int x = queries[i];
        int low = 0, high = n - 1;
        bool found = false;
        // Binary search
        while (low <= high) {
            int mid = low + (high - low) / 2;
            // If element is found
            if (arr[mid] == x) {
                found = true;
                break;
            }
            // If element is greater than mid
            else if (arr[mid] < x)
                low = mid + 1;
            // If element is smaller than mid
            else
                high = mid - 1;
        }
        // If element is found, push 1 to result vector, else push 0
        if (found)
            result.push_back(1);
        else
            result.push_back(0);
    }
    return result;
}