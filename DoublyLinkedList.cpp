#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *back;

    // 1
    Node(int data1, Node *next1, Node *back1)
    {
        data = data1;
        next = next1;
        back = back1;
    }

    // 2
    Node(int data1)
    {
        data = data1;
        next = NULL;
        back = NULL;
    }
};

// Convert Array to Doubly Linked List

Node *convertArray2DoublyLinkedLst(vector<int> &varr)
{
    Node *Head = new Node(varr[0]);
    Node *prev = Head;

    for (int i = 1; i < varr.size(); i++)
    {
        Node *temp = new Node(varr[i], NULL, prev);
        prev->next = temp;
        prev = temp;
    }
    return Head;
}

// Function to print the doubly linked list
void printList(Node *Head)
{
    Node *current = Head;
    while (current != nullptr)
    {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

// Deletions
// -> Head
Node *DeleteHead(Node *Head)
{
    if (Head == NULL || Head->next == NULL)
    {
        return NULL;
    }

    Node *oldHead = Head;
    Head = Head->next;
    Head->back = NULL;
    oldHead->next = NULL;

    delete oldHead;

    return Head;
}

// -> Tail
Node *DeleteTail(Node *Head)
{
    if (Head == NULL || Head->next == NULL)
    {
        return NULL;
    }

    Node *tail = Head;
    while (tail->next != nullptr)
    {
        tail = tail->next;
    }

    Node *newTail = tail->back;
    newTail->next = NULL;
    tail->back = NULL;

    delete tail;

    return Head;
}

// -> Position

Node *DeleteatPosition(Node *Head, int k)
{
    if (Head == NULL)
    {
        return NULL;
    }

    Node *KNode = Head;
    int count = 0;
    while (KNode->next != nullptr)
    {
        count++;
        if (count == k)
        {
            break;
        }
        KNode = KNode->next;
    }

    Node *prevNode = KNode->back;
    Node *frontNode = KNode->next;

    if (prevNode == NULL && frontNode == NULL)
    {
        // single element
        return NULL;
    }
    else if (prevNode == NULL)
    {
        return DeleteHead(Head);
    }
    else if (frontNode == NULL)
    {

        return DeleteTail(Head);
    }

    prevNode->next = frontNode;
    frontNode->back = prevNode;
    KNode->back = NULL;
    KNode->next = NULL;

    delete KNode;

    return Head;
}

// -> Node  --> Node is never teh head of the DLL

void deleteatNode(Node *temp)
{
    Node *prevNode = temp->back;
    Node *frontNode = temp->next;

    if (frontNode == NULL)
    {
        prevNode->next = NULL;
        temp->back = NULL;
        delete temp;
    }

    prevNode->next = frontNode;
    frontNode->back = prevNode;
    temp->back = NULL;
    temp->next = NULL;

    delete temp;
}

int main()
{
    vector<int> varr = {22, 45, 67, 78, 22, 11, 89};
    // // it invoke 1 in class Node
    // Node *Head = new Node(varr[0], NULL, NULL);

    // it invoke 2 in class Node
    Node *Head = convertArray2DoublyLinkedLst(varr);
    cout << "HEAD Value: " << Head->data << endl;

    // // Delete of the head
    // cout << "Delete of the head node: ";
    // Head = DeleteHead(Head);
    // printList(Head);

    // // Delete of the Tail
    // cout << "Delete of the tail node: ";
    // Head = DeleteTail(Head);
    // printList(Head);

    // // Delete of the Position
    // cout << "Delete of the position: ";
    // Head = DeleteatPosition(Head, 1);
    // printList(Head);

    // Delete of the Node
    cout << "Delete of the Node: ";
    deleteatNode(Head->next->next->next);
    printList(Head);

    // 44:15

    return 0;
}
