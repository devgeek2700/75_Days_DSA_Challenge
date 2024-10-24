#include <bits/stdc++.h>
using namespace std;

// ************************* LINKEDLIST EASY ***************************
class Node
{
public:
    int data;
    Node *next;

    // creating the node structure
public:
    Node(int data1, Node *next1)
    {
        data = data1;
        next = next1;
    }

public:
    Node(int data1)
    {
        data = data1;
        next = nullptr;
    }
};

// Function to convert array (vector) to linked list

Node *convertarraytoLinkedlist(vector<int> &varr)
{
    Node *head = new Node(varr[0]); // set the head at varr[0]
    Node *mover = head;
    for (int i = 1; i < varr.size(); i++)
    {
        Node *temp = new Node(varr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

// Function to print the linked list
void printLinkedList(Node *Head)
{
    Node *curr = Head;
    while (curr != nullptr)
    {
        cout << curr->data << " -> ";
        curr = curr->next;
    }
    cout << "nullptr" << endl;
}

// Length of Node
int lengthOfLL(Node *Head)
{
    Node *temp = Head;
    int count = 0;
    while (temp != nullptr)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

// Search in Linked List
bool searchKey(int n, struct Node *head, int key)
{
    Node *temp = head;
    while (temp != nullptr)
    {
        if (temp->data == key)
        {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

int main()
{
    int x = 56;
    int *y = &x;
    cout << "Address of x: " << &x << endl;

    // memory location like int x = 2; --> Mtd1
    Node x2 = Node(2, nullptr);
    Node *xy = &x2;
    cout << "Address of xy: " << &xy << endl;

    // memory location like int x = 2; --> Mtd2
    Node *x3 = new Node(3, nullptr);
    cout << "Address of x3: " << &xy << endl;

    vector<int> arr = {1, 2, 3, 4, 5};                       // Creates a vector (array) of integers with values {1, 2, 3, 4, 5}.
    Node *newVal = new Node(arr[0]);                         // Dynamically allocates memory for a new Node. The node's 'data' is set to the first element of 'arr' (i.e., 1) and its 'next' pointer is set to nullptr (indicating the end of the list).
    cout << "Address of newVal: " << &newVal << endl;        // Prints the memory address of the node.
    cout << "Address of xy->data: " << newVal->data << endl; // Prints the value stored in the node (1).

    vector<int> varr = {20, 30, 40, 50, 60};
    Node *Head = convertarraytoLinkedlist(varr);
    cout << "HEAD Value: " << Head->data << endl;

    printLinkedList(Head);

    cout << "length of LL: " << lengthOfLL(Head) << endl;
    cout << "Search an Element: " << searchKey(varr.size(), Head, 440) << endl;

    return 0;
}