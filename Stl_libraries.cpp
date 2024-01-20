#include <bits/stdc++.h>
using namespace std;

void print()
{
    cout << "function void";
}

int sum(int a, int b)
{
    return a + b;
}

// Explain pairs
void explainPAir()
{
    // Normal pairs
    pair<int, int> p = {3, 5};
    cout << "p.first: " << p.first << " "
         << "p.second: " << p.second << endl;

    cout << endl;

    // Nested pairs
    pair<int, pair<int, int>> np = {30, {56, 89}};
    cout << "np.first: " << np.first << " "
         << "np.second.first: " << np.second.first << " "
         << "np.second.second: " << np.second.second << endl;
    cout << endl;

    // Array pairs
    pair<int, int> arr[] = {{34, 50}, {22, 77}, {20, 48}};
    cout << "arr[0].first: " << arr[0].first << " "
         << "arr[1].first: " << arr[1].first << " "
         << "arr[2].second: " << arr[2].second << endl;
}

// Explain Vectors
void explainVectors()
{
    vector<int> v;
    v.push_back(20);
    cout << "V[0]: " << v[0] << endl;

    v.emplace_back(30);
    cout << "V[1]: " << v[1] << " ";

    // pairs in vectors
    vector<pair<int, int>> vpr;
    vpr.push_back({11, 22});
    vpr.emplace_back(45, 78);

    // instances by size
    vector<int> sv(5, 39);

    vector<int> grbval(6);

    // copy the vector to another vector
    vector<int> cpyv(sv);

    cout << endl;

    // Access
    vector<int> acc(5, 30);

    cout << "acc[0]: " << acc[0] << endl;

    vector<int> loopv;
    loopv.push_back(10);
    loopv.push_back(58);
    loopv.push_back(29);
    loopv.push_back(88);

    // Iterators in Vector by v.begin --> it posint to the memory not the element
    vector<int>::iterator it = loopv.begin();
    it++;
    cout << "it++:  " << *(it) << endl;

    it = it + 2;
    cout << "it+2:  " << *(it) << endl;

    // Access the array with loops
    vector<int> loopvector;
    loopvector.push_back(30);
    loopvector.push_back(44);
    loopvector.push_back(56);
    loopvector.push_back(98);

    // Access the array
    cout << "loopvector with arr: ";
    for (int i = 0; i < 4; i++)
    {
        cout << loopvector[i] << " ";
    }

    cout << endl;

    // Print the vetors using Iterators
    cout << "loopvector with iterator: ";
    for (vector<int>::iterator lpvc = loopvector.begin(); lpvc != loopvector.end(); lpvc++)
    {
        cout << *(lpvc) << " ";
    }
    cout << endl;

    // shortcut for Printing the vetors using Iterators
    cout << "loopvector with iterator with shortcut: ";
    for (auto lpvcs = loopvector.begin(); lpvcs != loopvector.end(); lpvcs++)
    {
        cout << *(lpvcs) << " ";
    }
    cout << endl;

    // forEach loop
    cout << "loopvector with forEach loop: ";
    for (auto alpv : loopvector)
    {
        cout << alpv << " ";
    }

    cout << endl;

    // delete vectors
    loopvector.erase(loopvector.begin() + 1);

    // loopvector after earse
    cout << "loopvector after earse: ";
    for (auto alpv : loopvector)
    {
        cout << alpv << " ";
    }

    loopvector.push_back(156);
    loopvector.push_back(908);
    cout << endl;

    cout << "loopvector before multiple earse: ";
    for (auto alpv : loopvector)
    {
        cout << alpv << " ";
    }

    // delete multiple elements
    loopvector.erase(loopvector.begin() + 1, loopvector.begin() + 4);
    cout << endl;

    cout << "loopvector after multiple earse: ";
    for (auto alpv : loopvector)
    {
        cout << alpv << " ";
    }

    // Insert Functions
    vector<int> vacc(5, 200);
    cout << endl;

    cout << "Insert Functions: ";
    for (auto accit : vacc)
    {
        cout << accit << " ";
    }

    // Insert Functions only at start
    vacc.insert(vacc.begin(), 278);

    cout << endl;

    cout << "Insert Functions at start only: ";
    for (auto accit : vacc)
    {
        cout << accit << " ";
    }

    // insert to another vector

    vector<int> anvacc(2, 888);
    loopvector.insert(loopvector.begin(), anvacc.begin(), anvacc.end());

    cout << endl;

    cout << "insert to another vector: ";
    for (auto anvacclp : loopvector)
    {
        cout << anvacclp << " ";
    }

    // size of vector
    cout << endl;
    cout << "size is: " << loopvector.size() << endl;

    // pop element out
    vector<int> v1;
    v1.push_back(12);
    v1.push_back(378);
    v1.push_back(120);

    cout << "pop element out before: ";
    for (auto poplp : v1)
    {
        cout << poplp << " ";
    }

    v1.pop_back();
    cout << endl;
    cout << "pop element out after: ";
    for (auto poplp : v1)
    {
        cout << poplp << " ";
    }

    vector<int> v2 = {33, 66, 78, 99, 865};
    cout << endl;
    cout << "v1 lements before: ";
    for (auto showv1 : v1)
    {
        cout << showv1 << " ";
    }

    cout << endl;
    cout << "v1 lements before: ";
    for (auto showv2 : v2)
    {
        cout << showv2 << " ";
    }

    v1.swap(v2);

    cout << endl;
    cout << "v1 lements after: ";
    for (auto swapv1 : v1)
    {
        cout << swapv1 << " ";
    }

    cout << endl;
    cout << "v1 lements after: ";
    for (auto swapv2 : v2)
    {
        cout << swapv2 << " ";
    }

    // erase entire vector
    v1.clear();

    cout << endl;
    cout << "v1 entire cleared: ";
    for (auto clrv1 : v1)
    {
        cout << clrv1 << " ";
    }
    cout << endl;

    // check vector is empty or not
    cout << "Empty vector or not: " << v1.empty() << endl;
}

void explainList()
{
    list<int> ls;
    ls.push_back(33);
    ls.emplace_back(56);
    ls.push_front(209);
    ls.emplace_front(111);

    cout << endl;
    cout << "push_back list: ";
    for (auto clrv1 : ls)
    {
        cout << clrv1 << " ";
    }

    cout << endl;
    cout << "emplace_back list: ";
    for (auto clrv1 : ls)
    {
        cout << clrv1 << " ";
    }

    cout << endl;
    cout << "push_front list: ";
    for (auto clrv1 : ls)
    {
        cout << clrv1 << " ";
    }

    cout << endl;
    cout << "emplace_front list: ";
    for (auto clrv1 : ls)
    {
        cout << clrv1 << " ";
    }

    cout << endl;

    cout << "Size of the list: " << ls.size() << endl;
}

void explainSatck()
{
    stack<int> st;

    st.push(1);
    st.push(34);
    st.push(89);
    st.push(29);
    st.emplace(200);

    // fetch top stack element
    cout << "Stack top: " << st.top() << endl;

    // fetch size stack
    cout << "Stack Size: " << st.size() << endl;

    // check for the empty stack
    cout << "Stack Empty: " << st.empty() << endl;

    // Access Stack elements
    cout << "Stack elements st: ";
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }

    cout << endl;

    // stack<int> st1;

    // st1.push(23);
    // st1.push(56);
    // st1.push(66);
    // st1.emplace(567);

    // // Access Stack elements
    // cout << "Stack elements st1: ";
    // while (!st1.empty())
    // {
    //     cout << st1.top() << " ";
    //     st1.pop();
    // }

    cout << endl;

    // Swap the contents of st and st1
    stack<int> st1;
    stack<int> st2;

    st1.push(1);
    st1.push(34);
    st1.push(78);

    st2.push(10);
    st2.push(22);
    st2.push(89);

    cout << "Before Swap elements: " << endl;

    // Store elements in temporary containers for printing
    stack<int> tempSt1 = st1;
    stack<int> tempSt2 = st2;

    cout << "Stack elements st1: ";
    while (!tempSt1.empty())
    {
        cout << tempSt1.top() << " ";
        tempSt1.pop();
    }

    cout << endl;

    cout << "Stack elements st2: ";
    while (!tempSt2.empty())
    {
        cout << tempSt2.top() << " ";
        tempSt2.pop();
    }

    st1.swap(st2);
    cout << endl;

    cout << "After Swap elements: " << endl;
    cout << "Stack elements st1: ";
    while (!st1.empty())
    {
        cout << st1.top() << " ";
        st1.pop();
    }

    cout << endl;

    cout << "Stack elements st2: ";
    while (!st2.empty())
    {
        cout << st2.top() << " ";
        st2.pop();
    }
}

void explainDeque(){
    deque<int> dq;

    dq.push_back(99);
    dq.emplace_back(25);
    dq.push_front(67);
    dq.emplace_front(56);


    cout << "Deque elements dq: ";
    for (auto dqlp : dq)
    {
        cout << dqlp << " ";
    }

    cout << endl;

    dq.pop_back();
    dq.pop_front();

    cout << "Deque pop dq: ";
    for (auto dqlp : dq)
    {
        cout << dqlp << " ";
    }
        cout << endl;

    dq.front();
    dq.back();

    cout << "Deque front/back dq: ";
    for (auto dqlp : dq)
    {
        cout << dqlp << " ";
    }

// 34:30

}

int main()
{
    // cout << "Stl world" << endl;
    // print();
    // cout << endl;
    // cout << "Sum: " << sum(4, 8);
    // cout << endl;
    // explainPAir();
    // explainVectors();
    // explainList();
    // explainSatck();
    explainDeque();

    // 30:23

    return 0;
}