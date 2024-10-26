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

// Deletion at HEAD
Node *deletionHead(Node *Head)
{
    if (Head == NULL)
    {
        return Head;
    }

    Node *oldHead = Head;
    Head = Head->next;
    free(oldHead);
    return Head;
}

// Deletion at LAST
Node *deletionLast(Node *Head)
{
    if (Head == NULL || Head->next == NULL)
    {
        delete Head;
        return NULL;
    }

    Node *temp = Head;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = NULL;
    return Head;
}

// Deletion at POSITION
Node *deletionAtPosition(Node *Head, int k)
{
    // if it is head idx = 0
    if (Head == NULL)
    {
        return NULL;
    }

    // if idx = 1
    if (k == 1)
    {
        Node *temp = Head;
        Head = Head->next;
        delete temp;
        return Head;
    }

    // if idx <= 2
    Node *temp = Head;
    int count = 1;
    Node *Prev = NULL;
    while (temp != NULL && count < k)
    {
        Prev = temp;
        temp = temp->next;
        count++;
    }

    if (temp == NULL)
    {
        return Head;
    }

    if (Prev != NULL)
    {
        Prev->next = temp->next;
    }
    delete temp;

    return Head;
}

// Deletion at VALUE
Node *deletionAtValue(Node *Head, int Value)
{
    // if it is head
    if (Head == NULL)
    {
        return Head;
    }

    // if k = 1 that is head is next value
    if (Head->data == Value)
    {
        Node *temp = Head;
        Head = Head->next;
        delete temp;
        return Head;
    }

    // if k = 3 or between head & tail that is head is next value
    Node *temp = Head;
    Node *prev = NULL;
    while (temp != NULL)
    {
        if (temp->data == Value)
        {
            prev->next = prev->next->next;
            delete temp;
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return Head;
}

// Insertion at HEAD

Node *InsertionHead(Node *Head, int insValue)
{
    Node *newNode = new Node(insValue, Head);
    return newNode;
}

// Insertion at LAST
Node *InsertionLast(Node *Head, int insValue)
{
    if (Head == NULL || Head->next == NULL)
    {
        return new Node(insValue);
    }

    Node *temp = Head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    Node *newLastNode = new Node(insValue);
    temp->next = newLastNode;
    return Head;
}

// Insertion at AFTER POSITION
Node *InsertionAtafterPosition(Node *Head, int k, int insValue)
{

    if (Head == NULL || Head->next == NULL)
    {
        return new Node(insValue);
    }

    if (k == 1)
    {
        Node *newHeadNode = new Node(insValue, Head);
        return newHeadNode;
    }

    Node *temp = Head;
    int count = 0;

    while (temp->next != NULL)
    {
        count++;
        if (count == k)
        {
            Node *newafterPosNode = new Node(insValue, Head);
            newafterPosNode->next = temp->next;
            temp->next = newafterPosNode;
            break;
        }
        temp = temp->next;
    }
    return Head;
}

// Insertion at BEFORE POSITION

Node *InsertionAtbeforePosition(Node *Head, int k, int insValue)
{

    if (Head == NULL || Head->next == NULL)
    {
        return new Node(insValue);
    }

    if (k == 1)
    {
        Node *newHeadNode = new Node(insValue, Head);
        return newHeadNode;
    }

    Node *temp = Head;
    int count = 0;

    while (temp->next != NULL)
    {
        count++;
        if (count == k - 1)
        {
            Node *newbeforePosNode = new Node(insValue, Head);
            newbeforePosNode->next = temp->next;
            temp->next = newbeforePosNode;
            break;
        }
        temp = temp->next;
    }
    return Head;
}

// Insertion at AFTER VALUE
Node *InsertionAtAfterValue(Node *Head, int Value, int insValue)
{
    if (Head == NULL || Head->next == NULL)
    {
        return new Node(insValue);
    }

    if (Head->data == Value)
    {
        Node *newHeadNode = new Node(insValue, Head);
        return newHeadNode;
    }

    Node *temp = Head;

    while (temp->next != NULL)
    {
        if (temp->data == Value)
        {
            Node *newbeforeValNode = new Node(insValue, Head);
            newbeforeValNode->next = temp->next;
            temp->next = newbeforeValNode;
            break;
        }
        temp = temp->next;
    }
    return Head;
}

// Insertion at BEFORE VALUE
Node *InsertionAtBeforeValue(Node *Head, int Value, int insValue)
{
    if (Head == NULL || Head->next == NULL)
    {
        return new Node(insValue);
    }

    if (Head->data == Value)
    {
        Node *newHeadNode = new Node(insValue, Head);
        return newHeadNode;
    }

    Node *temp = Head;

    while (temp->next != NULL)
    {
        if (temp->next->data == Value)
        {
            Node *newbeforeValNode = new Node(insValue, Head);
            newbeforeValNode->next = temp->next;
            temp->next = newbeforeValNode;
            break;
        }
        temp = temp->next;
    }
    return Head;
}

int main()
{
    // int x = 56;
    // int *y = &x;
    // cout << "Address of x: " << &x << endl;

    // // memory location like int x = 2; --> Mtd1
    // Node x2 = Node(2, nullptr);
    // Node *xy = &x2;
    // cout << "Address of xy: " << &xy << endl;

    // // memory location like int x = 2; --> Mtd2
    // Node *x3 = new Node(3, nullptr);
    // cout << "Address of x3: " << &xy << endl;

    // vector<int> arr = {1, 2, 3, 4, 5};                       // Creates a vector (array) of integers with values {1, 2, 3, 4, 5}.
    // Node *newVal = new Node(arr[0]);                         // Dynamically allocates memory for a new Node. The node's 'data' is set to the first element of 'arr' (i.e., 1) and its 'next' pointer is set to nullptr (indicating the end of the list).
    // cout << "Address of newVal: " << &newVal << endl;        // Prints the memory address of the node.
    // cout << "Address of xy->data: " << newVal->data << endl; // Prints the value stored in the node (1).

    vector<int> varr = {20, 30, 40, 50, 60};
    Node *Head = convertarraytoLinkedlist(varr);
    // cout << "HEAD Value: " << Head->data << endl;

    // printLinkedList(Head);

    // cout << "length of LL: " << lengthOfLL(Head) << endl;
    // cout << "Search an Element: " << searchKey(varr.size(), Head, 440) << endl;
    // cout << "HEAD Value: " << Head->data << endl;

    // //  Deletion at HEAD
    // Head = deletionHead(Head);
    // cout << "Deletion at HEAD: ";
    // printLinkedList(Head);

    // // Deletion at LAST
    // Head = deletionLast(Head);
    // cout << "Deletion at LAST: ";
    // printLinkedList(Head);

    // // Deletion at POSITION
    // Head = deletionAtPosition(Head, 4);
    // cout << "Deletion at Position: ";
    // printLinkedList(Head);

    // Deletion at VALUE
    // Head = deletionAtValue(Head, 50);
    // cout << "Deletion at Value: ";
    // printLinkedList(Head);

    // // Insertion at HEAD
    // Head = InsertionHead(Head, 90);
    // cout << "Insertion at Head: ";
    // printLinkedList(Head);

    // // Insertion at LAST
    // Head = InsertionLast(Head, 44);
    // cout << "Insertion at Last: ";
    // printLinkedList(Head);

    // // Insertion at AFTER POSITION
    // Head = InsertionAtafterPosition(Head, 2, 244);
    // Head = InsertionAtafterPosition(Head, 3, 7002);
    // cout << "Insertion at Position: ";
    // printLinkedList(Head);

    // // Insertion at AFTER POSITION
    // Head = InsertionAtbeforePosition(Head, 4, 100);
    // Head = InsertionAtbeforePosition(Head, 2, 555);
    // cout << "Insertion at Position: ";
    // printLinkedList(Head);

    // Insertion at  AFTER VALUE
    Head = InsertionAtAfterValue(Head, 30, 300);
    Head = InsertionAtAfterValue(Head, 50, 676);
    cout << "Insertion at after Value: ";
    printLinkedList(Head);

    // Insertion at  BEFORE VALUE
    Head = InsertionAtBeforeValue(Head, 10, 100);
    Head = InsertionAtBeforeValue(Head, 40, 888);
    cout << "Insertion at before Value: ";
    printLinkedList(Head);

    return 0;
}