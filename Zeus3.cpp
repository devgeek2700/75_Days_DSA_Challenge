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

// // ************************* DOUBLY LINKEDLIST EASY ***************************
// class Node
// {
// public:
//     int data;
//     Node *prev;
//     Node *next;

//     // creating the node structure
// public:
//     Node(int data1, Node *next1, Node *prev1)
//     {
//         data = data1;
//         next = next1;
//         prev = prev1;
//     }

// public:
//     Node(int data1)
//     {
//         data = data1;
//         next = nullptr;
//         prev = nullptr;
//     }
// };

// // Function to convert array (vector) to doubly linked list

// Node *convertArrayintoDLL(vector<int> &dlvarr)
// {
//     Node *Head = new Node(dlvarr[0]); // set the head at varr[0]
//     Node *prev = Head;

//     for (int i = 1; i < dlvarr.size(); i++)
//     {
//         Node *newNode = new Node(dlvarr[i], NULL, prev);
//         prev->next = newNode;
//         prev = newNode;
//     }
//     return Head;
// }

// // Function to print the linked list
// void printDoublyLinkedList(Node *Head)
// {
//     Node *curr = Head;
//     while (curr != nullptr)
//     {
//         cout << curr->data << " <-> ";
//         curr = curr->next;
//     }
//     cout << "NULL" << endl;
// }

// //  Deletion at HEAD
// Node *DeleteHeadDLL(Node *Head)
// {
//     if (Head == NULL)
//     {
//         delete Head;
//         return NULL;
//     }

//     Node *oldNode = Head;
//     Head = Head->next;
//     Head->prev = NULL;
//     oldNode->next = NULL;
//     delete oldNode;
//     return Head;
// }

// //  Deletion at LAST
// Node *DeleteTailDLL(Node *Head)
// {
//     if (Head == NULL)
//     {
//         return NULL;
//     }

//     if (Head->next == NULL)
//     {
//         delete Head;
//         return NULL;
//     }
//     Node *tailNode = Head;

//     while (tailNode->next != NULL)
//     {
//         tailNode = tailNode->next;
//     }

//     Node *newtail = tailNode->prev;
//     newtail->next = NULL;
//     tailNode->prev = NULL;
//     delete tailNode;
//     return Head;
// }

// //  Deletion at POSITION
// Node *DeleteatPositionDLL(Node *Head, int k)
// {
//     if (Head == NULL)
//     {
//         return NULL;
//     }

//     if (k == 1)
//     {
//         Node *newHead = Head->next;
//         if (newHead != NULL)
//         {
//             newHead->prev = NULL;
//         }
//         delete Head;
//         return newHead;
//     }

//     Node *KNode = Head;
//     int count = 0;

//     while (KNode->next != NULL)
//     {
//         count++;
//         if (count == k)
//         {
//             break;
//         }
//         KNode = KNode->next;
//     }

//     Node *FrontNode = KNode->next;
//     Node *BackNode = KNode->prev;

//     if (FrontNode->next == NULL && BackNode->prev)
//     {
//         return NULL;
//     }
//     else if (FrontNode->next == NULL)
//     {
//         DeleteTailDLL(Head);
//     }
//     else if (BackNode->next == NULL)
//     {
//         DeleteHeadDLL(Head);
//     }

//     BackNode->next = FrontNode;
//     FrontNode->prev = BackNode;
//     KNode->next = NULL;
//     KNode->prev = NULL;

//     delete KNode;

//     return Head;
// }

// //  Deletion at VALUE
// Node *deleteatNodeDLL(Node *Head, int Value)
// {
//     if (Head == NULL)
//     {
//         return NULL;
//     }

//     Node *KNode = Head;
//     while (KNode != NULL && KNode->data != Value)
//     {
//         KNode = KNode->next;
//     }

//     if (KNode == NULL)
//     {
//         return Head;
//     }

//     if (KNode == Head)
//     {
//         return DeleteHeadDLL(Head);
//     }

//     Node *FrontNode = KNode->next;
//     Node *BackNode = KNode->prev;

//     if (FrontNode != NULL)
//     {
//         FrontNode->prev = BackNode;
//     }
//     if (BackNode != NULL)
//     {
//         BackNode->next = FrontNode;
//     }

//     delete KNode;
//     return Head;
// }

// //  Insertion at HEAD
// Node *InsertBeforeHeadDLL(Node *Head, int insertValue)
// {
//     Node *newHeadNode = new Node(insertValue, Head, NULL);
//     Head->prev = newHeadNode;
//     return newHeadNode;
// }

// //  Insertion at BEFORE TAIL
// Node *InsertBeforeTailDLL(Node *Head, int insertValue)
// {
//     if (Head->next == NULL)
//     {
//         return InsertBeforeHeadDLL(Head, insertValue);
//     }

//     Node *tailNode = Head;
//     while (tailNode->next != NULL)
//     {
//         tailNode = tailNode->next;
//     }

//     Node *prevNodebeforeNewNode = tailNode->prev;
//     Node *newNodeBeforetail = new Node(insertValue, tailNode, prevNodebeforeNewNode);
//     prevNodebeforeNewNode->next = newNodeBeforetail;
//     tailNode->prev = newNodeBeforetail;

//     return Head;
// }

// //  Insertion at TAIL
// Node *insertAtTailDLL(Node *Head, int insertValue)
// {
//     if (Head->next == NULL)
//     {
//         return InsertBeforeHeadDLL(Head, insertValue);
//     }

//     Node *tailNode = Head;
//     while (tailNode->next != NULL)
//     {
//         tailNode = tailNode->next;
//     }

//     Node *newtailNode = new Node(insertValue, NULL, tailNode);
//     tailNode->next = newtailNode;

//     return Head;
// }

// //  Insertion at BEFORE K-NODE
// Node *InsertBeforeKNodeDLL(Node *Head, int k, int insertValue)
// {
//     if (k == 1)
//     {
//         return InsertBeforeHeadDLL(Head, insertValue);
//     }

//     Node *temp = Head;
//     int count = 1;
//     while (temp != NULL && count < k)
//     {
//         count++;
//         temp = temp->next;
//     }

//     if (temp == NULL)
//     {
//         return Head;
//     }

//     Node *prevNodebeforeKNode = temp->prev;
//     Node *newKNode = new Node(insertValue, temp, prevNodebeforeKNode);
//     prevNodebeforeKNode->next = newKNode;
//     temp->prev = newKNode;

//     return Head;
// }

// //  Insertion at AFTER K-NODE
// Node *InsertAfterKNodeDLL(Node *Head, int k, int insertValue)
// {
//     if (k == 1)
//     {
//         return InsertBeforeHeadDLL(Head, insertValue);
//     }

//     Node *temp = Head;
//     int count = 1;
//     while (temp != NULL && count < k)
//     {
//         count++;
//         temp = temp->next;
//     }

//     if (temp == NULL)
//     {
//         return Head;
//     }

//     if (temp->next == NULL)
//     {
//         return insertAtTailDLL(Head, insertValue);
//     }
//     // Insert between temp and temp->next
//     else
//     {
//         Node *newafterKNode = new Node(insertValue, temp->next, temp);
//         temp->next->prev = newafterKNode;
//         temp->next = newafterKNode;
//     }

//     return Head;
// }

// //  Insertion at BEFORE K-NODE VALUE
// Node *InsertBeforeKNodeValueDLL(Node *Head, int Value, int insertValue)
// {
//     if (Head->next == NULL)
//     {
//         return InsertBeforeHeadDLL(Head, insertValue);
//     }

//     Node *temp = Head;
//     while (temp->data != Value && temp != NULL)
//     {
//         temp = temp->next;
//     }

//     if (temp == NULL)
//     {
//         return Head;
//     }

//     if (temp == Head)
//     {
//         return InsertBeforeHeadDLL(Head, insertValue);
//     }

//     Node *prevNodebeforeKNode = temp->prev;
//     Node *newKNode = new Node(insertValue, temp, prevNodebeforeKNode);
//     prevNodebeforeKNode->next = newKNode;
//     temp->prev = newKNode;

//     return Head;
// }

// //  Insertion at AFTER K-NODE VALUE
// Node *InsertAfterKNodeValueDLL(Node *Head, int Value, int insertValue)
// {
//     if (Head->next == NULL)
//     {
//         return InsertBeforeHeadDLL(Head, insertValue);
//     }

//     Node *temp = Head;
//     while (temp->data != Value && temp != NULL)
//     {
//         temp = temp->next;
//     }

//     if (temp == NULL)
//     {
//         return Head;
//     }

//     if (temp->next == NULL)
//     {
//         return insertAtTailDLL(Head, insertValue);
//     }
//     else
//     {
//         Node *newafterKNode = new Node(insertValue, temp->next, temp);
//         temp->next->prev = newafterKNode;
//         temp->next = newafterKNode;
//     }

//     return Head;
// }

// // Reverse a Doubly Linked List
// Node *reverseDLL(Node *Head)
// {
//     if (Head == NULL || Head->next == NULL)
//     {
//         return Head;
//     }

//     Node *curr = Head;
//     Node *prev = NULL;

//     while (curr != NULL)
//     {
//         Node *next = curr->next;
//         curr->next = prev;
//         curr->prev = next;
//         prev = curr;
//         curr = next;
//     }

//     return prev;
// }

// *************************MEDIUM LINKEDLIST EASY ***************************

//  Middle Of Linked List
// Slow --> 1 step
// Fast --> 2 step
// Node *findMiddleTortoiseHareMethod(Node *Head) // TC --> O(n/2)  SC --> O(1)
// {
//     Node *Slow = Head;
//     Node *Fast = Head;

//     while (Fast != NULL && Fast->next != NULL)
//     {
//         Slow = Slow->next;
//         Fast = Fast->next->next;
//     }
//     return Slow;
// }

// // Reverse Linked List
// Node *reverseLinkedListIterative(Node *Head)
// {
//     Node *prevNode = NULL;
//     Node *curr = Head;

//     while (curr != NULL)
//     {
//         Node *frontNode = curr->next;
//         curr->next = prevNode;
//         prevNode = curr;
//         curr = frontNode;
//     }
//     return prevNode;
// }

// // 	Reverse a Linked List - Recursive
// Node *reverseLinkedListRecursive(Node *Head)
// {
//     if (Head != NULL || Head->next != NULL)
//     {
//         return Head;
//     }

//     Node *newHeadNode = reverseLinkedListRecursive(Head->next);
//     Node *frontNode = Head->next;
//     frontNode->next = Head;
//     Head->next = NULL;

//     return newHeadNode;
// }

// // Linked List Cycle - Tortoise Hare Method
// bool hasCycleusing(Node *Head)
// {
//     Node *Slow = Head;
//     Node *Fast = Head;

//     while (Fast != NULL && Fast->next != NULL)
//     {
//         Slow = Slow->next;
//         Fast = Fast->next->next;

//         if (Slow == Fast)
//         {
//             return true;
//         }
//     }
//     return false;
// }

// //  Linked List Cycle II -->detect starting of loop
// Node *detectCycle(Node *Head)
// {
//     Node *Slow = Head;
//     Node *Fast = Head;

//     while (Fast != NULL && Fast->next != NULL)
//     {
//         Slow = Slow->next;
//         Fast = Fast->next->next;

//         if (Slow == Fast)
//         {
//             Slow = Head;
//             while (Slow != Fast)
//             {
//                 Slow = Slow->next;
//                 Fast = Fast->next;
//             }
//             return Slow;
//         }
//     }
//     return NULL;
// }

// // Find length of Loop

// int findlengthcount(Node *Slow, Node *Fast)
// {
//     int count = 1;
//     Fast = Fast->next;

//     while (Slow != Fast)
//     {
//         count++;
//         Fast = Fast->next;
//     }
//     return count;
// }

// int countNodesinLoop(Node *Head)
// {
//     Node *Slow = Head;
//     Node *Fast = Head;

//     while (Fast != NULL && Fast->next != NULL)
//     {
//         Slow = Slow->next;
//         Fast = Fast->next->next;

//         if (Slow == Fast)
//         {
//             return findlengthcount(Slow, Fast);
//         }
//     }
//     return 0;
// }

// // Palindrome Linked List
// bool isPalindrome(Node *Head)
// {
//     Node *Slow = Head;
//     Node *Fast = Head;

//     while (Fast->next != NULL && Fast->next->next != NULL)
//     {
//         Slow = Slow->next;
//         Fast = Fast->next->next;
//     }

//     Node *newHeadafterRev = reverseLinkedListIterative(Slow->next);

//     Node *First = Head;
//     Node *Second = newHeadafterRev;

//     while (Second != NULL)
//     {
//         if (First->data != Second->data)
//         {
//             reverseLinkedListIterative(newHeadafterRev);
//             return false;
//         }
//         First = First->next;
//         Second = Second->next;
//     }

//     reverseLinkedListIterative(newHeadafterRev);
//     return true;
// }

// // Odd Even Linked List
// // odd - even - odd - even
// Node *oddEvenLList(Node *Head)
// {
//     if (Head == NULL || Head->next == NULL)
//     {
//         return Head;
//     }

//     Node *Oddstart = Head;
//     Node *Evenstart = Head->next;
//     Node *EvenHead = Evenstart;

//     while (Evenstart != NULL && Evenstart->next != NULL)
//     {
//         Oddstart->next = Evenstart->next;
//         Oddstart = Oddstart->next;

//         Evenstart->next = Oddstart->next;
//         Evenstart = Evenstart->next;
//     }

//     Oddstart->next = EvenHead;

//     return Head;
// }

// // Remove Nth Node From End of List
// Node *removeNthFromEndLL(Node *Head, int n)
// {
//     Node *Slow = Head;
//     Node *Fast = Head;

//     for (int i = 0; i < n; i++)
//     {
//         Fast = Fast->next;
//     }

//     if (Fast == NULL)
//     {
//         return Head->next;
//     }

//     while (Fast->next != NULL)
//     {
//         Slow = Slow->next;
//         Fast = Fast->next;
//     }

//     Node *deleteNode = Slow->next;
//     Slow->next = Slow->next->next;
//     delete (deleteNode);

//     return Head;
// }

// // Delete the Middle Node of a Linked List
// Node *deleteMiddleLL(Node *Head)
// {
//     Node *Slow = Head;
//     Node *Fast = Head;

//     Fast = Fast->next->next;

//     while (Fast != NULL && Fast->next != NULL)
//     {
//         Slow = Slow->next;
//         Fast = Fast->next->next;
//     }

//     Node *deleteNode = Slow->next;
//     Slow->next = Slow->next->next;
//     delete (deleteNode);

//     return Head;
// }

// // Sort List
// // LL --> Array --> any sortng alog like quick, merge sort --> output

// Node *mergesortLL(Node *Leftlist, Node *Rightlist)
// {
//     Node *dummyNode = new Node(-1);
//     Node *temp = dummyNode;

//     while (Leftlist != NULL && Rightlist != NULL)
//     {
//         if (Leftlist->data < Rightlist->data)
//         {
//             temp->next = Leftlist;
//             temp = Leftlist;
//             Leftlist = Leftlist->next;
//         }
//         else
//         {
//             temp->next = Rightlist;
//             temp = Rightlist;
//             Rightlist = Rightlist->next;
//         }
//     }

//     if (Leftlist)
//     {
//         temp->next = Leftlist;
//     }
//     else
//     {
//         temp->next = Rightlist;
//     }
//     return dummyNode->next;
// }

// Node *findMiddleMergeSort(Node *Head) // TC --> O(n/2)  SC --> O(1)
// {
//     Node *Slow = Head;
//     Node *Fast = Head->next;

//     while (Fast != NULL && Fast->next != NULL)
//     {
//         Slow = Slow->next;
//         Fast = Fast->next->next;
//     }

//     return Slow;
// }

// Node *sortListLL(Node *Head)
// {
//     if (Head == NULL || Head->next == NULL)
//     {
//         return Head;
//     }

//     Node *findMid = findMiddleMergeSort(Head);
//     Node *LeftSide = Head;
//     Node *RightSide = findMid->next;
//     findMid->next = NULL;

//     LeftSide = sortListLL(LeftSide);
//     RightSide = sortListLL(RightSide);

//     return mergesortLL(LeftSide, RightSide);
// }

// // Sort a linked list of 0s, 1s and 2s
// Node *sort012LL(Node *Head)
// {
//     if (Head == NULL && Head->next == NULL)
//     {
//         return Head;
//     }

//     Node *dummyNode0 = new Node(-1);
//     Node *dummyNode1 = new Node(-1);
//     Node *dummyNode2 = new Node(-1);
//     Node *zero = dummyNode0;
//     Node *one = dummyNode1;
//     Node *two = dummyNode2;
//     Node *temp = Head;

//     while (temp != NULL)
//     {
//         if (temp->data == 0)
//         {
//             zero->next = temp;
//             zero = temp;
//         }
//         else if (temp->data == 1)
//         {
//             one->next = temp;
//             one = temp;
//         }
//         else
//         {
//             two->next = temp;
//             two = temp;
//         }
//         temp = temp->next;
//     }

//     zero->next = (dummyNode1->next) ? dummyNode1->next : dummyNode2->next;
//     one->next = dummyNode2->next;
//     two->next = NULL;

//     Node *newHead = dummyNode0->next;
//     delete (dummyNode0);
//     delete (dummyNode1);
//     delete (dummyNode2);

//     return newHead;
// }

// //  Intersection of Two Linked Lists
// Node *findIntersectionExchange(Node *firstHead, Node *secondHead) // TC --> O(n1 + n2)  SC --> O(n1)
// {
//     Node *temp1 = firstHead;
//     Node *temp2 = secondHead;

//     if (firstHead == NULL || secondHead == NULL)
//     {
//         return NULL;
//     }

//     while (temp1 != temp2)
//     {
//         temp1 = temp1->next;
//         temp2 = temp2->next;

//         if (temp1 == temp2)
//         {
//             return temp1;
//         }

//         if (temp1 == NULL)
//         {
//             temp1 = secondHead;
//         }
//         if (temp2 == NULL)
//         {
//             temp2 = firstHead;
//         }
//     }

//     return NULL;
// }

// // Add 1 to a Linked List Number

// Node *addOne(Node *Head)
// {
//     Node *newHead = reverseLinkedListIterative(Head);
//     Node *temp = newHead;
//     int carry = 1;

//     while (temp != NULL)
//     {
//         temp->data = temp->data + carry;
//         if (temp->data < 10)
//         {
//             carry = 0;
//             break;
//         }
//         else
//         {
//             carry = 1;
//             temp->data = 0;
//         }
//         temp = temp->next;
//     }

//     if (carry == 1)
//     {
//         Node *newcarryNode = new Node(1);
//         Head = reverseLinkedListIterative(newHead);
//         newcarryNode->next = Head;
//         return newcarryNode;
//     }

//     return reverseLinkedListIterative(newHead);
// }

// // Add Two Numbers
// Node *addTwoNumbers(Node *l1, Node *l2)
// {
//     Node *temp1 = l1;
//     Node *temp2 = l2;

//     Node *sublistFinal = new Node(-1);
//     Node *curr = sublistFinal;

//     int carry = 0;
//     while (temp1 != NULL || temp2 != NULL)
//     {
//         int sum = carry;
//         if (temp1)
//         {
//             sum = sum + temp1->data;
//             temp1 = temp1->next;
//         }
//         if (temp2)
//         {
//             sum = sum + temp2->data;
//             temp2 = temp2->next;
//         }

//         curr->next = new Node(sum % 10);
//         carry = sum / 10;
//         curr = curr->next;
//     }

//     if (carry)
//     {
//         curr->next = new Node(carry);
//     }

//     return sublistFinal->next;
// }

// ************************* MEDIUM DOUBLY LINKEDLIST EASY ***************************

// Delete all occurrences of a given key in a doubly linked list
// Node *deleteAllOccurrences(Node *Head, int k)
// {
//     Node *temp = Head;

//     while (temp != NULL)
//     {
//         if (temp->data == k)
//         {
//             Node *frontNode = temp->next;

//             if (temp == Head)
//             {
//                 Head = frontNode;
//                 if (Head != NULL)
//                 {
//                     Head->prev = NULL;
//                 }
//             }
//             else
//             {
//                 Node *prevNode = temp->prev;
//                 if (frontNode)
//                 {
//                     frontNode->prev = prevNode;
//                 }
//                 if (prevNode)
//                 {
//                     prevNode->next = frontNode;
//                 }
//             }

//             delete temp;
//             temp = frontNode;
//         }
//         else
//         {
//             temp = temp->next;
//         }
//     }
//     return Head;
// }

// // Find pairs with given sum in doubly linked list

// Node *findTail(Node *Head)
// {
//     Node *tail = Head;

//     while (tail->next != NULL)
//     {
//         tail = tail->next;
//     }
//     return tail;
// }

// vector<pair<int, int>> findPairsWithGivenSum(Node *Head, int target)
// {
//     vector<pair<int, int>> ansPairs;
//     Node *Left = Head;
//     Node *Right = findTail(Head);
//     set<pair<int, int>> uniquePairs;

//     while (Left != NULL && Right != NULL && Left != Right && Left->prev != Right)
//     {
//         int sum = Left->data + Right->data;
//         if (sum == target)
//         {
//             pair<int, int> currentPair = {Left->data, Right->data};

//             if (uniquePairs.find(currentPair) == uniquePairs.end())
//             {
//                 ansPairs.push_back(currentPair);
//                 uniquePairs.insert(currentPair);
//             }

//             Left = Left->next;
//             Right = Right->prev;
//         }
//         else if (sum > target)
//         {
//             Right = Right->prev;
//         }
//         else
//         {
//             Left = Left->next;
//         }
//     }
//     return ansPairs;
// }

// // Remove duplicates from a sorted doubly linked list
// Node *removeDuplicates(Node *Head)
// {
//     if (Head == NULL || Head->next == NULL)
//     {
//         return Head;
//     }

//     Node *temp = Head;
//     while (temp != NULL && temp->next != NULL)
//     {
//         if (temp->data == temp->next->data)
//         {
//             Node *nodeToDelete = temp->next;
//             temp->next = nodeToDelete->next;

//             if (nodeToDelete->next != NULL)
//             {
//                 nodeToDelete->next->prev = temp;
//             }
//             delete (nodeToDelete);
//         }
//         else
//         {
//             temp = temp->next;
//         }
//     }
//     return Head;
// }

//  ************************* HARD LINEDLIST EASY ***************************
// Rotate List in LL

Node *findNewLastNode(Node *temp, int k)
{
    int count = 1;
    while (temp != NULL)
    {
        if (count == k)
        {
            return temp;
        }

        count++;
        temp = temp->next;
    }
    return temp;
}

Node *rotateRightLL(Node *Head, int k)
{
    if (Head == NULL || Head->next == NULL || k == 0)
    {
        return Head;
    }

    Node *tail = Head;
    int len = 1;

    while (tail->next != NULL)
    {
        len++;
        tail = tail->next;
    }

    k = k % len;
    if (k == 0)
    {
        return Head;
    }
    tail->next = Head;

    Node *newtailNode = findNewLastNode(Head, len - k);
    Head = newtailNode->next;
    newtailNode->next = NULL;

    return Head;
}

// Reverse Nodes in k-Group

Node *reverseLinkedListIterative(Node *Head)
{
    Node *prevNode = NULL;
    Node *curr = Head;

    while (curr != NULL)
    {
        Node *frontNode = curr->next;
        curr->next = prevNode;
        prevNode = curr;
        curr = frontNode;
    }
    return prevNode;
}

Node *findKthNode(Node *temp, int k)
{
    while (temp != NULL && k > 1)
    {
        k--;
        temp = temp->next;
    }
    return temp;
}

Node *reverseKGroup(Node *Head, int k)
{
    if (Head == NULL || Head->next == NULL || k == 1)
    {
        return Head;
    }

    Node *temp = Head;
    Node *prevNode = NULL;

    while (temp != NULL)
    {
        Node *KthNode = findKthNode(temp, k);

        if (KthNode == NULL)
        {
            if (prevNode)
            {
                prevNode->next = temp;
            }
            break;
        }

        Node *nextNode = KthNode->next;
        KthNode->next = NULL;
        Node *newKthHEad = reverseLinkedListIterative(temp);

        if (Head == temp)
        {
            Head = newKthHEad;
        }
        else
        {
            prevNode->next = newKthHEad;
        }
        prevNode = temp; // the last node of the previous k-group
        temp = nextNode;
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

    // vector<int> varr = {20, 30, 40, 50, 60};
    // Node *Head = convertarraytoLinkedlist(varr);
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

    // // Insertion at  AFTER VALUE
    // Head = InsertionAtAfterValue(Head, 30, 300);
    // Head = InsertionAtAfterValue(Head, 50, 676);
    // cout << "Insertion at after Value: ";
    // printLinkedList(Head);

    // // Insertion at  BEFORE VALUE
    // Head = InsertionAtBeforeValue(Head, 10, 100);
    // Head = InsertionAtBeforeValue(Head, 40, 888);
    // cout << "Insertion at before Value: ";
    // printLinkedList(Head);

    // vector<int> varrA = {3, 5};
    // vector<int> varrB = {4, 5, 9, 9};
    // // vector<int> varrB = {5, 6, 1, 8, 4, 5};
    // Node *HeadA = convertarraytoLinkedlist(varrA);
    // Node *HeadB = convertarraytoLinkedlist(varrB);
    // Node *HeadB = convertarraytoLinkedlist(varrB);

    // Node *temp = HeadA;
    // while (temp->next != NULL)
    // {
    //     temp = temp->next;
    // }
    // temp->next = HeadB->next->next;

    // cout << "Original List A: ";
    // printLinkedList(HeadA);

    // cout << "Original List B: ";
    // printLinkedList(HeadB);

    // Node *intersectionHead = findIntersectionExchange(HeadA, HeadB);

    // if (intersectionHead)
    // {
    //     cout << "Intersection Node: " << intersectionHead->data << endl;
    // }
    // else
    // {
    //     cout << "No intersection found." << endl;
    // }

    // cout << "Original List A: ";
    // printLinkedList(HeadA);

    // cout << "Original List B: ";
    // printLinkedList(HeadB);

    // // cout << "Add 1 to a Linked List Number: ";
    // // HeadA = addOne(HeadA);
    // // printLinkedList(HeadA);

    // cout << "Add Two Numbers: ";
    // Node *result = addTwoNumbers(HeadA, HeadB);
    // printLinkedList(result);

    vector<int> varr = {1, 2, 3, 4, 5, 6, 7};
    int target = 5;
    Node *Head = convertarraytoLinkedlist(varr);

    // Node *Head = convertArrayintoDLL(varr);

    // cout << "DDL Delete all occurrences: ";
    // Head = deleteAllOccurrences(Head, k);
    // printDoublyLinkedList(Head);

    // vector<pair<int, int>> ansPairs = findPairsWithGivenSum(Head, target);
    // for (auto it : ansPairs)
    // {
    //     cout << "(" << it.first << ", " << it.second << ")" << endl;
    // }

    // cout << "Remove duplicates from a sorted doubly linked list: ";
    // Head = removeDuplicates(Head);
    // printDoublyLinkedList(Head);

    // cout << "Rotate List linked list: ";
    // Head = rotateRightLL(Head, 4);
    // printLinkedList(Head);

    cout << "Reverse Nodes in k-Group: ";
    Head = reverseKGroup(Head, 3);
    printLinkedList(Head);

    return 0;
}