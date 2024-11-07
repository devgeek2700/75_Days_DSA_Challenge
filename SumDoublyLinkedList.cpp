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

// Convert Array to Doubly Linked List --> real application in Browser clicking into pages

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

//  Delete all occurrences of a given key in a doubly linked list

Node *deleteAllOccurrences(Node *Head, int k) // Tc --> O(n)  SC --> O(1)
{
    Node *temp = Head;
    while (temp != nullptr)
    {
        if (temp->data == k)
        {
            if (temp == Head)
            {
                Head = Head->next;
            }

            Node *frontNode = temp->next;
            Node *prevNode = temp->back;

            if (frontNode)
            {
                frontNode->back = prevNode;
            }
            if (prevNode)
            {
                prevNode->next = frontNode;
            }

            delete (temp);
            temp = frontNode;
        }
        else
        {
            temp = temp->next;
        }
    }
    return Head;
}

//  Find pairs with given sum in doubly linked list
// bructe force soln
vector<pair<int, int>> findPairs1(Node *Head, int k) // Tc --> O(near about n^2)   // SC --< O(1)
{
    vector<pair<int, int>> anspairs;
    Node *temp1 = Head;
    while (temp1 != NULL)
    {
        Node *temp2 = temp1->next;
        while (temp2 != NULL && temp1->data + temp2->data <= k)
        {
            if (temp1->data + temp2->data == k)
            {
                anspairs.push_back({temp1->data, temp2->data});
            }
            temp2 = temp2->next;
        }
        temp1 = temp1->next;
    }
    return anspairs;
}

// optimal soln

Node *Findtail(Node *Head)
{
    Node *TailNode = Head;
    while (TailNode->next != NULL)
    {
        TailNode = TailNode->next;
    }
    return TailNode;
}

vector<pair<int, int>> findPairs(Node *Head, int k) // Tc --> O(2n)   // SC --< O(1)
{
    vector<pair<int, int>> anspairs;
    Node *left = Head;
    Node *Right = Findtail(Head);

    while (left < Right)
    {
        if (left->data + Right->data == k)
        {
            anspairs.push_back({left->data, Right->data});
            left = left->next;
            Right = Right->back;
        }
        else if (left->data + Right->data > k)
        {
            Right = Right->back;
        }
        else
        {
            left = left->next;
        }
    }

    return anspairs;
}

//  Remove duplicates from a sorted Doubly Linked List
Node *removeDuplicates(Node *Head) // TC --> O(n)  SC --> O(1)
{
    Node *temp = Head;

    while (temp != NULL && temp->next != NULL)
    {
        Node *nextNode = temp->next;
        while (nextNode != NULL && nextNode->data == temp->data)
        {
            nextNode = nextNode->next;
        }
        temp->next = nextNode;
        if (nextNode)
        {
            nextNode->back = temp;
        }
        temp = temp->next;
    }

    return Head;
}

// 

int main()
{
    vector<int> varr = {1, 2, 2, 2, 3};
    int Key = 5;

    Node *Head = convertArray2DoublyLinkedLst(varr);

    cout << "Display Linked List: ";
    printList(Head);
    cout << endl;

    // Head = deleteAllOccurrences(Head, Key);
    // cout << "Delete all occurrences of KEY: ";
    // printList(Head);
    // cout << endl;

    // auto result = findPairs(Head, Key);
    // cout << "Pairs with sum equal to " << Key << ": ";
    // for (auto p : result)
    // {
    //     cout << "(" << p.first << ", " << p.second << ") ";
    // }
    // cout << endl;

    Head = removeDuplicates(Head);
    cout << "Remove duplicates from a sorted Doubly Linked List: ";
    printList(Head);
    cout << endl;
    return 0;
}