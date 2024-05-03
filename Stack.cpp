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
stack<int> st;

void push(int x)
{
    st.push(x);
}

void pop()
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

void Display()
{
    if (st.empty())
    {
        cout << "Stack Underflow" << endl;
    }
    else
    {
        cout << "The Display element is ";
        stack<int> temp = st;
        while (!temp.empty())
        {
            cout << temp.top() << " ";
            temp.pop();
        }
        cout << endl;
    }
}

void Emptyornot()
{
    if (st.empty())
    {
        cout << "Stack Underflow" << endl;
    }
    else
    {
        cout << "Stack is not Empty" << endl;
    }
}

void Fullornot()
{
    cout << "Stack is not Full" << endl;
}

int main()
{
    int stack1[100], n = 100, top = -1;

    int ch, val;
    cout << "1) Push in stack" << endl;
    cout << "2) Pop from stack" << endl;
    cout << "3) Display stack" << endl;
    cout << "4) Check if Stack Empty" << endl;
    cout << "5) Check if Stack Full" << endl;
    cout << "6) Exit" << endl;

    do
    {
        cout << "Enter choice: ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            cout << "Enter value to be pushed: ";
            cin >> val;
            push(val);
            break;
        case 2:
            pop();
            break;
        case 3:
            Display();
            break;
        case 4:
            Emptyornot();
            break;
        case 5:
            Fullornot();
            break;
        case 6:
            cout << "Exit" << endl;
            break;
        default:
            cout << "Invalid Choice" << endl;
        }
    } while (ch != 6);

    return 0;
}