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

//  Find length of Loop
// // Mtd-1 using map
int lengthOfLoop(Node *Head) // TC --> O(n*2*logn)  SC --> O(n)
{
    map<Node *, int> mpp;
    Node *temp = Head;
    int count = 0;

    while (temp != NULL)
    {
        if (mpp.find(temp) != mpp.end())
        {
            int startvalueloop = mpp[temp];
            return count - startvalueloop;
        }
        mpp[temp] = count;
        count++;
        temp = temp->next;
    }

    return 0;
}

// Mtd-2 using Tortoise Hare Method

int findlengthcount(Node *Slow, Node *Fast)
{
    int count = 1;
    Fast = Fast->next;
    while (Slow != Fast)
    {
        count++;
        Fast = Fast->next;
    }
    return count;
}

int lengthOfLoopTortoiseHareMethod(Node *Head) // TC --> O(n)  SC --> O(1)
{
    Node *Slow = Head;
    Node *Fast = Head;

    while (Fast != NULL && Fast->next != NULL)
    {
        Slow = Slow->next;
        Fast = Fast->next->next;

        if (Slow == Fast)
        {
            return findlengthcount(Slow, Fast);
        }
    }
    return 0;
}

// Check If Linked List Is Palindrome
// mtd-1  -> stack
bool isPalindrome(Node *Head) // TC --> O(2n)  SC --> O(n)
{
    stack<int> st;
    Node *temp = Head;
    while (temp != NULL)
    {
        st.push(temp->data);
        temp = temp->next;
    }

    temp = Head;
    while (temp != NULL || !st.empty())
    {
        if (temp->data != st.top())
        {
            return false;
        }
        temp = temp->next;
        st.pop();
    }
    return true;
}

// mtd-1  -> Tortoise Hare Method
bool isPalindromeTortoiseHareMethod(Node *Head) // TC --> O(2n)  SC --> O(n)
{
    Node *Slow = Head;
    Node *Fast = Head;

    while (Fast->next != NULL && Fast->next->next != NULL)
    {
        Slow = Slow->next;
        Fast = Fast->next->next;
    }

    Node *newHeadMidVal = reverseLinkedListIterative(Slow->next);

    Node *First = Head;
    Node *Second = newHeadMidVal;

    while (Second != NULL)
    {
        if (First->data != Second->data)
        {
            reverseLinkedListIterative(newHeadMidVal);
            return false;
        }
        First = First->next;
        Second = Second->next;
    }

    reverseLinkedListIterative(newHeadMidVal);

    return true;
}

//    In a Linked List
// Mtd - 1 --> bructe force odd & even iterstions
Node *segregateEvenOdd(Node *Head) // TC --> O(2n)   SC --> O(n)
{
    if (Head == NULL || Head->next == NULL)
    {
        return Head;
    }

    Node *temp = Head;
    vector<int> arr;

    // ODD INDEX
    while (temp != NULL && temp->next != NULL)
    {
        arr.push_back(temp->data);
        temp = temp->next->next;
    }
    if (temp != NULL)
    {
        arr.push_back(temp->data);
    }

    // EVEN INDEX
    temp = Head->next;
    while (temp != NULL && temp->next != NULL)
    {
        arr.push_back(temp->data);
        temp = temp->next->next;
    }
    if (temp != NULL)
    {
        arr.push_back(temp->data);
    }

    // exchange the original list with the new list

    int i = 0;
    temp = Head;
    while (temp != NULL)
    {
        temp->data = arr[i];
        i++;
        temp = temp->next;
    }
    return Head;
}

// Mtd - 2 --> change links
Node *segregateEvenOddlinks(Node *Head)
{
    if (Head == NULL || Head->next == NULL)
    {
        return Head;
    }

    Node *oddNode = Head;
    Node *evenNode = Head->next;
    Node *evenHead = Head->next;

    while (evenNode != NULL && evenNode->next != NULL)
    {
        oddNode->next = oddNode->next->next;
        evenNode->next = evenNode->next->next;
        oddNode = oddNode->next;
        evenNode = evenNode->next;
    }

    oddNode->next = evenHead;

    return Head;
}

//  Segregate Even And Odd Data Nodes In a Linked List
Node *segregateEvenOddData(Node *Head)
{
    if (Head == NULL || Head->next == NULL)
    {
        return Head;
    }

    Node *temp = Head;
    Node *evenStart = NULL;
    Node *evenEnd = NULL;
    Node *oddStart = NULL;
    Node *oddEnd = NULL;

    while (temp != NULL)
    {
        if (temp->data >= 0) // Ignore negative data values
        {
            if (temp->data % 2 == 0) // If the data is even
            {
                if (evenStart == NULL) // even nodes not found before
                {
                    evenStart = temp;
                    evenEnd = evenStart;
                }
                else
                {
                    evenEnd->next = temp; // some even nodes not found before
                    evenEnd = evenEnd->next;
                }
            }
            else // If the data is odd
            {
                if (oddStart == NULL)
                {
                    oddStart = temp;
                    oddEnd = oddStart;
                }
                else
                {
                    oddEnd->next = temp;
                    oddEnd = oddEnd->next;
                }
            }
        }
        temp = temp->next;
    }

    // Joining the even and odd lists
    if (evenStart != NULL)
    {
        Head = evenStart;
        evenEnd->next = oddStart;
    }
    else
    {
        Head = oddStart;
    }

    if (oddEnd != NULL)
    {
        oddEnd->next = NULL;
    }

    return Head;
}

//  Delete Kth Node From End
// bructe force
Node *removeKthNodeTortiseMtd(Node *Head, int K) // TC --> O(2*len)  SC --> O(1)
{
    int count = 0;
    Node *temp = Head;

    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }

    if (count == K)
    {
        Node *newHead = Head->next;
        delete (Head);
        return newHead;
    }

    int resNode = count - K;
    temp = Head;

    while (temp != NULL)
    {
        resNode--;
        if (resNode == 0)
        {
            break;
        }

        temp = temp->next;
    }

    Node *deleteNode = temp->next;
    temp->next = temp->next->next;
    delete (deleteNode);

    return Head;
}

// Optimal soln
Node *removeKthNode(Node *Head, int K) // TC --> O(2*len)  SC --> O(1)
{
    Node *Slow = Head;
    Node *Fast = Head;

    Fast = Head;
    for (int i = 0; i < K; i++)
    {
        Fast = Fast->next;
    }

     // when n is given
    if(Fast == NULL){
        return Head->next;
    }


    while (Fast->next != NULL)
    {
        Slow = Slow->next;
        Fast = Fast->next;
    }


    Node *deleteNode = Slow->next;
    Slow->next = Slow->next->next;
    delete (deleteNode);

    

    return Head;
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
    // Node *findMiddleTortoiseHareMethodAns = findMiddleTortoiseHareMethod(Head);
    // cout << "Middle Of Linked List: " << findMiddleTortoiseHareMethodAns->data << endl;

    // Head = reverseLinkedListIterative(Head);
    // cout << "Reverse Linked List Iterative - Using Stack: ";
    // printLinkedList(Head);

    // bool isLoopedorNot = detectCycle(Head);
    // bool isLoopedorNot = detectCycleTortoiseHareMethod(Head);
    // cout <<"Cycle Detection in a Singly Linked List: " << isLoopedorNot << endl;

    //      Node *isLoopStarted = staringNodeodCycle(Head);
    // //    Node* isLoopStarted = staringNodeodCycleTortoiseHareMethod(Head);
    //    if (isLoopStarted != nullptr) {
    //        cout << "Found the starting point of the cycle in the linked list: " << isLoopStarted->data << endl;
    //    } else {
    //        cout << "No cycle found in the linked list." << endl;
    //    }

    // int lenLoop = lengthOfLoop(Head);
    // int lenLoop = lengthOfLoopTortoiseHareMethod(Head);
    // cout << "Find length of Loop: " << lenLoop << endl;

    // bool isPalindromeval = isPalindrome(Head);
    // bool isPalindromeval = isPalindromeTortoiseHareMethod(Head);
    // if (isPalindromeval == 1)
    // {
    //     cout << "Linked List Is Palindrome: " << isPalindromeval << endl;
    // }
    // else
    // {
    //     cout << "Linked List Is Not Palindrome" << endl;
    // }

    // Head = segregateEvenOdd(Head);
    // Head = segregateEvenOddlinks(Head);
    // cout << "Segregate Even And Odd Index Nodes: ";
    // printLinkedList(Head);

    // Head = segregateEvenOddData(Head);
    // cout << "Even And Odd Data Nodes: ";
    // printLinkedList(Head);

    // Head = removeKthNode(Head, 3);
    Head = removeKthNodeTortiseMtd(Head, 3);
    cout << "Remove Nth Node from the end of LL: ";
    printLinkedList(Head);

    return 0;
}
