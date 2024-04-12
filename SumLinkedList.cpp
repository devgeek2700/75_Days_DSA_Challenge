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

//  Middle Of Linked List
// Mtd-1
Node *findMiddle1(Node *Head) // TC --> O(n)  SC --> O(1)
{
    Node *temp = Head;
    int count = 0;

    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }

    int indexMidNode = (count / 2) + 1;
    temp = Head;

    while (temp != NULL)
    {
        indexMidNode--;
        if (indexMidNode == 0)
        {
            break;
        }
        temp = temp->next;
    }
    return temp;
}

// Mtd-2
Node *findMiddleTortoiseHareMethod(Node *Head) // TC --> O(n/2)  SC --> O(1)
{
    Node *Slow = Head;
    Node *Fast = Head;

    while (Fast != NULL && Fast->next != NULL)
    {
        Slow = Slow->next;
        Fast = Fast->next->next;
    }

    return Slow;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6};

    Node *Head = convertArray2LinkedLst(arr);

    Node *temp = Head;
    cout << "Linked List Values: ";
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

    // Node *findMidAns = findMiddle1(Head);
    Node *findMiddleTortoiseHareMethodAns = findMiddleTortoiseHareMethod(Head);
    cout << "Middle Of Linked List: " << findMiddleTortoiseHareMethodAns->data << endl;

    return 0;
}