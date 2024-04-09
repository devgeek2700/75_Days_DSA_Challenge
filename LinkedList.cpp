#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    // constructors
public:
    Node(int data1, Node *next1)
    {
        data = data1;
        next = next1;
    }

    // constructors
public:
    Node(int data1)
    {
        data = data1;
        next = nullptr;
    }
};

// MEMORY SPACES
// 32-bits --> data = 4 bytes, address= 4 bytes
// 64-bits --> data = 4 bytes, address= 8 bytes

// Node  --> creating an object of type Node.
// Node*  --> you're creating a pointer

// in array they will ask u to return arr
// in linked list they will ask u to return head or element

// Array to linked list
Node *convertArray2LinkedLst(vector<int> &arr)
{
    Node *head = new Node(arr[0]);
    Node *mover = head;
    for (int i = 1; i < arr.size(); i++)
    {
        Node *temp = new Node(arr[i]);
        mover->next = temp; // address
        mover = temp;       // go to temp
    }
    return head;
}

// Length of linked list
int lengthOfLL(Node *Head)
{
    int count = 0;
    Node *temp = Head;
    while (temp != NULL)
    {
        temp = temp->next;
        count++;
    }
    return count;
}

// Search in the linked list

int checkPresent(Node *Head, int value) // TC --> O(n)
{
    Node *temp = Head;
    while (temp != NULL)
    {
        if (temp->data == value)
        {
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}

int main()
{
    int x = 2;
    int *y = &x; // y stores the address of x
    cout << "Y address: " << y << endl;
    cout << "Y value: " << *y << endl;

    vector<int> arr = {61, 2, 3, 4, 5};
    int val = 50;
    // MTD - 1
    // Node* head = new Node(2, nullptr);
    // Node* ptr = head;

    // MTD - 2
    Node *xy = new Node(arr[3]);
    cout << "xy: " << xy->data << endl;

    Node *Head = convertArray2LinkedLst(arr);
    cout << "HEAD Value: " << Head->data << endl;

    // // Traversal in Linked List

    Node *temp = Head;
    cout << "Temp Values: ";
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

    cout << "length of LL: " << lengthOfLL(Head) << endl;
    cout << "Search an Element: " << checkPresent(Head, val) << endl;

    return 0;
}




long long firstOne() {
    long long lo = 0, hi = 1;
    
    // Double the window size until we find the first occurrence of 1
    while (get(hi) == 0) {
        lo = hi;
        hi *= 2;
    }
    
    // Perform binary search within the identified window to find the first occurrence of 1
    while (lo < hi) {
        long long mid = lo + (hi - lo) / 2;
        if (get(mid) == 0) {
            lo = mid + 1;
        } else {
            hi = mid;
        }
    }
    
    return hi;
}


int specialSum(vector<int>& arr, int n) {
    int sum = 0;
    
    // Calculate the sum of all elements of the array
    for (int i = 0; i < n; ++i) {
        sum += arr[i];
    }
    
    // Keep adding the digits of the sum until it becomes a single digit
    while (sum >= 10) {
        int tempSum = 0;
        while (sum > 0) {
            tempSum += sum % 10; // Add the last digit of the sum
            sum /= 10; // Remove the last digit from the sum
        }
        sum = tempSum; // Update the sum with the new sum of digits
    }
    
    return sum; // Return the final single-digit sum
}



// kal se coding start