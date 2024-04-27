#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *child;
    Node *random;

public:
    Node(int data1, Node *next1, Node *child1, Node *random1)
    {
        data = data1;
        next = next1;
        child = child1;
        random = random1;
    }

public:
    Node(int data1)
    {
        data = data1;
        next = nullptr;
        child = nullptr;
        random = nullptr;
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

//  Reverse List In K Groups

Node *reverseLinkedListIterative(Node *Head)
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

Node *findKthNode(Node *temp, int k)
{
    k -= 1;
    while (temp != NULL && k > 0)
    {
        k--;
        temp = temp->next;
    }
    return temp;
}

Node *kReverse(Node *Head, int k) // TC --> O(2n)   SC --> O(1)
{
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
        Node *KthHead = reverseLinkedListIterative(temp);

        if (temp == Head)
        {
            Head = KthHead;
        }
        else
        {
            prevNode->next = KthHead;
        }
        prevNode = temp;
        temp = nextNode;
    }
    return Head;
}

//  Rotate Linked List

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

Node *rotateKthLL(Node *Head, int k) // TC --> O(2*n)   SC --> O(1)
{
    Node *Tail = Head;
    int len = 1;

    while (Tail->next != NULL)
    {
        len++;
        Tail = Tail->next;
    }

    if (k % len == 0)
    {
        return Head;
    }

    k = k % len;
    Tail->next = Head;

    Node *newLastNode = findNewLastNode(Head, len - k);
    Head = newLastNode->next;
    newLastNode->next = NULL;

    return Head;
}

//  Flatten A Linked List
// Mtd - 1 --> Bructe force --> using Array
Node *convertArray2VerticalLinkedLst(vector<int> &arr)
{
    if (arr.size() == 0)
    {
        return NULL;
    }

    Node *newHead = new Node(arr[0]);
    Node *temp = newHead;

    for (int i = 1; i < arr.size(); i++)
    {
        Node *newNode = new Node(arr[i]);
        temp->child = newNode;
        temp = temp->child;
    }

    return newHead;
}

Node *flattenLinkedList(Node *Head) // Tc --> O(2*(n*m))   SC --> O(2*(n*m))
{
    Node *temp = Head;
    vector<int> varr;

    while (temp != NULL)
    {
        Node *childtemp = temp;
        while (childtemp != NULL)
        {
            varr.push_back(childtemp->data);
            childtemp = childtemp->child;
        }
        temp = temp->next;
    }

    sort(varr.begin(), varr.end());

    return convertArray2VerticalLinkedLst(varr);
}

// Mtd - 2 --> Better solution --> using Merge 2 lists

Node *mergetwoLists(Node *list1, Node *list2)
{
    Node *DummyNode = new Node(-1);
    Node *res = DummyNode;

    while (list1 != NULL && list2 != NULL)
    {
        if (list1->data < list2->data)
        {
            res->child = list1;
            res = list1;
            list1 = list1->child;
        }
        else
        {
            res->child = list2;
            res = list2;
            list2 = list2->child;
        }
        res->next = NULL;
    }

    if (list1)
    {
        res->child = list1;
    }
    else
    {
        res->child = list2;
    }

    if (DummyNode->child)
    {
        DummyNode->child->next = NULL;
    }
    return DummyNode->child;
}

Node *flattenLinkedListmerge(Node *Head) // Tc --> O(2*n*m)   SC --> O(n)
{

    if (Head == NULL || Head->next == NULL)
    {
        return Head;
    }

    Node *mergeHead = flattenLinkedListmerge(Head->next);
    Head = mergetwoLists(mergeHead, Head);
    return Head;
}

//  Clone a Linked List with random pointers
// Mtd - 1 --> Bructe force --> using Map

Node *cloneLL(Node *Head) // TC --> O(2*n)  SC --> O(2*n)
{
    Node *temp = Head;
    map<Node *, Node *> mpp;

    while (temp != NULL)
    {
        Node *newNode = new Node(temp->data);
        mpp[temp] = newNode;
        temp = temp->next;
    }

    while (temp != NULL)
    {
        Node *copyNode = mpp[temp];
        copyNode->next = mpp[temp->next];
        copyNode->random = mpp[temp->random];
        temp = temp->next;
    }
    return mpp[Head];
}

// Mtd - 2 --> Bructe force --> using Insert Node in between

void insertCopyData(Node *Head) // TC --> O(n)  SC --> O(1)
{
    Node *temp = Head;

    while (temp != NULL)
    {
        Node *copyNode = new Node(temp->data);
        copyNode->next = temp->next;
        temp->next = copyNode;
        temp = temp->next->next;
    }
}

void conncetRandomPointers(Node *Head) // TC --> O(n)  SC --> O(1)
{
    Node *temp = Head;
    while (temp != NULL)
    {
        Node *copyNode = temp->next;
        if (temp->random != NULL)
        {
            copyNode->random = temp->random->next;
        }
        else
        {
            copyNode->random = NULL;
        }
        temp = temp->next->next;
    }
}

Node *getCopyNodes(Node *Head) // TC --> O(n)  SC --> O(n)
{
    Node *temp = Head;
    Node *DummyNode = new Node(-1);
    Node *res = DummyNode;

    while (temp != NULL)
    {
        res->next = temp->next;
        temp->next = temp->next->next;
        res = res->next;
        temp = temp->next;
    }

    return DummyNode->next;
}

Node *cloneLLInsert(Node *Head) // TC --> O(3*n)  SC --> O(n)
{
    insertCopyData(Head);
    conncetRandomPointers(Head);
    return getCopyNodes(Head);
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    int k = 2;

    Node *Head = convertArray2LinkedLst(arr);
    Node *temp = Head;

    cout << "Temp Values: ";
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

    // Head = kReverse(Head, k);
    // cout << "Reverse List In K Groups: ";
    // printLinkedList(Head);

    // Head = rotateKthLL(Head, k);
    // cout << "Rotate Linked List: ";
    // printLinkedList(Head);

    // Head = flattenLinkedList(Head);
    // Head = flattenLinkedListmerge(Head);
    // cout << " Flatten A Linked List: ";
    // printLinkedList(Head);
    // Head = cloneLL(Head);
    Head = cloneLLInsert(Head);
    cout << "Clone a Linked List with random pointers: ";
    printLinkedList(Head);

    return 0;
}