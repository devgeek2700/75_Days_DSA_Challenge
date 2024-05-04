#include <bits/stdc++.h>
using namespace std;

// Queue using Arrays

// void Insert(int queue[], int n, int &front, int &rear, int val)
// {
//     if (rear == n - 1)
//     {
//         cout << "Queue Overflow" << endl;
//     }
//     else
//     {
//         if (front == -1)
//         {
//             front = 0;
//         }
//         rear++;
//         queue[rear] = val;
//     }
// }

// void Delete(int queue[], int n, int &front, int &rear)
// {
//     if (front == -1 || front > rear)
//     {
//         cout << "Queue Underflow ";
//         return;
//     }
//     else
//     {
//         cout << "Element deleted from queue is : " << queue[front] << endl;
//         front++;
//     }
// }

// void Display(int queue[], int n, int front, int rear)
// {
//     if (front == -1)
//     {
//         cout << "Queue is empty" << endl;
//     }
//     else
//     {
//         cout << "Queue elements are : ";
//         for (int i = front; i <= rear; i++)
//         {
//             cout << queue[i] << " ";
//         }
//         cout << endl;
//     }
// }

// void isEmpty(int queue[], int n, int front, int rear)
// {
//     if (front == -1)
//     {
//         cout << "Queue is empty" << endl;
//     }
//     else
//     {
//         cout << "Queue is not empty" << endl;
//     }
// }

// void isFull(int queue[], int n, int front, int rear)
// {
//     if (rear == n - 1)
//     {
//         cout << "Queue is Full" << endl;
//     }
//     else
//     {
//         cout << "Queue is not Full" << endl;
//     }
// }

// Queue using queue STL Library

// queue<int> q;

// void Insert(int val)
// {
//     q.push(val);
// }

// void Delete()
// {
//     if (!q.empty())
//     {
//         cout << "Element deleted from queue is : " << q.front() << endl;
//         q.pop();
//     }
//     else
//     {
//         cout << "Queue Underflow" << endl;
//     }
// }

// void Display()
// {
//     if (!q.empty())
//     {
//         cout << "Elements in the queue are:";
//         queue<int> temp = q;
//         while (!temp.empty())
//         {
//             cout << temp.front() << " ";
//             temp.pop();
//         }
//         cout << endl;
//     }
//     else
//     {
//         cout << "Queue Underflow" << endl;
//     }
// }

// void isEmpty()
// {
//     if (q.empty())
//     {
//         cout << "Queue is EMPTY" << endl;
//     }
//     else
//     {
//         cout << "Queue is not EMPTY" << endl;
//     }
// }

// void isFull()
// {
//     cout << "Queue is not FULL" << endl;
// }

// Queue Implementation using Stack

stack<int> st1;
stack<int> st2;

void pushQueueusing2Stack(int val) // TC --> O(N)  SC --> ~ O(2N)
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
}

void popQueueusing2Stack()
{
    if (!st1.empty())
    {
        cout << "Queue elmenent pop using Stack: " << st1.top() << endl;
        st1.pop();
    }
    else
    {
        cout << "stack1 is EMPTY" << endl;
    }
}

void displayQueueusing2Stack()
{
    if (!st1.empty())
    {
        cout << "Elements in the queue using Stack are:";
        stack<int> temp = st1;
        while (!temp.empty())
        {
            cout << temp.top() << " ";
            temp.pop();
        }
        cout << endl;
    }
    else
    {
        cout << "Queue Underflow" << endl;
    }
}

// Queue Implementation using Stack --> O(1) Push and Pop Operations

stack<int> input;
stack<int> output;

void pushQueueusing2optimalStack(int val) // TC --> O(N)  SC --> ~ O(2N)
{
    input.push(val);
}

void popQueueusing2optimalStack()
{
    if (!output.empty())
    {
        cout << "Queue element pop using Stack: " << output.top() << endl;
        output.pop();
    }
    else if (!input.empty())
    {
        while (!input.empty())
        {
            output.push(input.top());
            input.pop();
        }
        cout << "Queue element pop using Stack: " << output.top() << endl;
        output.pop();
    }
    else
    {
        cout << "Queue Underflow" << endl;
    }
}

void displayQueueusing2optimalStack()
{
    if (!input.empty())
    {
        cout << "Elements in the queue using Stack are: ";
        stack<int> temp = input;
        while (!temp.empty())
        {
            cout << temp.top() << " ";
            temp.pop();
        }
        cout << endl;
    }
    else
    {
        cout << "Queue Underflow" << endl;
    }
}

int main()
{
    // int queue[100], n = 100, front = -1, rear = -1;

    // int ch, val;
    // cout << "1) Insert element to queue" << endl;
    // cout << "2) Delete element from queue" << endl;
    // cout << "3) Display all the elements of queue" << endl;
    // cout << "4) Check if Queue Empty" << endl;
    // cout << "5) Check if Queue Full" << endl;
    // cout << "6) Exit" << endl;

    // do
    // {
    //     cout << "Enter your choice : ";
    //     cin >> ch;
    //     switch (ch)
    //     {
    //     case 1:
    //         cout << "Enter value to be inserted : ";
    //         cin >> val;
    //         Insert(queue, n, front, rear, val);
    //         break;
    //     case 2:
    //         Delete(queue, n, front, rear);
    //         break;
    //     case 3:
    //         Display(queue, n, front, rear);
    //         break;
    //     case 4:
    //         isEmpty(queue, n, front, rear);
    //         break;
    //     case 5:
    //         isFull(queue, n, front, rear);
    //         break;
    //     case 6:
    //         cout << "Exit" << endl;
    //         break;
    //     default:
    //         cout << "Invalid choice" << endl;
    //     }
    // } while (ch != 6);

    // Queue using queue STL Library

    // do
    // {
    //     cout << "Enter your choice : ";
    //     cin >> ch;
    //     switch (ch)
    //     {
    //     case 1:
    //         cout << "Enter value to be inserted : ";
    //         cin >> val;
    //         Insert(val);
    //         break;
    //     case 2:
    //         Delete();
    //         break;
    //     case 3:
    //         Display();
    //         break;
    //     case 4:
    //         isEmpty();
    //         break;
    //     case 5:
    //         isFull();
    //         break;
    //     case 6:
    //         cout << "Exit" << endl;
    //         break;
    //     default:
    //         cout << "Invalid choice" << endl;
    //     }
    // } while (ch != 6);

    // Queue Implementation using Stack

    int ch, val;
    cout << "1) Push in Queue using Stack " << endl;
    cout << "2) Pop from Queue using Stack " << endl;
    cout << "3) Display Queue using Stack " << endl;
    cout << "4) Exit" << endl;

    do
    {
        cout << "Enter choice: ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            cout << "Enter value to be pushed: ";
            cin >> val;
            pushQueueusing2optimalStack(val);
            break;
        case 2:
            popQueueusing2optimalStack();
            break;
        case 3:
            displayQueueusing2optimalStack();
            break;
        case 4:
            cout << "Exit" << endl;
            break;
        default:
            cout << "Invalid Choice" << endl;
        }
    } while (ch != 4);

    return 0;
}
