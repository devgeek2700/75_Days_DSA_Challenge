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

//  Infix To Postfix (->)

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
    if ((oprd >= 'a' && oprd <= 'z') ||
        (oprd >= 'A' && oprd <= 'Z') ||
        (oprd >= '0' && oprd <= '9'))
    {
        return true;
    }
    return false;
}

string infixToPostfix(string exp)
{
    stack<char> st;
    string postfixVal;

    for (int i = 0; i < exp.length(); i++)
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
                st.pop(); // Pop '('
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

//  Prefix to Infix
// Post to inf --> B operator A (->)

bool ispost2infixOperand(char oprd)
{
    switch (oprd)
    {
    case '+':
    case '-':
    case '/':
    case '*':
        return true;
    }
    return false;
}
string postToInfix(string &s)
{
    stack<string> expression;

    for (int i = 0; i < s.length(); i++)
    {
        if (ispost2infixOperand(s[i]))
        {
            string op1 = expression.top();
            expression.pop();
            string op2 = expression.top();
            expression.pop();

            string temp = '(' + op2 + s[i] + op1 + ')';
            expression.push(temp);
        }
        else
        {
            expression.push(string(1, s[i]));
        }
    }

    return expression.top();
}

// Prefix to Infix
// Pre to inf --> A operator B (<-)
bool ispre2infixOperand(char oprd)
{
    switch (oprd)
    {
    case '+':
    case '-':
    case '/':
    case '*':
        return true;
    }
    return false;
}

string prefixToInfixConversion(string &s)
{
    stack<string> expression;

    for (int i = s.length() - 1; i >= 0; i--)
    {
        if (ispre2infixOperand(s[i]))
        {
            string op1 = expression.top();
            expression.pop();
            string op2 = expression.top();
            expression.pop();

            string temp = '(' + op1 + s[i] + op2 + ')';
            expression.push(temp);
        }
        else
        {
            expression.push(string(1, s[i]));
        }
    }

    return expression.top();
}

//  Convert Prefix to Postfix
// Prefix to Postfix -->  AB operator (<-)
bool ispreToPostOperand(char oprd)
{
    switch (oprd)
    {
    case '+':
    case '-':
    case '/':
    case '*':
        return true;
    }
    return false;
}

string preToPost(string &s)
{
    stack<string> expression;

    for (int i = s.length() - 1; i >= 0; i--)
    {
        if (ispreToPostOperand(s[i]))
        {
            string op1 = expression.top();
            expression.pop();
            string op2 = expression.top();
            expression.pop();

            string temp = op1 + op2 + s[i];
            expression.push(temp);
        }
        else
        {
            expression.push(string(1, s[i]));
        }
    }

    return expression.top();
}

//  PostFix To Prefix
// PostFix To Prefix -->  operator AB (->)

bool ispostfixToPrefixOperand(char oprd)
{
    switch (oprd)
    {
    case '+':
    case '-':
    case '/':
    case '*':
        return true;
    }
    return false;
}

string postfixToPrefix(string &s)
{
    stack<string> expression;

    for (int i = 0; i < s.length(); i++)
    {
        if (ispostfixToPrefixOperand(s[i]))
        {
            string op1 = expression.top();
            expression.pop();
            string op2 = expression.top();
            expression.pop();

            string temp = s[i] + op2 + op1;
            expression.push(temp);
        }
        else
        {
            expression.push(string(1, s[i]));
        }
    }

    return expression.top();
}

// Infix to Prefix
int infixToPrefixprecedence(char sign)
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

bool isinfixToPrefixOperand(char oprd)
{
    if ((oprd >= 'a' && oprd <= 'z') ||
        (oprd >= 'A' && oprd <= 'Z') ||
        (oprd >= '0' && oprd <= '9'))
    {
        return true;
    }
    return false;
}

string infixToPrefix(string exp)
{
    exp = '(' + exp + ')';
    stack<char> st;
    string PrefixVal;

    for (int i = 0; i < exp.length(); i++)
    {
        if (isinfixToPrefixOperand(exp[i]))
        {
            PrefixVal += exp[i];
        }
        else if (exp[i] == '(')
        {
            st.push(exp[i]);
        }
        else if (exp[i] == ')')
        {
            while (!st.empty() && st.top() != '(')
            {
                PrefixVal += st.top();
                st.pop();
            }
            if (!st.empty())
                st.pop(); // Pop '('
        }
        else
        {
            if (isinfixToPrefixOperand(st.top()))
            {
                while (!st.empty() && infixToPrefixprecedence(exp[i]) <= infixToPrefixprecedence(st.top()))
                {
                    PrefixVal += st.top();
                    st.pop();
                }
                st.push(exp[i]);
            }
            else
            {
                while (!st.empty() && infixToPrefixprecedence(exp[i]) < infixToPrefixprecedence(st.top()))
                {
                    PrefixVal += st.top();
                    st.pop();
                }
                st.push(exp[i]);
            }
        }
    }

    while (!st.empty())
    {
        PrefixVal += st.top();
        st.pop();
    }
    reverse(PrefixVal.begin(), PrefixVal.end());
    return PrefixVal;
}

string infixToPrefixconversion(string infix)
{
    int l = infix.size();

    reverse(infix.begin(), infix.end());

    for (int i = 0; i < l; i++)
    {

        if (infix[i] == '(')
        {
            infix[i] = ')';
            i++;
        }
        else if (infix[i] == ')')
        {
            infix[i] = '(';
            i++;
        }
    }

    string prefix = infixToPrefix(infix);

    return prefix;
}

//  Next Greater Element
// on the right side and then in circular way

vector<int> nextGreaterElementcircular(vector<int> &arr, int n) // TC --> O(2*n)  SC --> O(N)
{
    vector<int> nqe(n, -1);
    stack<int> st;

    for (int i = 0; i <= 2 * n - 1; i++)
    {
        while (!st.empty() && arr[st.top()] < arr[i % n])
        {
            nqe[st.top()] = arr[i % n];
            st.pop();
        }

        if (i < n)
        {
            st.push(i % n);
        }
    }

    return nqe;
}

// on the right side
vector<int> nextGreaterElement(vector<int> &arr, int n) // TC --> O(2*n)  SC --> O(N)
{
    vector<int> nqe(n, -1);
    stack<int> st;

    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && arr[st.top()] < arr[i])
        {
            nqe[st.top()] = arr[i];
            st.pop();
        }
        st.push(i);
    }

    return nqe;
}

//  Immediate Smaller Element
// Mtd-1
void immediateSmaller(vector<int> &arr) // TC --> O(n)  SC --> O(1)
{
    int n = arr.size();

    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            arr[i] = arr[i + 1];
        }
        else
        {
            arr[i] = -1;
        }
    }
    arr[n - 1] = -1;

    for (auto i : arr)
    {
        cout << i << " ";
    }
}

//  Count Of Greater Elements To The Right
vector<int> countGreater(vector<int> &arr, vector<int> &query) // TC --> O(N^2 +Q)  SC --> O(N+Q)
{
    int n = arr.size();
    int q = query.size();
    vector<int> answer;
    vector<int> countarr(n, 0);
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] < arr[j])
            {
                count++;
            }
        }
        countarr[i] = count;
        count = 0;
    }

    for (int i = 0; i < q; i++)
    {
        answer.push_back(countarr[query[i]]);
    }
    return answer;
}

//  Trapping Rain Water
// Mtd - 1 --> using loops
long long getTrappedWater1(vector<int> &arr) // TC --> O(N^2)  SC --> O(1)
{
    long long res = 0;
    int n = arr.size();

    for (int i = 0; i < n; i++)
    {
        int left = arr[i];
        for (int j = 0; j < i; j++)
        {
            left = max(left, arr[j]);
        }

        int right = arr[i];
        for (int j = i + 1; j < n; j++)
        {
            right = max(right, arr[j]);
        }

        res += (min(left, right) - arr[i]);
    }

    return res;
}

// Mtd - 2 --> using Stack

long long getTrappedWater(vector<int> &arr)
{
    long long trappedWater = 0;
    stack<int> st;
    int n = arr.size();

    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && arr[i] > arr[st.top()])
        {
            int top = st.top();
            st.pop();
            if (!st.empty())
            {
                int distance = i - st.top() - 1;
                trappedWater += (min(arr[i], arr[st.top()]) - arr[top]) * distance;
            }
        }
        st.push(i);
    }

    return trappedWater;
}

// Sum of Subarray Minimums
int sumSubarrayMins(vector<int> &arr)
{

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
    //  minStack mst;

    // mst.push(23);
    // mst.push(56);
    // mst.push(78);
    // mst.push(-12);
    // mst.push(98);
    // mst.push(42);

    // cout<<"popped value: "<<mst.top()<<endl;
    // mst.pop();

    // cout<<"top value: "<<mst.top()<<endl;
    // cout<<"Min Value: "<<mst.getMin()<<endl;

    // string str = "a+b+c+d-e";
    // string exp = "ab+c+";
    // string str1 = "*-a/bc-/del";
    // string str2 = "-/A+BC*DE";
    // string str3 = "abc/-ak/l-*";
    // string str4 = "a+b*(c^d-e)^(f+g*h)-i";

    // string postfixAns = infixToPostfix(str);
    // string postfixToInfixConversionAns = postToInfix(exp);
    // string prefixToInfixConversionAns = prefixToInfixConversion(str1);
    // string preToPostAns = preToPost(str2);
    // string postfixToPrefixAns = postfixToPrefix(str3);
    // string infixToPerfixAns = infixToPrefixconversion(str4);

    // cout << "Infix String: " << str << endl;
    // cout << "Infix To Postfix: " << postfixAns << endl;
    // cout << endl;
    // cout << "Postfix String: " << exp << endl;
    // cout << "Postfix to Infix: " << postfixToInfixConversionAns << endl;
    // cout << endl;
    // cout << "Prefix String: " << str1 << endl;
    // cout << "Prefix to Infix: " << prefixToInfixConversionAns << endl;
    // cout << endl;
    // cout << "Prefix String: " << str2 << endl;
    // cout << "Prefix to Postfix: " << preToPostAns << endl;
    // cout << endl;
    // cout << "Postfix String: " << str3 << endl;
    // cout << "PostFix To Prefix: " << postfixToPrefixAns << endl;
    // cout << endl;
    // cout << "Infix String: " << str4 << endl;
    // cout << "Infix to Prefix: " << postfixToPrefixAns << endl;

    vector<int> varr = {3, 1, 2, 4};

    cout << "Display Element: ";
    for (int i = 0; i < varr.size(); i++)
    {
        cout << varr[i] << " ";
    }
    cout << endl;

    // cout << "Next Greater Element: ";
    // vector<int> res = nextGreaterElement(varr, varr.size());
    // for (int i = 0; i < res.size(); i++)
    // {
    //     cout << res[i] << " ";
    // }
    // cout << endl;

    // cout << "Immediate Smaller Element: ";
    // immediateSmaller(varr);

    // cout << "Count Of Greater Elements To The Right: ";
    // vector<int> res = countGreater(varr, query);
    // for (int i = 0; i < res.size(); i++)
    // {
    //     cout << res[i] << " ";
    // }
    // cout << endl;
    // long long res = getTrappedWater(varr);
    // cout << "Trapping Rain Water: " << res << endl;

    int res = sumSubarrayMins(varr);
    cout << "Sum of Subarray Minimums: " << res << endl;

    return 0;
}