#include <bits/stdc++.h>
using namespace std;

// Stack using Arrays
// PUSH OPERATION
void push(int stack[], int n, int &top, int x)
{
    if (top >= n - 1)
    {
        cout << "Stack Overflow" << endl;
    }
    else
    {
        top++;
        stack[top] = x;
    }
}

// POP OPERATION
void pop(int stack[], int n, int &top)
{
    if (top == -1)
    {
        cout << "Stack Underflow" << endl;
    }
    else
    {
        cout << "The popped element is " << stack[top] << endl;
        top--;
    }
}

// DISPLAY OPERATION
void Display(int stack[], int n, int &top)
{
    if (top == -1)
    {
        cout << "Stack Underflow" << endl;
    }
    else
    {
        cout << "Display Stack: ";
        for (int i = top; i >= 0; i--)
        {
            cout << stack[i] << " ";
        }
        cout << endl;
    }
}

// EMPTY OPERATION
void Emptyornot(int top)
{
    if (top == -1)
    {
        cout << "Stack EMPTY!" << endl;
    }
    else
    {
        cout << "Stack NOT EMPTY!" << endl;
    }
}

// FULL OPERATION
void Fullornot(int top, int n)
{
    if (top >= n - 1)
    {
        cout << "Stack FULL!" << endl;
    }
    else
    {
        cout << "Stack NOT FULL!" << endl;
    }
}

// Queue Using Array
// PUSH OPERATION

void enqueue(int queue[], int n, int &front, int &rear, int val)
{
    if (rear >= n - 1)
    {
        cout << "Queue Overflow" << endl;
    }
    else
    {
        if (front == -1)
        {
            front = 0;
        }
        rear++;
        queue[rear] = val;
        cout << val << " enqueued to queue" << endl;
    }
}

// POP OPERATION
void dequeue(int queue[], int &front, int &rear)
{
    if (front == -1)
    {
        cout << "Queue underflow" << endl;
    }
    else
    {
        cout << " dequeued to queue" << queue[front] << endl;
        front++;
        if (front > rear)
        {
            front = -1;
            rear = -1;
        }
    }
}

// DISPLAY OPERATION
void display(int queue[], int &front, int &rear)
{
    if (front == -1)
    {
        cout << "Queue underflow" << endl;
    }
    else
    {
        cout << "Queue elements: ";
        for (int i = front; i <= rear; i++)
        {
            cout << queue[i] << " ";
        }
        cout << endl;
    }
}

// EMPTY OPERATION
void isEmpty(int front)
{
    if (front == -1)
    {
        cout << "Queue is EMPTY!" << endl;
    }
    else
    {
        cout << "Queue is NOT EMPTY!" << endl;
    }
}

// FULL OPERATION
void isFull(int rear, int n)
{
    if (rear >= n - 1)
    {
        cout << "Queue is FULL!" << endl;
    }
    else
    {
        cout << "Queue is NOT FULL!" << endl;
    }
}

// Stack Implementation using a stack STL Library
// PUSH OPERATION
void pushstack(stack<int> &st, int val)
{
    st.push(val);
    cout << val << " pushed to stack" << endl;
}

// POP OPERATION
void popstack(stack<int> &st)
{
    if (st.empty())
    {
        cout << "Stack Underflow" << endl;
    }
    else
    {
        cout << "The popped element is " << st.top() << endl;
        st.pop();
    }
}

// DISPLAY OPERATION
void Displaystack(stack<int> &st)
{
    if (st.empty())
    {
        cout << "Stack Underflow" << endl;
    }

    stack<int> temp;
    temp = st;
    while (!temp.empty())
    {
        cout << temp.top() << " ";
        temp.pop();
    }
    cout << endl;
}

// EMPTY OPERATION
void Emptyornotstack(stack<int> &st)
{
    if (st.empty())
    {
        cout << "Stack is EMPTY!" << endl;
    }
    else
    {
        cout << "Stack is NOT EMPTY!" << endl;
    }
}

// Queue Implementation using a queue STL Library

// PUSH OPERATION
void enqueuequeue(queue<int> &q, int val)
{
    q.push(val);
    cout << "Value " << val << " enqueued to queue" << endl;
}

// POP OPERATION
void dequeuequeue(queue<int> &q)
{
    if (q.empty())
    {
        cout << "Queue underflow" << endl;
        return;
    }
    cout << "Dequeued element: " << q.front() << endl;
    q.pop();
}

// DISPLAY OPERATION
void displayqueue(queue<int> &q)
{
    if (q.empty())
    {
        cout << "Queue underflow" << endl;
        return;
    }

    cout << "Queue elements: ";
    queue<int> temp = q;
    while (!temp.empty())
    {
        cout << temp.front() << " ";
        temp.pop();
    }
    cout << endl;
}

// EMPTY OPERATION
void isEmptyqueue(queue<int> &q)
{
    if (q.empty())
    {
        cout << "Queue is EMPTY!" << endl;
    }
    else
    {
        cout << "Queue is NOT EMPTY!" << endl;
    }
}

// Implement Stack using Queues
// PUSH OPERATION
void pushStackusing1Queue(queue<int> &q1, int val)
{
    q1.push(val);
    cout << val << " pushed to stack" << endl;

    for (int i = 0; i < q1.size() - 1; i++)
    {
        q1.push(q1.front());
        q1.pop();
    }
}

// POP OPERATION
void popStackusing1Queue(queue<int> &q1)
{
    if (q1.empty())
    {
        cout << "UnderFlow" << endl;
        return;
    }
    cout << "Popped value: " << q1.front() << endl;
    q1.pop();
}

// DISPLAY OPERATION
void displayStackusing1Queue(queue<int> &q1)
{
    if (q1.empty())
    {
        cout << "UnderFlow" << endl;
        return;
    }

    cout << "Stack elements: ";
    queue<int> temp = q1;
    while (!temp.empty())
    {
        cout << temp.front() << " ";
        temp.pop();
    }
    cout << endl;
}

// EMPTY OPERATION
void isEmptyStackusing1Queue(queue<int> &q1)
{
    if (q1.empty())
    {
        cout << "Stack EMPTY!" << endl;
    }
    else
    {
        cout << "Stack NOT EMPTY!" << endl;
    }
}

// Implement Queue using Stacks
// PUSH OPERATION

void pushQueueusing1stack(stack<int> &st1, stack<int> &st2, int val)
{
    while (!st1.empty())
    {
        st2.push(st1.top());
        st1.pop();
    }

    st1.push(val);

    while (!st2.empty())
    {
        st1.push(st2.top());
        st2.pop();
    }
    cout << val << " pushed to queue" << endl;
}

// POP OPERATION
void popQueueusing1stack(stack<int> &st1, stack<int> &st2)
{
    if (st1.empty())
    {
        cout << "Queue Underflow!" << endl;
        return;
    }

    cout << "Queue elmenent pop using Stack: " << st1.top() << endl;
    st1.pop();
}

// DISPLAY OPERATION
void displayQueueusing1stack(stack<int> &st1, stack<int> &st2)
{
    if (st1.empty())
    {
        cout << "Queue Underflow!" << endl;
        return;
    }

    cout << "Queue elements: ";
    stack<int> temp = st1;
    while (!temp.empty())
    {
        cout << temp.top() << " ";
        temp.pop();
    }
    cout << endl;
}

// EMPTY OPERATION
void isEmptyQueueusing1stack(stack<int> &st1, stack<int> &st2)
{
    if (st1.empty())
    {
        cout << "Queue EMPTY!" << endl;
    }
    else
    {
        cout << "Queue NOT EMPTY!" << endl;
    }
}

// Stack using Linked List
// class Node
// {
// public:
//     int data;
//     Node *next;

// public:
//     Node(int data1)
//     {
//         data = data1;
//         next = nullptr;
//     }
// };

// class Stack
// {
//     Node *top;

// public:
//     Stack()
//     {
//         top = NULL;
//     }

//     void pushStackusingLL(int val)
//     {
//         Node *temp = new Node(val);

//         if (!temp)
//         {
//             cout << "Stack LL Underflow!" << endl;
//             exit(1);
//         }
//         temp->data = val;
//         temp->next = top;
//         top = temp;
//     }

//     void popStackusingLL()
//     {
//         if (top == NULL)
//         {
//             cout << "Stack LL Underflow!" << endl;
//             exit(1);
//         }

//         cout << "Popped value: " << top->data << endl;
//         Node *temp = top;
//         top = top->next;
//         delete (temp);
//     }

//     void displayStackusingLL()
//     {
//         if (top == NULL)
//         {
//             cout << "\nStack LL Underflow" << endl;
//             exit(1);
//         }
//         else
//         {
//             Node *temp = top;
//             while (temp != NULL)
//             {
//                 cout << temp->data;
//                 if (temp->next != NULL)
//                 {
//                     cout << " -> ";
//                 }
//                 temp = temp->next;
//             }
//         }
//         cout << endl;
//     }

//     bool isEmptyStackusingLL()
//     {
//         if (top == NULL)
//         {
//             cout << "\nStack LL EMPTY!" << endl;
//         }
//         else
//         {
//             cout << "\nStack LL NOT EMPTY!" << endl;
//         }
//     }

//     int peekusingLL()
//     {
//         if (top == NULL)
//         {
//             cout << "Stack is empty!" << endl;
//             return -1; // or throw an exception
//         }
//         return top->data;
//     }
// };

// Queue using Linked List
class Node
{
public:
    int data;
    Node *next;

public:
    Node(int data1)
    {
        data = data1;
        next = nullptr;
    }
};

class Queue
{
    Node *front, *rear;

public:
    Queue()
    {
        front = NULL;
        rear = NULL;
    }

    void pushQueueusingLL(int val)
    {
        Node *temp = new Node(val);

        // if queue is empty
        if (rear == NULL)
        {
            front = rear = temp;
            return;
        }
        rear->next = temp;
        rear = temp;
    }

    void popQueueusingLL()
    {
        if (front == NULL)
        {
            cout << "Queue Underflow" << endl;
            return;
        }

        Node *deletenode = front;
        cout << "Dequeued element: " << front->data << endl;
        front = front->next;
        delete (deletenode);
    }

    void displayQueueusingLL()
    {
        if (front == NULL)
        {
            cout << "Queue Underflow" << endl;
            return;
        }
        Node *temp = front;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void isEmptyQueueusingLL()
    {
        if (front == NULL)
        {
            cout << "Queue EMPTY!" << endl;
            return;
        }
        else
        {
            cout << "Queue NOT EMPTY!" << endl;
        }
    }

    int peekQueueusingLL()
    {
        if (front == NULL)
        {
            cout << "Queue Underflow" << endl;
            return -1;
        }
        return front->data;
    }
};

int main()
{
    // Stack Implementation using a Array

    // int stack[100];
    // int n = 100;
    // int top = -1;

    // int ch, val;
    // cout << "1) Push in stack" << endl;
    // cout << "2) Pop from stack" << endl;
    // cout << "3) Display stack" << endl;
    // cout << "4) Check if Stack Empty" << endl;
    // cout << "5) Check if Stack Full" << endl;
    // cout << "6) Exit" << endl;

    // do
    // {
    //     cout << "Enter choice: ";
    //     cin >> ch;
    //     switch (ch)
    //     {
    //     case 1:
    //         cout << "Enter value to be pushed: ";
    //         cin >> val;
    //         push(stack, n, top, val);
    //         break;
    //     case 2:
    //         pop(stack, n, top);
    //         break;
    //     case 3:
    //         Display(stack, n, top);
    //         break;
    //     case 4:
    //         Emptyornot(top);
    //         break;
    //     case 5:
    //         Fullornot(top, n);
    //         break;
    //     case 6:
    //         cout << "Exit" << endl;
    //         break;
    //     default:
    //         cout << "Invalid Choice" << endl;
    //     }
    // } while (ch != 6);

    // Queue Implementation using a Array

    // int queue[100];
    // int n = 100;
    // int front = -1;
    // int rear = -1;

    // int ch, val;
    // cout << "1) Enqueue in queue" << endl;
    // cout << "2) Dequeue from queue" << endl;
    // cout << "3) Display queue" << endl;
    // cout << "4) Check if Queue is Empty" << endl;
    // cout << "5) Check if Queue is Full" << endl;
    // cout << "6) Exit" << endl;

    // do
    // {
    //     cout << "Enter choice: ";
    //     cin >> ch;
    //     switch (ch)
    //     {
    //     case 1:
    //         cout << "Enter value to be enqueued: ";
    //         cin >> val;
    //         enqueue(queue, n, front, rear, val);
    //         break;
    //     case 2:
    //         dequeue(queue, front, rear);
    //         break;
    //     case 3:
    //         display(queue, front, rear);
    //         break;
    //     case 4:
    //         isEmpty(front);
    //         break;
    //     case 5:
    //         isFull(rear, n);
    //         break;
    //     case 6:
    //         cout << "Exit" << endl;
    //         break;
    //     default:
    //         cout << "Invalid Choice" << endl;
    //     }
    // } while (ch != 6);

    // Stack Implementation using a stack STL Library

    // stack<int> st;

    // int ch, val;
    // cout << "1) Push in stack" << endl;
    // cout << "2) Pop from stack" << endl;
    // cout << "3) Display stack" << endl;
    // cout << "4) Check if Stack Empty" << endl;
    // cout << "5) Check if Stack Full" << endl;
    // cout << "6) Exit" << endl;

    // do
    // {
    //     cout << "Enter choice: ";
    //     cin >> ch;
    //     switch (ch)
    //     {
    //     case 1:
    //         cout << "Enter value to be pushed: ";
    //         cin >> val;
    //         pushstack(st, val);
    //         break;
    //     case 2:
    //         popstack(st);
    //         break;
    //     case 3:
    //         Displaystack(st);
    //         break;
    //     case 4:
    //         Emptyornotstack(st);
    //         break;
    //     case 5:
    //         cout << "Exit" << endl;
    //         break;
    //     default:
    //         cout << "Invalid Choice" << endl;
    //     }
    // } while (ch != 5);

    // Queue Implementation using a queue STL Library

    // queue<int> q;
    // int ch, val;
    // cout << "1) Enqueue in queue" << endl;
    // cout << "2) Dequeue from queue" << endl;
    // cout << "3) Display queue" << endl;
    // cout << "4) Check if Queue is Empty" << endl;
    // cout << "5) Exit" << endl;

    // do
    // {
    //     cout << "Enter choice: ";
    //     cin >> ch;
    //     switch (ch)
    //     {
    //     case 1:
    //         cout << "Enter value to be enqueued: ";
    //         cin >> val;
    //         enqueuequeue(q, val);
    //         break;
    //     case 2:
    //         dequeuequeue(q);
    //         break;
    //     case 3:
    //         displayqueue(q);
    //         break;
    //     case 4:
    //         isEmptyqueue(q);
    //         break;
    //     case 5:
    //         cout << "Exit" << endl;
    //         break;
    //     default:
    //         cout << "Invalid Choice" << endl;
    //     }
    // } while (ch != 5);

    // Implement Stack using Queues
    // queue<int> q1;

    // int ch, val;
    // cout << "1) Enqueue in queue" << endl;
    // cout << "2) Dequeue from queue" << endl;
    // cout << "3) Display queue" << endl;
    // cout << "4) Check if Queue is Empty" << endl;
    // cout << "5) Exit" << endl;

    // do
    // {
    //     cout << "Enter choice: ";
    //     cin >> ch;
    //     switch (ch)
    //     {
    //     case 1:
    //         cout << "Enter value to be enqueued: ";
    //         cin >> val;
    //         pushStackusing1Queue(q1, val);
    //         break;
    //     case 2:
    //         popStackusing1Queue(q1);
    //         break;
    //     case 3:
    //         displayStackusing1Queue(q1);
    //         break;
    //     case 4:
    //         isEmptyStackusing1Queue(q1);
    //         break;
    //     case 5:
    //         cout << "Exit" << endl;
    //         break;
    //     default:
    //         cout << "Invalid Choice" << endl;
    //     }
    // } while (ch != 5);

    // Implement Queue using Stacks

    // stack<int> st1;
    // stack<int> st2;

    // int ch, val;
    // cout << "1) Enqueue in queue" << endl;
    // cout << "2) Dequeue from queue" << endl;
    // cout << "3) Display queue" << endl;
    // cout << "4) Check if Queue is Empty" << endl;
    // cout << "5) Exit" << endl;

    // do
    // {
    //     cout << "Enter choice: ";
    //     cin >> ch;
    //     switch (ch)
    //     {
    //     case 1:
    //         cout << "Enter value to be enqueued: ";
    //         cin >> val;
    //         pushQueueusing1stack(st1, st2, val);
    //         break;
    //     case 2:
    //         popQueueusing1stack(st1, st2);
    //         break;
    //     case 3:
    //         displayQueueusing1stack(st1, st2);
    //         break;
    //     case 4:
    //         isEmptyQueueusing1stack(st1, st2);
    //         break;
    //     case 5:
    //         cout << "Exit" << endl;
    //         break;
    //     default:
    //         cout << "Invalid Choice" << endl;
    //     }
    // } while (ch != 5);

    // Stack using Linked List
    // Stack stackLL;
    // cout << "Stack Operations Using Linked List:" << endl;
    // stackLL.pushStackusingLL(10);
    // stackLL.pushStackusingLL(20);
    // stackLL.pushStackusingLL(30);
    // stackLL.pushStackusingLL(40);
    // stackLL.displayStackusingLL();
    // stackLL.popStackusingLL();
    // stackLL.displayStackusingLL();
    // stackLL.isEmptyStackusingLL();
    // cout << "Peek element: " << stackLL.peekusingLL() << endl;

    // Queue using Linked List
    Queue QueueLL;
    cout << "Stack Operations Using Linked List:" << endl;
    QueueLL.pushQueueusingLL(10);
    QueueLL.pushQueueusingLL(20);
    QueueLL.pushQueueusingLL(30);
    QueueLL.pushQueueusingLL(40);
    QueueLL.displayQueueusingLL();
    QueueLL.popQueueusingLL();
    QueueLL.displayQueueusingLL();
    QueueLL.popQueueusingLL();
    QueueLL.displayQueueusingLL();
    QueueLL.isEmptyQueueusingLL();
    cout << "Peek element: " << QueueLL.peekQueueusingLL() << endl;

    return 0;
}