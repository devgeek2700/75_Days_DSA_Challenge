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

//  Reverse Linked List Iterative - reverse data --> Using Stack
// bructe force
// Node *reverseLinkedListIterative(Node *Head) // TC --> O(n) SC --> O(n)
// {
//     stack<int> st;
//     Node *temp = Head;
//     while (temp != NULL)
//     {
//         st.push(temp->data);
//         temp = temp->next;
//     }

//     temp = Head;
//     while (temp != NULL || !st.empty())
//     {
//         temp->data = st.top();
//         st.pop();
//         temp = temp->next;
//     }
//     return Head;
// }

// optimal soln - reverse links
Node *reverseLinkedListIterative(Node *Head) // TC --> O(n) SC --> O(1)
{
    Node *prevNode = NULL;
    Node *temp = Head;

    while (temp != NULL)
    {
        Node *frontNode = temp->next;
        temp->next = prevNode;
        prevNode = temp;
        temp = frontNode;
    }
    return prevNode;
}

// 	Reverse a Linked List - Recursive

Node *reverseLinkedListRecursive(Node *Head) // TC --> O(n) SC --> O(n)
{
    if (Head == NULL || Head->next == NULL)
    {
        return Head;
    }

    Node *newHeadNode = reverseLinkedListRecursive(Head->next);
    Node *frontNode = Head->next;
    frontNode->next = Head;
    Head->next = NULL;

    return newHeadNode;
}

//  Cycle Detection in a Singly Linked List
// Mtd-1 using map
bool detectCycle(Node *Head) // TC --> O(n*2*logn)  SC --> O(1)
{
    map<Node *, int> mpp;
    Node *temp = Head;

    while (temp != NULL)
    {
        if (mpp.find(temp) != mpp.end())
        {
            return true;
        }

        mpp[temp] = 1;
        temp = temp->next;
    }

    return false;
}

// Mtd-2 using Tortoise Hare Method
bool detectCycleTortoiseHareMethod(Node *Head) // TC --> O(n)  SC --> O(1)
{
    Node *Slow = Head;
    Node *Fast = Head;

    while (Fast != NULL && Fast->next != NULL)
    {
        Slow = Slow->next;
        Fast = Fast->next->next;

        if (Slow == Fast)
        {
            return true;
        }
    }

    return false;
}

// Find the starting point in LL - Linked List Cycle II
// Mtd-1 using map

Node *staringNodeodCycle(Node *Head)
{
    map<Node *, int> mpp;
    Node *temp = Head;

    while (temp != NULL)
    {
        if (mpp.find(temp) != mpp.end())
        {
            return temp;
        }

        mpp[temp] = 1;
        temp = temp->next;
    }

    return NULL;
}

// Mtd-2 using map

Node *staringNodeodCycleTortoiseHareMethod(Node *Head) // Tc -->O(n*2*logn)  SC -->O(n)
{
    // 1) detecting the loop
    // 2) finding starting point

    Node *Slow = Head;
    Node *Fast = Head;

    while (Fast != NULL && Fast->next != NULL)
    {
        Slow = Slow->next;
        Fast = Fast->next->next;

        if (Slow == Fast)
        {
            Slow = Head;
            while (Slow != Fast)
            {
                Slow = Slow->next;
                Fast = Fast->next;
            }
            return Slow;
        }
    }

    return NULL;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, -1};

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
    // Node *findMiddleTortoiseHareMethodAns = findMiddleTortoiseHareMethod(Head);
    // cout << "Middle Of Linked List: " << findMiddleTortoiseHareMethodAns->data << endl;

    // Head = reverseLinkedListIterative(Head);
    // cout << "Reverse Linked List Iterative - Using Stack: ";
    // printLinkedList(Head);

    // bool isLoopedorNot = detectCycle(Head);
    // bool isLoopedorNot = detectCycleTortoiseHareMethod(Head);
    // cout <<"Cycle Detection in a Singly Linked List: " << isLoopedorNot << endl;

    Node *isLoopedstarted = staringNodeodCycle(Head);
    cout << "Find the starting point in LL: " << isLoopedstarted->data << endl;
    return 0;
}