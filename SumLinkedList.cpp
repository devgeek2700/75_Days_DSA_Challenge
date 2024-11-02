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
Node *removeKthNodeTortiseMtd(Node *Head, int K) // TC --> O(len)  SC --> O(1)
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
    if (Fast == NULL)
    {
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

//  Sort Linked List
// bructe force

Node *sortList(Node *Head) // TC --> O(n+logn+n)   SC --> O(n)
{
    vector<int> varr;
    Node *temp = Head;

    while (temp != NULL)
    {
        varr.push_back(temp->data);
        temp = temp->next;
    }

    sort(varr.begin(), varr.end());

    int i = 0;
    temp = Head;
    while (temp != NULL)
    {
        temp->data = varr[i];
        temp = temp->next;
        i++;
    }

    return Head;
}

// optimal soln

Node *merge2Sortedlist(Node *list1, Node *list2)
{
    Node *dummyNode = new Node(-1);
    Node *temp = dummyNode;

    while (list1 != NULL && list2 != NULL)
    {
        if (list1->data > list2->data)
        {
            temp->next = list1;
            temp = list1;
            list1 = list1->next;
        }
        else
        {
            temp->next = list2;
            temp = list2;
            list2 = list2->next;
        }
    }
    if (list1)
    {
        temp->next = list1;
    }
    else
    {
        temp->next = list2;
    }
    return dummyNode->next;
}

Node *findMiddleMergeSort(Node *Head) // TC --> O(n/2)  SC --> O(1)
{
    Node *Slow = Head;
    Node *Fast = Head->next;

    while (Fast != NULL && Fast->next != NULL)
    {
        Slow = Slow->next;
        Fast = Fast->next->next;
    }

    return Slow;
}

Node *sortListMergesort(Node *Head) // TC --> O((n*logn)   SC --> O(1)
{
    if (Head == NULL || Head->next == NULL)
    {
        return Head;
    }

    Node *middleVal = findMiddleMergeSort(Head);
    Node *leftHead = Head;
    Node *RightHead = middleVal->next;
    middleVal->next = NULL;

    leftHead = sortListMergesort(leftHead);
    RightHead = sortListMergesort(RightHead);

    return merge2Sortedlist(leftHead, RightHead);
}

//  Sort linked list of 0s 1s 2s
// bructe force  --> data replacement
Node *sortList012(Node *Head) // TC --> O(2n)   SC --> O(1)
{
    Node *temp = Head;
    int count0 = 0;
    int count1 = 0;
    int count2 = 0;

    while (temp != NULL)
    {
        if (temp->data == 0)
        {
            count0++;
        }
        else if (temp->data == 1)
        {
            count1++;
        }
        else
        {
            count2++;
        }
        temp = temp->next;
    }

    temp = Head;

    while (temp != NULL)
    {
        if (count0)
        {
            temp->data = 0;
            count0--;
        }
        else if (count1)
        {
            temp->data = 1;
            count1--;
        }
        else
        {
            temp->data = 2;
            count2--;
        }
        temp = temp->next;
    }
    return Head;
}

// optimal soln  --> link exchange
Node *sortList012links(Node *Head) // TC --> O(2n)   SC --> O(1)
{
    if (Head == NULL || Head->next == NULL)
    {
        return Head;
    }

    Node *temp = Head;
    Node *dummyNode0 = new Node(-1);
    Node *dummyNode1 = new Node(-1);
    Node *dummyNode2 = new Node(-1);
    Node *zero = dummyNode0;
    Node *one = dummyNode1;
    Node *two = dummyNode2;

    while (temp != NULL)
    {
        if (temp->data == 0)
        {
            zero->next = temp;
            zero = temp;
        }
        else if (temp->data == 1)
        {
            one->next = temp;
            one = temp;
        }
        else
        {
            two->next = temp;
            two = temp;
        }
        temp = temp->next;
    }

    zero->next = (dummyNode1->next) ? dummyNode1->next : dummyNode2->next;
    one->next = dummyNode2->next;
    two->next = NULL;

    Node *newHead = dummyNode0->next;
    delete (dummyNode0);
    delete (dummyNode1);
    delete (dummyNode2);

    return newHead;
}

//  Intersection of Two Linked Lists
// Mtd - 1  --> Using Map
// Node *findIntersectionExchange(Node *firstHead, Node *secondHead) // TC --> O(n*logn)  SC --> O(n1)
// {
//     map<Node *, int> mpp;
//     Node *temp1 = firstHead;

//     while (temp1 != NULL)
//     {
//         mpp[temp1] = 1;
//         temp1 = temp1->next;
//     }

//     Node *temp2 = secondHead;

//     while (temp2 != NULL)
//     {
//         if (mpp.find(temp2) != mpp.end())
//         {
//             return temp2;
//         }
//         else
//         {
//             temp2 = temp2->next;
//         }
//     }
//     return NULL;
// }

// Mtd - 2  --> moving by 'd' dsitance for equal comparison

Node *collisionPoint(Node *small, Node *big, int d)
{
    while (d)
    {
        d--;
        big = big->next;
    }

    while (small != big)
    {
        small = small->next;
        big = big->next;
    }
    return big;
}

Node *findIntersectiondistance(Node *firstHead, Node *secondHead) // TC --> O(n1 + 2*n2)  SC --> O(1)
{
    Node *temp1 = firstHead;
    Node *temp2 = secondHead;

    int n1 = 0;
    while (temp1 != NULL)
    {
        n1++;
        temp1 = temp1->next;
    }

    int n2 = 0;
    while (temp2 != NULL)
    {
        n2++;
        temp2 = temp2->next;
    }

    // Resetting temp1 and temp2 to their respective heads
    temp1 = firstHead;
    temp2 = secondHead;

    if (n1 > n2)
    {
        return collisionPoint(firstHead, secondHead, n2 - n1);
    }
    else
    {
        return collisionPoint(secondHead, firstHead, n1 - n2);
    }

    return NULL;
}

// Mtd - 3  --> optimal soln -->

Node *findIntersectionExchange(Node *firstHead, Node *secondHead) // TC --> O(n1 + n2)  SC --> O(n1)
{
    Node *temp1 = firstHead;
    Node *temp2 = secondHead;

    if (firstHead == NULL || secondHead == NULL)
    {
        return NULL;
    }

    while (temp1 != temp2)
    {
        temp1 = temp1->next;
        temp2 = temp2->next;

        if (temp1 == temp2)
        {
            return temp1;
        }

        if (temp1 == NULL)
        {
            temp1 = secondHead;
        }
        if (temp2 == NULL)
        {
            temp2 = firstHead;
        }
    }

    return NULL;
}

//  Add one to a number represented as Linked List
Node *addOne(Node *Head) // TC -->O(3n)   SC --> O(1)
{
    Head = reverseLinkedListIterative(Head);
    Node *temp = Head;
    int carry = 1;

    while (temp != NULL)
    {
        temp->data = temp->data + carry;

        if (temp->data < 10)
        {
            carry = 0;
            break; // Move this break statement outside of the if-else block
        }
        else
        {
            temp->data = 0;
            carry = 1;
        }
        temp = temp->next;
    }

    if (carry == 1)
    {
        Node *newCarryNode = new Node(1);
        Head = reverseLinkedListIterative(Head);
        newCarryNode->next = Head; // Corrected the assignment operator here
        return newCarryNode;
    }

    Head = reverseLinkedListIterative(Head);

    return Head;
}

// using recusrions --> backtracking

int Recusrionaddone(Node *temp)
{
    if (temp == NULL)
    {
        return 1;
    }

    int Carry = Recusrionaddone(temp->next);
    temp->data = temp->data + Carry;

    if (temp->data < 10)
    {
        return 0;
    }

    temp->data = 0;
    return 1;
}

Node *addOneRecursion(Node *Head) // TC -->O(3n)   SC --> O(1)
{
    int finalCarry = Recusrionaddone(Head);
    if (finalCarry == 1)
    {
        Node *newCarryNode = new Node(1);
        newCarryNode->next = Head;
        return newCarryNode;
    }

    return Head;
}

//  Add Two Numbers

Node *addTwoNumbers(Node *Headnum1, Node *Headnum2) // TC --> O(max(n1,n2))   SC --> O(max(n1,n2))
{
    Node *temp1 = Headnum1;
    Node *temp2 = Headnum2;

    Node *sublistFinal = new Node(-1);
    Node *currNode = sublistFinal;

    int carry = 0;
    while (temp1 != NULL || temp2 != NULL)
    {
        int sum = carry;
        if (temp1)
        {
            sum = sum + temp1->data;
            temp1 = temp1->next;
        }
        if (temp2)
        {
            sum = sum + temp2->data;
            temp2 = temp2->next;
        }
        currNode->next = new Node(sum % 10);
        carry = sum / 10;
        currNode = currNode->next;
    }

    if (carry)
    {
        currNode->next = new Node(carry);
    }
    return sublistFinal->next;
}
// 11:41

int main()
{
    vector<int> arr = {9, 9};
    vector<int> firstHead = {4, 1, -1};
    vector<int> secondHead = {5, 6, -1};
    vector<int> num1 = {1, 2, 3};
    vector<int> num2 = {4, 5, 6};

    Node *Head = convertArray2LinkedLst(arr);
    Node *Headnum1 = convertArray2LinkedLst(num1);
    Node *Headnum2 = convertArray2LinkedLst(num2);

    Node *temp = Head;
    Node *temp1 = Headnum1;
    Node *temp2 = Headnum2;
    cout << "Linked List Values: ";
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

    cout << "Linked List Values  of num1: ";
    while (temp1 != NULL)
    {
        cout << temp1->data << " ";
        temp1 = temp1->next;
    }
    cout << endl;

    cout << "Linked List Values  of num2: ";
    while (temp2 != NULL)
    {
        cout << temp2->data << " ";
        temp2 = temp2->next;
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
    // Head = removeKthNodeTortiseMtd(Head, 3);
    // cout << "Remove Nth Node from the end of LL: ";
    // printLinkedList(Head);

    // Head = sortList(Head);
    // cout << "Sort Linked List: ";
    // printLinkedList(Head);

    // Head = sortList012(Head);
    // Head = sortList012links(Head);
    // cout << "Sort linked list of 0s 1s 2s: ";
    // printLinkedList(Head);

    // // int lenLoop = findIntersection(firstHead, secondHead);
    // int lenLoop = findIntersectionExchange(firstHead, secondHead);
    // cout << "Intersection of Two Linked Lists: " << lenLoop << endl;

    // Head = addOne(Head);
    // Head = addOneRecursion(Head);
    // cout << "Add one to a number represented as Linked List: ";
    // printLinkedList(Head);

    Head = addTwoNumbers(Headnum1, Headnum2);
    cout << " Add Two Numbers: ";
    printLinkedList(Head);

    return 0;
}