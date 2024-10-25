#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

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

Node *convertArray2LinkedLst(vector<int> &arr)
{
    Node *head = new Node(arr[0]);
    Node *mover = head;
    for (int i = 1; i < arr.size(); i++)
    {
        Node *temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

int lengthOfLL(Node *Head)
{
    int count = 0;
    Node *temp = Head;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

int checkPresent(Node *Head, int value)
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

// Print LinkedList
void printLinkedList(Node *Head)
{
    Node *temp = Head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Deletion

// -> Head
Node *deletionHead(Node *Head)
{
    if (Head == NULL)
    {
        return Head;
    }
    Node *temp = Head;
    Head = Head->next;
    free(temp); // or delete(temp);
    return Head;
}

// -> position

Node *deletionAtPosition(Node *Head, int k)
{
    // if it is head
    if (Head == NULL)
    {
        return Head;
    }

    // if k = 1 that is head is next value
    if (k == 1)
    {
        Node *temp = Head;
        Head = Head->next;
        delete temp;
        return Head;
    }

    // if k = 3 or between head & tail that is head is next value
    Node *temp = Head;
    int count = 0;
    Node *prev = NULL;
    while (temp != NULL)
    {
        count++;
        if (count == k)
        {
            prev->next = prev->next->next;
            // cout<<"Deleted at "<<k<<endl;
            delete temp;
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return Head;
}

// -> value

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
            // cout<<"Deleted at "<<k<<endl;
            delete temp;
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return Head;
}

// -> last

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

// Insertion
// -> Head

Node *InsertionHead(Node *Head, int insValue)
{
    Node *temp = new Node(insValue, Head);
    return temp;
}
// -> position

Node *InsertionAtPosition(Node *Head, int k, int insValue)
{
    // if it is head
    if (Head == NULL)
    {
        return new Node(insValue);
    }

    // if k = 1 that is head is next value
    if (k == 1)
    {
        Node *newHeadNode = new Node(insValue, Head);
        return newHeadNode;
    }

    // if k = 3 or between head & tail that is head is next value
    Node *temp = Head;
    int count = 0;
    while (temp != NULL)
    {
        count++;
        if (count == k - 1)
        {
            Node *newbetweenNode = new Node(insValue);
            newbetweenNode->next = temp->next;
            temp->next = newbetweenNode;
            break;
        }
        temp = temp->next;
    }
    return Head;
}

// -> value
Node *InsertionAtAfterValue(Node *Head, int Value, int insValue)
{
    // if it is head
    if (Head == NULL)
    {
        return Head;
    }

    // if k = 1 that is head is next value
    if (Head->data == Value)
    {
        return new Node(insValue);
    }

    // if k = 3 or between head & tail that is head is next value
    Node *temp = Head;
    while (temp != NULL)
    {
        if (temp->data == Value)
        {
            Node *newbetweenNode = new Node(insValue);
            newbetweenNode->next = temp->next;
            temp->next = newbetweenNode;
            break;
        }
        temp = temp->next;
    }
    return Head;
}

Node *InsertionAtBeforeValue(Node *Head, int Value, int insValue)
{
    // if it is head
    if (Head == NULL)
    {
        return NULL;
    }

    // if k = 1 that is head is next value
    if (Head->data == Value)
    {
        return new Node(insValue);
    }

    // if k = 3 or between head & tail that is head is next value
    Node *temp = Head;
    while (temp->next != NULL)
    {
        if (temp->next->data == Value)
        {
            Node *newbetweenNode = new Node(insValue);
            newbetweenNode->next = temp->next;
            temp->next = newbetweenNode;
            break;
        }
        temp = temp->next;
    }
    return Head;
}

// -> last

Node *InsertionLast(Node *Head, int insValue)
{
    if (Head == NULL)
    {
        return new Node(insValue);
    }

    Node *temp = Head;

    while (temp->next != NULL)
    {
        // stop at last element
        temp = temp->next;
    }

    Node *newlastNode = new Node(insValue);
    temp->next = newlastNode;
    return Head;
}

int main()
{
    int x = 2;
    int *y = &x;
    cout << "Y address: " << y << endl;
    cout << "Y value: " << *y << endl;

    vector<int> arr = {61, 2, 3, 4, 5};
    int val = 50; // Value to search for
    Node *xy = new Node(arr[3]);
    cout << "xy: " << xy->data << endl;

    Node *Head = convertArray2LinkedLst(arr);
    cout << "HEAD Value: " << Head->data << endl;

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
    // New Head After deleeting from Node
    Head = deletionHead(Head);
    // cout << "Deletion at HEAD: ";
    // Head = deletionHead(Head);
    // printLinkedList(Head);

    // // Deletion at LAST
    // cout << "Deletion at LAST: ";
    // Head = deletionLast(Head);
    // printLinkedList(Head);

    // // Deletion at POSITION
    // Head = deletionAtPosition(Head, 2);
    // cout << "Deletion at Position: ";
    // printLinkedList(Head);

    // cout << "Org list: ";
    // printLinkedList(Head);

    // // Deletion at VALUE
    // Head = deletionAtValue(Head, 2);
    // cout << "Deletion at Value: ";
    // printLinkedList(Head);

    // Insertion at HEAD
    Head = InsertionHead(Head, 20);
    cout << "Insertion at Head: ";
    printLinkedList(Head);

    // Insertion at LAST
    Head = InsertionLast(Head, 44);
    cout << "Insertion at Last: ";
    printLinkedList(Head);

    // Insertion at POSITION
    Head = InsertionAtPosition(Head, 2, 244);
    Head = InsertionAtPosition(Head, 6, 7002);
    cout << "Insertion at Position: ";
    printLinkedList(Head);

    // Insertion at  AFTER VALUE
    Head = InsertionAtAfterValue(Head, 61, 300);
    Head = InsertionAtAfterValue(Head, 44, 676);
    cout << "Insertion at after Value: ";
    printLinkedList(Head);

    // Insertion at  BEFORE VALUE
    Head = InsertionAtBeforeValue(Head, 2, 100);
    Head = InsertionAtBeforeValue(Head, 3, 1);
    cout << "Insertion at before Value: ";
    printLinkedList(Head);

    return 0;
}