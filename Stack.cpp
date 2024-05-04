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

// queue<int> q1;
// queue<int> q2;

// void pushStackusing2Queue(int val) // TC --> O(N)  SC --> ~ O(2N)
// {
//     q2.push(val);

//     while (!q1.empty())
//     {
//         q2.push(q1.front());
//         q1.pop();
//     }
//     swap(q1, q2);
// }

// void popStackusing2Queue()
// {
//     if (!q1.empty())
//     {
//         cout << "Stack elmenent pop using queue: " << q1.front() << endl;
//         q1.pop();
//     }
//     else
//     {
//         cout << "Queue1 is EMPTY" << endl;
//     }
// }

// void displayStackusing2Queue()
// {
//     if (!q1.empty())
//     {
//         cout << "Elements in the queue are:";
//         queue<int> temp = q1;
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

// // Stack Implementation using a Single Queue
// queue<int> qu1;

// void pushStackusing1Queue(int val) // TC --> O(N)  SC --> O(N)
// {
//     qu1.push(val);

//     for (int i = 0; i < qu1.size() - 1; i++)
//     {
//         qu1.push(qu1.front());
//         qu1.pop();
//     }
// }

// void popStackusing1Queue()
// {
//     if (!qu1.empty())
//     {
//         cout << "Stack elmenent pop using queue: " << qu1.front() << endl;
//         qu1.pop();
//     }
//     else
//     {
//         cout << "Queue1 is EMPTY" << endl;
//     }
// }

// void displayStackusing1Queue()
// {
//     if (!qu1.empty())
//     {
//         cout << "Elements in the queue are:";
//         queue<int> temp = qu1;
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

// Implement stack using Linkedlist
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

class Stack
{
    Node *top;

public:
    Stack()
    {
        top = nullptr;
    }

    void pushStackusingLL(int val)
    {
        Node *temp = new Node(val);

        if (!temp)
        {
            cout << "Stack Overflow!" << endl;
            exit(1);
        }
        temp->data = val;
        temp->next = top;
        top = temp;
    }

    bool isEmptyStackusingLL()
    {
        return top == NULL;
    }

    int peek_topStackusingLL()
    {
        if (!isEmptyStackusingLL())
        {
            return top->data;
        }
        else
        {
            cout << "Stack Underflow!" << endl;
            exit(1);
        }
    }

    void popStackusingLL()
    {
        Node *temp;

        if (isEmptyStackusingLL())
        {
            cout << "\nStack Underflow" << endl;
            exit(1);
        }
        else
        {
            temp = top;
            top = top->next;
            delete (temp);
        }
    }

    void displayStackusingLL()
    {
        Node *temp;

        if (isEmptyStackusingLL())
        {
            cout << "\nStack Underflow" << endl;
            exit(1);
        }
        else
        {
            temp = top;
            while (temp != NULL)
            {
                cout << temp->data << " ";
                temp = temp->next;
                if (temp != NULL)
                {
                    cout << " -> ";
                }
            }
        }
    }
};

// Valid Parentheses

bool isValidParenthesis(string str)
{
    stack<char> st;

    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '(' || str[i] == '[' || str[i] == '{')
        {
            st.push(str[i]);
        }
        else
        {
            if (st.empty())
            {
                return false;
            }

            char ch = st.top();
            st.pop();
            if ((str[i] == ')' && ch != '(') || (str[i] == ']' && ch != '[') || (str[i] == '}' && ch != '{'))
            {
                return false;
            }
        }
    }

    return st.empty();
}

//  Min Stack
class minStack
{
    stack<long long> st;
    long long mini;

public:
    // Constructor
    minStack()
    {
        while (st.empty() == false)
        {
            st.pop();
        }
        mini = INT_MAX;
    }

   void push(int num)
    {
        long long val = num;
        if (st.empty())
        {
            mini = val;
            st.push(val);
        }
        else
        {
            if (val < mini)
            {
                st.push(2 * val * 1LL - mini);
                mini = val;
            }
            else
            {
                st.push(val);
            }
        }
    }
    void pop()
    {
        if (st.empty())
        {
            return;
        }

        long long el = st.top();
        st.pop();

        if (el < mini)
        {
            mini = 2 * mini - el;
        }
    }

    int top()
    {
        if (st.empty())
        {
            return -1;
        }

        long long el = st.top();

        if (el < mini)
        {
            return mini;
        }
        return el;
    }

    int getMin()
    {
        return mini;
    }
};

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
    //         pushStackusing1Queue(val);
    //         break;
    //     case 2:
    //         popStackusing1Queue();
    //         break;
    //     case 3:
    //         displayStackusing1Queue();
    //         break;
    //     case 4:
    //         cout << "Exit" << endl;
    //         break;
    //     default:
    //         cout << "Invalid Choice" << endl;
    //     }
    // } while (ch != 4);

    // Implement stack using Linkedlist

    // Stack s;

    // // Push
    // s.pushStackusingLL(11);
    // s.pushStackusingLL(34);
    // s.pushStackusingLL(56);
    // s.pushStackusingLL(67);
    // s.pushStackusingLL(22);
    // s.pushStackusingLL(90);

    // // Display
    // s.displayStackusingLL();

    // cout << "\nTop element is " << s.peek_topStackusingLL() << endl;

    // // Delete
    // s.popStackusingLL();
    // s.popStackusingLL();
    // s.popStackusingLL();

    // // Print top
    // cout << "\nTop element is " << s.peek_topStackusingLL() << endl;

    // Valid Parentheses
    // string str = "[[}[";
    // cout << "strin is: " << str << endl;

    // if (isValidParenthesis(str))
    // {
    //     cout << "Parentheses are Balanced" << endl;
    // }
    // else
    // {
    //     cout << "Parentheses are Not Balanced" << endl;
    // }

    //  Min Stack
     minStack mst;

    mst.push(23);
    mst.push(56);
    mst.push(78);
    mst.push(-12);
    mst.push(98);
    mst.push(42);

    cout<<"popped value: "<<mst.top()<<endl;
    mst.pop();

    cout<<"top value: "<<mst.top()<<endl;
    cout<<"Min Value: "<<mst.getMin()<<endl;
    


    return 0;
}