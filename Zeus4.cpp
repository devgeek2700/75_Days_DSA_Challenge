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

// Valid Parentheses

bool isValid(string s)
{
    stack<char> st;
    if (s.length() < 2)
    {
        return false;
    }

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{')
        {
            st.push(s[i]);
        }
        else
        {
            if (st.empty())
            {
                return false;
            }

            char lastChar = st.top();
            st.pop();
            if (s[i] == ')' && lastChar != '(' ||
                s[i] == ']' && lastChar != '[' ||
                s[i] == '}' && lastChar != '{')
            {
                return false;
            }
        }
    }
    return st.empty();
}

// Min Stack
class MinStack
{
    stack<pair<int, int>> st;

public:
    MinStack() {}

    void push(int val)
    {
        if (st.empty())
        {
            st.push({val, val});
        }
        else
        {
            st.push({val, min(val, st.top().second)});
        }
    }

    void pop()
    {
        if (st.empty())
        {
            cout << "Stack Underflow" << endl;
            return;
        }
        st.pop();
    }

    int top()
    {
        if (st.empty())
        {
            cout << "Stack Underflow" << endl;
            return -1;
        }
        return st.top().first;
    }

    int getMin()
    {
        if (st.empty())
        {
            cout << "Stack Underflow" << endl;
            return -1;
        }
        return st.top().second;
    }
};

// Infix to Postfix Conversion

int precedence(char sign)
{
    if (sign == '^')
    {
        return 3;
    }
    else if (sign == '/' || sign == '*')
    {
        return 2;
    }
    else if (sign == '+' || sign == '-')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

bool isOperand(char oprd)
{
    if ((oprd >= 'a' && oprd <= 'z') || (oprd >= 'A' && oprd <= 'Z') || (oprd >= '0' && oprd <= '9'))
    {
        return true;
    }
    return false;
}

string infixToPostfix(string exp)
{
    stack<char> st;
    string postfixVal;

    for (int i = 0; i < exp.size(); i++)
    {
        if (isOperand(exp[i]))
        {
            postfixVal += exp[i];
        }
        else if (exp[i] == '(')
        {
            st.push(exp[i]);
        }
        else if (exp[i] == ')')
        {
            while (!st.empty() && st.top() != '(')
            {
                postfixVal += st.top();
                st.pop();
            }
            if (!st.empty())
            {
                st.pop();
            }
        }
        else
        {
            while (!st.empty() && precedence(exp[i]) <= precedence(st.top()))
            {
                postfixVal += st.top();
                st.pop();
            }
            st.push(exp[i]);
        }
    }

    while (!st.empty())
    {
        postfixVal += st.top();
        st.pop();
    }

    return postfixVal;
}

// Prefix to Infix Conversion

bool ispre2infixOperand(char oprd)
{
    if ((oprd == '*') || (oprd == '/') || (oprd == '+') || (oprd == '-'))
    {
        return true;
    }
    else
    {
        return false;
    }
}

string preToInfix(string pre_exp)
{
    stack<string> st;
    int n = pre_exp.length();

    for (int i = n - 1; i >= 0; i--)
    {
        if (ispre2infixOperand(pre_exp[i]))
        {
            string a = st.top();
            st.pop();
            string b = st.top();
            st.pop();

            string temp = '(' + a + pre_exp[i] + b + ')';
            st.push(temp);
        }
        else
        {
            st.push(string(1, pre_exp[i]));
        }
    }
    return st.top();
}

// Prefix to Postfix Conversion
bool ispre2postfixOperand(char oprd)
{
    if ((oprd == '*') || (oprd == '/') || (oprd == '+') || (oprd == '-'))
    {
        return true;
    }
    else
    {
        return false;
    }
}

string preToPost(string pre_exp)
{
    int n = pre_exp.length();
    stack<string> st;

    for (int i = n - 1; i >= 0; i--)
    {
        if (ispre2postfixOperand(pre_exp[i]))
        {
            string op1 = st.top();
            st.pop();
            string op2 = st.top();
            st.pop();

            string temp = op1 + op2 + pre_exp[i];
            st.push(temp);
        }
        else
        {
            st.push(string(1, pre_exp[i]));
        }
    }
    return st.top();
}

// Postfix to Prefix Conversion

bool ispost2prefixOperand(char oprd)
{
    if ((oprd == '*') || (oprd == '/') || (oprd == '+') || (oprd == '-'))
    {
        return true;
    }
    else
    {
        return false;
    }
}

string postToPre(string post_exp)
{
    int n = post_exp.length();
    stack<string> st;

    for (int i = 0; i < n; i++)
    {
        if (ispost2prefixOperand(post_exp[i]))
        {
            string op1 = st.top();
            st.pop();
            string op2 = st.top();
            st.pop();

            string temp = post_exp[i] + op2 + op1;
            st.push(temp);
        }
        else
        {
            st.push(string(1, post_exp[i]));
        }
    }
    return st.top();
}

// Postfix to Infix Conversion
bool ispost2infixOperand(char oprd)
{
    if ((oprd == '*') || (oprd == '/') || (oprd == '+') || (oprd == '-'))
    {
        return true;
    }
    else
    {
        return false;
    }
}

string postToInfix(string exp)
{
    int n = exp.length();
    stack<string> st;

    for (int i = 0; i < n; i++)
    {
        if (ispost2infixOperand(exp[i]))
        {
            string op1 = st.top();
            st.pop();

            string op2 = st.top();
            st.pop();

            string temp = '(' + op2 + exp[i] + op1 + ')';
            st.push(temp);
        }
        else
        {
            st.push(string(1, exp[i]));
        }
    }
    return st.top();
}

// Infix to Pretfix Conversion

int precedenceinfixToPrefix(char sign)
{
    if (sign == '^')
    {
        return 3;
    }
    else if (sign == '/' || sign == '*')
    {
        return 2;
    }
    else if (sign == '+' || sign == '-')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

bool isOperandinfixToPrefix(char c)
{
    return isalnum(c);
}

string infixToPrefixConversion(string s)
{
    int n = s.length();
    stack<char> st;
    string prefixVal;

    for (int i = 0; i < n; i++)
    {
        if (isOperandinfixToPrefix(s[i]))
        {
            prefixVal += s[i];
        }
        else if (s[i] == '(')
        {
            st.push(s[i]);
        }
        else if (s[i] == ')')
        {
            while (!st.empty() && st.top() != '(')
            {
                prefixVal += st.top();
                st.pop();
            }
            if (!st.empty())
            {
                st.pop();
            }
        }
        else
        {
            while (!st.empty() && precedenceinfixToPrefix(st.top()) >= precedenceinfixToPrefix(s[i]))
            {
                prefixVal += st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }

    while (!st.empty())
    {
        prefixVal += st.top();
        st.pop();
    }

    return prefixVal;
}

string infixtoprefix(string s)
{
    int n = s.length();

    reverse(s.begin(), s.end());

    for (int i = 0; i < n; i++)
    {
        if (s[i] == '(')
            s[i] = ')';
        else if (s[i] == ')')
            s[i] = '(';
    }

    string prefix = infixToPrefixConversion(s);

    reverse(prefix.begin(), prefix.end());

    return prefix;
}

// Next Greater Element I
vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
{
    stack<int> st;
    unordered_map<int, int> mpp;
    vector<int> ans;

    for (int i = 0; i < nums2.size(); i++)
    {
        while (!st.empty() && st.top() < nums2[i])
        {
            mpp[st.top()] = nums2[i];
            st.pop();
        }
        st.push(nums2[i]);
    }

    while (!st.empty())
    {
        mpp[st.top()] = -1;
        st.pop();
    }

    for (int i = 0; i < nums1.size(); i++)
    {
        ans.push_back(mpp[nums1[i]]);
    }

    return ans;
}

// Next Greater Element II
vector<int> nextGreaterElements2(vector<int> &nums)
{
    int n = nums.size();
    stack<int> st;
    vector<int> ans(n, -1);

    for (int i = 2 * n - 1; i >= 0; i--)
    {
        int idx = i % n;

        // Pop elements from the stack that are less than or equal to the current element
        while (!st.empty() && nums[st.top()] <= nums[idx])
        {
            st.pop();
        }

        // If stack is not empty, the top of the stack is the next greater element
        if (!st.empty())
        {
            ans[idx] = nums[st.top()];
        }

        // Push current index onto the stack

        st.push(idx);
    }
    return ans;
}

// Next Smaller Element
vector<int> nextSmallerElements2(vector<int> &nums)
{
    int n = nums.size();
    stack<int> st;
    vector<int> ans(n, -1);

    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && nums[st.top()] >= nums[i])
        {
            st.pop();
        }

        if (!st.empty())
        {
            ans[i] = nums[st.top()];
        }

        st.push(i);
    }

    return ans;
}

// Number of NGEs to the right
vector<int> count_NGE(int n, vector<int> &arr, int queries, vector<int> &indices)
{
    vector<int> NGEs(queries, 0);

    for (int i = 0; i < queries; i++)
    {
        int idx = indices[i];
        int count = 0;

        for (int j = idx + 1; j < n; j++)
        {
            if (arr[j] > arr[idx])
            {
                count++;
            }
        }

        NGEs[i] = count;
    }
    return NGEs;
}

// Sum of Subarray Minimums
vector<int> findprevSmallerElement(vector<int> &arr)
{
    int n = arr.size();
    vector<int> pse(n, -1);
    stack<int> st;

    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && arr[st.top()] > arr[i])
        {
            st.pop();
        }

        if (!st.empty())
        {
            pse[i] = st.top();
        }
        st.push(i);
    }
    return pse;
}

vector<int> findnextSmallerElement(vector<int> &arr)
{
    int n = arr.size();
    vector<int> nse(n, n);
    stack<int> st;

    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && arr[st.top()] >= arr[i])
        {
            st.pop();
        }

        if (!st.empty())
        {
            nse[i] = st.top();
        }
        st.push(i);
    }
    return nse;
}

int sumSubarrayMins(vector<int> &arr)
{
    int n = arr.size();
    int totalSum = 0;
    int MOD = 1e9 + 7;

    vector<int> pse = findprevSmallerElement(arr);
    vector<int> nse = findnextSmallerElement(arr);

    for (int i = 0; i < n; i++)
    {
        int left = i - pse[i];
        int right = nse[i] - i;
        totalSum = (totalSum + (long long)arr[i] * left * right) % MOD;
    }
    return totalSum;
}

// Asteroid Collision
vector<int> asteroidCollision(vector<int> &asteroids)
{
    int n = asteroids.size();
    stack<int> st;

    for (int i = 0; i < n; i++)
    {
        if (asteroids[i] > 0)
        {
            st.push(asteroids[i]);
        }
        // for Collision
        else
        {
            while (!st.empty() && st.top() > 0 && st.top() < abs(asteroids[i]))
            {
                st.pop();
            }

            if (!st.empty() && st.top() > 0 && st.top() == abs(asteroids[i]))
            {
                st.pop();
            }
            else if (!st.empty() && st.top() > 0)
            {
                continue;
            }
            else
            {
                st.push(asteroids[i]);
            }
        }
    }

    vector<int> ans;
    while (!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }

    reverse(ans.begin(), ans.end());
    return ans;
}

// Sum of Subarray Ranges
// Sum of Subarray Minimums
vector<int> subArrayRangesfindprevSmallerElement(vector<int> &arr)
{
    int n = arr.size();
    vector<int> pse(n, -1);
    stack<int> st;

    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && arr[st.top()] > arr[i])
        {
            st.pop();
        }

        if (!st.empty())
        {
            pse[i] = st.top();
        }
        st.push(i);
    }
    return pse;
}

vector<int> subArrayRangesfindnextSmallerElement(vector<int> &arr)
{
    int n = arr.size();
    vector<int> nse(n, n);
    stack<int> st;

    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && arr[st.top()] >= arr[i])
        {
            st.pop();
        }

        if (!st.empty())
        {
            nse[i] = st.top();
        }
        st.push(i);
    }
    return nse;
}

int subArrayRangessumSubarrayMins(vector<int> &arr)
{
    int n = arr.size();
    int totalSum = 0;
    int MOD = 1e9 + 7;

    vector<int> pse = subArrayRangesfindprevSmallerElement(arr);
    vector<int> nse = subArrayRangesfindnextSmallerElement(arr);

    for (int i = 0; i < n; i++)
    {
        int left = i - pse[i];
        int right = nse[i] - i;
        totalSum = (totalSum + (long long)arr[i] * left * right) % MOD;
    }
    return totalSum;
}

// Sum of Subarray Maximums
vector<int> findPrevGreaterElement(vector<int> &arr)
{
    int n = arr.size();
    vector<int> pge(n, -1);
    stack<int> st;

    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && arr[st.top()] < arr[i])
        {
            st.pop();
        }

        if (!st.empty())
        {
            pge[i] = st.top();
        }
        st.push(i);
    }
    return pge;
}

vector<int> findNextGreaterElement(vector<int> &arr)
{
    int n = arr.size();
    vector<int> nge(n, n);
    stack<int> st;

    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && arr[st.top()] <= arr[i])
        {
            st.pop();
        }

        if (!st.empty())
        {
            nge[i] = st.top();
        }
        st.push(i);
    }
    return nge;
}

int sumSubarrayMaxs(vector<int> &arr)
{
    int n = arr.size();
    int totalSum = 0;
    int MOD = 1e9 + 7;

    vector<int> pge = findPrevGreaterElement(arr);
    vector<int> nge = findNextGreaterElement(arr);

    for (int i = 0; i < n; i++)
    {
        int left = i - pge[i];
        int right = nge[i] - i;
        totalSum = (totalSum + (long long)arr[i] * left * right) % MOD;
    }
    return totalSum;
}

// 	Sum of subarray ranges
long long subArrayRanges(vector<int> &nums)
{
    return (long long)sumSubarrayMaxs(nums) - sumSubarrayMins(nums);
}

// Remove K Digits
string removeKdigits(string num, int k)
{
    int n = num.size();
    if (k == n)
    {
        return "0";
    }

    stack<char> st;
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && k > 0 && (st.top() - '0' > num[i] - '0'))
        {
            st.pop();
            k--;
        }
        st.push(num[i]);
    }

    while (k > 0)
    {
        st.pop();
        k--;
    }

    string ans = "";
    while (!st.empty())
    {
        ans += st.top();
        st.pop();
    }

    reverse(ans.begin(), ans.end());

    // Check if the resulting string is empty
    if (ans.empty())
    {
        return "0";
    }

    // Remove leading zeros
    int start = 0;
    while (start < ans.size() && ans[start] == '0')
    {
        start++;
    }

    return start == ans.size() ? "0" : ans.substr(start);
}

// Largest Rectangle in Histogram

vector<int> findprevSmallerElementHistogram(vector<int> &arr)
{
    int n = arr.size();
    vector<int> pse(n, -1);
    stack<int> st;

    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && arr[st.top()] > arr[i])
        {
            st.pop();
        }

        if (!st.empty())
        {
            pse[i] = st.top();
        }
        st.push(i);
    }
    return pse;
}

vector<int> findnextSmallerElementHistogram(vector<int> &arr)
{
    int n = arr.size();
    vector<int> nse(n, n);
    stack<int> st;

    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && arr[st.top()] >= arr[i])
        {
            st.pop();
        }

        if (!st.empty())
        {
            nse[i] = st.top();
        }
        st.push(i);
    }
    return nse;
}

int largestRectangleArea(vector<int> &heights)
{
    int n = heights.size();
    int maxArea = 0;
    vector<int> pse = findprevSmallerElementHistogram(heights);
    vector<int> nse = findnextSmallerElementHistogram(heights);

    for (int i = 0; i < n; i++)
    {
        maxArea = max(maxArea, heights[i] * (nse[i] - pse[i] - 1));
    }
    return maxArea;
}

// Maximal Rectangle
int maximalRectangle(vector<vector<char>> &matrix)
{
    if (matrix.empty())
        return 0;

    int n = matrix.size();
    int m = matrix[0].size();
    int maxRect = 0;
    vector<int> heights(m, 0);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == '1')
            {
                heights[j] += 1;
            }
            else
            {
                heights[j] = 0;
            }
        }
        maxRect = max(maxRect, largestRectangleArea(heights));
    }
    return maxRect;
}

// Trapping Rain Water
int trap(vector<int> &height)
{
    int n = height.size();
    stack<int> st;
    int trappedWater = 0;

    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && height[i] > height[st.top()])
        {
            int top = st.top();
            st.pop();
            if (!st.empty())
            {
                int distance = i - st.top() - 1;
                trappedWater += (min(height[i], height[st.top()]) - height[top]) * distance;
            }
        }
        st.push(i);
    }
    return trappedWater;
}

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
    // Queue QueueLL;
    // cout << "Stack Operations Using Linked List:" << endl;
    // QueueLL.pushQueueusingLL(10);
    // QueueLL.pushQueueusingLL(20);
    // QueueLL.pushQueueusingLL(30);
    // QueueLL.pushQueueusingLL(40);
    // QueueLL.displayQueueusingLL();
    // QueueLL.popQueueusingLL();
    // QueueLL.displayQueueusingLL();
    // QueueLL.popQueueusingLL();
    // QueueLL.displayQueueusingLL();
    // QueueLL.isEmptyQueueusingLL();
    // cout << "Peek element: " << QueueLL.peekQueueusingLL() << endl;

    // cout << isValid("(]") << endl;

    // MinStack minStack;
    // minStack.push(-2);
    // minStack.push(0);
    // minStack.push(-3);
    // cout << minStack.getMin() << endl; // return -3
    // minStack.pop();
    // cout << minStack.top() << endl;    // return 0
    // cout << minStack.getMin() << endl; // return -2

    // string str = "(A-B/C)*(A/K-L)";
    // cout << infixToPostfix(str) << endl;
    // cout << preToInfix(str) << endl;
    // cout << preToPost(str) << endl;
    // cout << postToPre(str) << endl;
    // cout << postToInfix(str) << endl;
    // cout << infixtoprefix(str) << endl;

    // vector<int> nums2 = {1, 2, 3, 4};
    // vector<int> result = nextGreaterElement(nums1, nums2);
    // vector<int> result = nextGreaterElements2(nums1);
    // vector<int> result = nextSmallerElements2(nums1);

    // vector<int> arr = {2, 1, 5, 6, 2, 3};
    // vector<int> indices = {0, 3};

    // int n = arr.size();
    // int queries = indices.size();

    // vector<int> result = count_NGE(n, arr, queries, indices);

    // for (int x : result)
    // {
    //     cout << x << " ";
    // }

    // cout << "Sum of Subarray Minimums: " << sumSubarrayMins(arr) << endl;

    // vector<int> result = asteroidCollision(arr);

    // for (int x : result)
    // {
    //     cout << x << " ";
    // }

    // cout << "Sum of Subarray Ranges: " << subArrayRanges(arr) << endl;

    // cout << removeKdigits("10", 2) << endl;
    // cout << largestRectangleArea(arr) << endl;

    // vector<vector<char>> matrix = {{'1', '0', '1', '0', '0'}, {'1', '0', '1', '1', '1'}, {'1', '1', '1', '1', '1'}, {'1', '0', '0', '1', '0'}};
    // cout << maximalRectangle(matrix) << endl;

    vector<int> height = {4, 2, 0, 3, 2, 5};
    cout << trap(height) << endl;

    return 0;
}