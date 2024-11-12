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

int main()
{
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

    int queue[100];
    int n = 100;
    int front = -1;
    int rear = -1;

    int ch, val;
    cout << "1) Enqueue in queue" << endl;
    cout << "2) Dequeue from queue" << endl;
    cout << "3) Display queue" << endl;
    cout << "4) Check if Queue is Empty" << endl;
    cout << "5) Check if Queue is Full" << endl;
    cout << "6) Exit" << endl;

    do
    {
        cout << "Enter choice: ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            cout << "Enter value to be enqueued: ";
            cin >> val;
            enqueue(queue, n, front, rear, val);
            break;
        case 2:
            dequeue(queue, front, rear);
            break;
        case 3:
            display(queue, front, rear);
            break;
        case 4:
            isEmpty(front);
            break;
        case 5:
            isFull(rear, n);
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