#include <bits/stdc++.h>
using namespace std;

// Stack using Arrays

// void push(int stack[], int n, int &top, int x)
// {
//     if (top >= n - 1)
//     {
//         cout << "Stack Overflow" << endl;
//     }
//     else
//     {
//         top++;
//         stack[top] = x;
//     }
// }

// void pop(int stack[], int n, int &top)
// {
//     if (top <= -1)
//     {
//         cout << "Stack Underflow" << endl;
//     }
//     else
//     {
//         cout << "The popped element is " << stack[top] << endl;
//         top--;
//     }
// }

// void Display(int stack[], int n, int &top)
// {
//     if (top <= -1)
//     {
//         cout << "Stack Underflow" << endl;
//     }
//     else
//     {
//         cout << "Stack elements are: ";
//         for (int i = top; i >= 0; i--)
//         {
//             cout << stack[i] << " ";
//         }
//         cout << endl;
//     }
// }

// void Emptyornot(int stack[], int n, int &top)
// {
//     if (top == -1)
//     {
//         cout << "Stack is Empty" << endl;
//     }
//     else
//     {
//         cout << "Stack is not Empty" << endl;
//     }
// }

// void Fullornot(int stack[], int n, int &top)
// {
//     if (top == n - 1)
//     {
//         cout << "Stack is Full" << endl;
//     }
//     else
//     {
//         cout << "Stack is not Full" << endl;
//     }
// }

// Stack using Stack STL Library
// stack<int> st;

// void push(int x)
// {
//     st.push(x);
// }

// void pop()
// {
//     if (st.empty())
//     {
//         cout << "Stack Underflow" << endl;
//     }
//     else
//     {
//         cout << "The popped element is " << st.top() << endl;
//         st.pop();
//     }
// }

// void Display()
// {
//     if (st.empty())
//     {
//         cout << "Stack Underflow" << endl;
//     }
//     else
//     {
//         cout << "The Display element is ";
//         stack<int> temp = st;
//         while (!temp.empty())
//         {
//             cout << temp.top() << " ";
//             temp.pop();
//         }
//         cout << endl;
//     }
// }

// void Emptyornot()
// {
//     if (st.empty())
//     {
//         cout << "Stack Underflow" << endl;
//     }
//     else
//     {
//         cout << "Stack is not Empty" << endl;
//     }
// }

// void Fullornot()
// {
//     cout << "Stack is not Full" << endl;
// }

// Stack Implementation using a Two Queues

queue<int> q1;
queue<int> q2;

void pushStackusing2Queue(int val) // TC --> O(N)  SC --> ~ O(N)
{
    q2.push(val);

    while (!q1.empty())
    {
        q2.push(q1.front());
        q1.pop();
    }
    swap(q1, q2);
}

void popStackusing2Queue()
{
    if (!q1.empty())
    {
        cout << "Stack elmenent pop using queue: " << q1.front() << endl;
        q1.pop();
    }
    else
    {
        cout << "Queue1 is EMPTY" << endl;
    }
}

void displayStackusing2Queue()
{
    if (!q1.empty())
    {
        cout << "Elements in the queue are:";
        queue<int> temp = q1;
        while (!temp.empty())
        {
            cout << temp.front() << " ";
            temp.pop();
        }
        cout << endl;
    }
    else
    {
        cout << "Queue Underflow" << endl;
    }
}

// Stack Implementation using a Single Queue
queue<int> qu1;

void pushStackusing1Queue(int val) // TC --> O(N)  SC --> O(N)
{
    qu1.push(val);

    for (int i = 0; i < qu1.size() - 1; i++)
    {
        qu1.push(qu1.front());
        qu1.pop();
    }
}

void popStackusing1Queue()
{
    if (!qu1.empty())
    {
        cout << "Stack elmenent pop using queue: " << qu1.front() << endl;
        qu1.pop();
    }
    else
    {
        cout << "Queue1 is EMPTY" << endl;
    }
}

void displayStackusing1Queue()
{
    if (!qu1.empty())
    {
        cout << "Elements in the queue are:";
        queue<int> temp = qu1;
        while (!temp.empty())
        {
            cout << temp.front() << " ";
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
    // int stack1[100], n = 100, top = -1;

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
    //         push(val);
    //         break;
    //     case 2:
    //         pop();
    //         break;
    //     case 3:
    //         Display();
    //         break;
    //     case 4:
    //         Emptyornot();
    //         break;
    //     case 5:
    //         Fullornot();
    //         break;
    //     case 6:
    //         cout << "Exit" << endl;
    //         break;
    //     default:
    //         cout << "Invalid Choice" << endl;
    //     }
    // } while (ch != 6);

    // Stack Implementation using a Single Queue

    // int ch, val;
    // cout << "1) Push in stack using Queue" << endl;
    // cout << "2) Pop from stack using Queue" << endl;
    // cout << "3) Display stack using Queue" << endl;
    // cout << "4) Exit" << endl;

    // do
    // {
    //     cout << "Enter choice: ";
    //     cin >> ch;
    //     switch (ch)
    //     {
    //     case 1:
    //         cout << "Enter value to be pushed: ";
    //         cin >> val;
    //         pushStackusing2Queue(val);
    //         break;
    //     case 2:
    //         popStackusing2Queue();
    //         break;
    //     case 3:
    //         displayStackusing2Queue();
    //         break;
    //     case 4:
    //         cout << "Exit" << endl;
    //         break;
    //     default:
    //         cout << "Invalid Choice" << endl;
    //     }
    // } while (ch != 4);

    // Stack Implementation using a Single Queue

    int ch, val;
    cout << "1) Push in stack using Queue" << endl;
    cout << "2) Pop from stack using Queue" << endl;
    cout << "3) Display stack using Queue" << endl;
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
            pushStackusing1Queue(val);
            break;
        case 2:
            popStackusing1Queue();
            break;
        case 3:
            displayStackusing1Queue();
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