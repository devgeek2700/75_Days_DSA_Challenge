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



//  Find the starting point in LL - Linked List Cycle II
// // Mtd-1 using map
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

 // Mtd-2 using Tortoise Hare Method

Node *staringNodeodCycleTortoiseHareMethod(Node *Head)
{

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
    vector<int> arr = {1, 2, 3, 4, -1 };

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

     Node *isLoopStarted = staringNodeodCycle(Head);
//    Node* isLoopStarted = staringNodeodCycleTortoiseHareMethod(Head);
   if (isLoopStarted != nullptr) {
       cout << "Found the starting point of the cycle in the linked list: " << isLoopStarted->data << endl;
   } else {
       cout << "No cycle found in the linked list." << endl;
   }

   

    return 0;
}




Node* reverseLinkedList(Node* head) {
    // Check if the list is empty
    // or has only one node
    if (head == NULL || head->next == NULL) {
        
        // No change is needed;
        // return the current head
        return head; 
    }

    // Recursive step: Reverse the remaining 
    // part of the list and get the new head
    Node* newHead = reverseLinkedList(head->next);

    // Store the next node in 'front'
    // to reverse the link
    Node* front = head->next;

    // Update the 'next' pointer of 'front' to
    // point to the current head, effectively
    // reversing the link direction
    front->next = head;

    // Set the 'next' pointer of the
    // current head to 'null' to
    // break the original link
    head->next = NULL;

    // Return the new head obtained
    // from the recursion
    return newHead;
}