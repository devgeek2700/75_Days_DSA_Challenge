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

void explainDeque()
{
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
}

void explainQueue()
{
    queue<int> q;

    // Insert
    q.push(22);
    q.push(67);
    q.push(99);
    q.emplace(233);

    // Access
    cout << "queue: ";
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;

    // Operations
    q.push(272);
    q.push(667);
    q.push(900);

    q.back() += 10;

    cout << "Queue back: " << q.back() << endl;
    cout << "Queue front: " << q.front() << endl;

    // Delete
    q.pop();
    cout << "Queue front: " << q.front() << endl;

    // Access
    cout << "queue after pop: ";
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}

void explainPriorityQueue()
{
    priority_queue<int> pq;

    // Insert
    pq.push(35);
    pq.push(47);
    pq.push(18);
    pq.emplace(2);

    cout << "priority_queue top: " << pq.top() << endl;

    cout << "priority queue: ";
    while (!pq.empty())
    {
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl;

    pq.push(345);
    pq.push(479);
    pq.push(180);
    pq.emplace(21);

    // Size

    cout << "Size: " << pq.size() << endl;

    // Delete
    pq.pop();

    cout << "priority queue after pop: ";
    while (!pq.empty())
    {
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl;

    // Set Minimum number priority

    priority_queue<int, vector<int>, greater<int>> minpq;

    minpq.push(257);
    minpq.push(4);
    minpq.push(890);
    minpq.push(7);
    minpq.emplace(1000);

    cout << endl;
    // top

    cout << "priority queue Minimum number priority top: " << minpq.top() << endl;
    ;

    cout << "priority queue Minimum number priority: ";
    while (!minpq.empty())
    {
        cout << minpq.top() << " ";
        minpq.pop();
    }
    cout << endl;
}

void explainSet()
{
    set<int> st;

    // Insert
    st.insert(12);
    st.insert(182);
    st.insert(2);
    st.insert(724);
    st.emplace(724);
    st.emplace(100);

    cout << "set: ";
    for (auto setlp : st)
    {
        cout << setlp << " ";
    }
    cout << endl;

    // Find

    auto it = st.find(20);
    cout << "Find 2 by index: " << *it << endl;

    // Erase
    st.erase(12);

    cout << "set after Erase: ";
    for (auto setlp : st)
    {
        cout << setlp << " ";
    }
    cout << endl;

    // Count
    int cnt = st.count(724);
    cout << "Count of 724 is: " << cnt << endl;

    auto itf = st.find(100);
    st.erase(itf);

    cout << "set after erase final: ";
    for (auto setlp : st)
    {
        cout << setlp << " ";
    }
    cout << endl;

    set<int> st1;

    // Insert
    st1.insert(1);
    st1.insert(222);
    st1.insert(2);
    st1.insert(724);
    st1.emplace(3);
    st1.emplace(143);

    // erase between elements
    auto it1 = st1.find(222);
    auto it2 = st1.find(3);
    st1.erase(it1, it2);

    cout << "Erase Between range: ";
    for (auto setlp : st1)
    {
        cout << setlp << " ";
    }
    cout << endl;

    set<int> st3;

    // Insert
    st3.insert(1);
    st3.insert(2);
    st3.emplace(3);
    st3.insert(4);

    cout << endl;

    // lower and upper bound
    auto itl = st3.lower_bound(4);
    auto itu = st3.upper_bound(2);
    // auto itus = st3.upper_bound(4);
    cout << "Lower Bound: " << *(itl) << endl;
    cout << "Upper Bound: " << *(itu) << endl;
    // cout << "Upper Bound itus: " << *(itus) << endl;
}

void explainMultiSet()
{
    multiset<int> ms;
    ms.insert(10);
    ms.insert(50);
    ms.insert(50);
    ms.insert(50);
    ms.insert(60);
    ms.insert(60);
    ms.emplace(70);
    ms.emplace(80);
    ms.emplace(90);

    // Access

    cout << "Multiset: ";
    for (auto mslp : ms)
    {
        cout << mslp << " ";
    }
    cout << endl;

    // Count
    int cnt = ms.count(50);
    cout << "Count of 50 is: " << cnt << endl;

    // Erase
    // All
    ms.erase(50);

    cout << "Multiset after earse all: ";
    for (auto mslp : ms)
    {
        cout << mslp << " ";
    }
    cout << endl;

    // Single
    ms.erase(ms.find(60));

    cout << "Multiset after earse single: ";
    for (auto mslp : ms)
    {
        cout << mslp << " ";
    }
    cout << endl;

    // Range of occurrences
    ms.erase(ms.lower_bound(60), ms.upper_bound(80)); // Use lower_bound and upper_bound
    cout << "Multiset after erasing occurrences between 60: ";
    for (auto mslp : ms)
    {
        cout << mslp << " ";
    }
}

void explainUnorderedSet()
{
    unordered_set<int> os;

    os.insert(10);
    os.insert(60);
    os.emplace(70);

    os.insert(60);
    os.emplace(90);

    cout << "unordered_set: ";
    for (auto oslp : os)
    {
        cout << oslp << " ";
    }
    cout << endl;
}

void explainMap()
{
    map<int, int> map;
    // map<int, pair<int, int> mapp;
    // map<pair<int, int> , int> pmap;
    // map<string, int> charmap;

    map[1] = 10;
    map[2] = 20;
    map.insert({3, 30});
    map.insert({4, 40});
    map.emplace(5, 50);

    cout << "Map: ";
    for (auto it : map)
    {
        cout << it.first << " : " << it.second << endl;
    }
    cout << endl;

    auto it = map.find(40);
    if (it != map.end())
    {
        cout << "it->second: " << it->second << endl;
    }
    else
    {
        cout << "Key not found in the map." << endl;
    }

    // lower and upper bound
    auto itlm = map.lower_bound(4);
    cout << "Lower Bound map: " << itlm->first << " : " << itlm->second << endl;

    auto itum = map.upper_bound(4);
    cout << "Upper Bound map: " << itum->first << " : " << itum->second << endl;
}

void explainMultiMap()
{
    multimap<int, int> mulmap;

    mulmap.insert({1, 67});
    mulmap.insert({3, 987});
    mulmap.insert({1, 89});
    mulmap.insert({2, 189});

    // Printing the multimap
    cout << "Multimap: ";
    for (const auto &it : mulmap)
    {
        cout << it.first << " : " << it.second << " " << endl;
    }
}

void explainUnorderedMap()
{
    unordered_map<int, int> umap;
    umap[4] = 123;
    umap[3] = 88;
    umap[2] = 78;
    umap[1] = 33;

    // Printing the unordered_map
    cout << "Unordered Map: ";
    for (const auto &it : umap)
    {
        cout << it.first << " : " << it.second << " " << endl;
    }
}

bool comp(pair<int, int> p1, pair<int, int> p2)
{
    if (p1.second < p2.second)
    {
        return true;
    }

    if (p1.second > p2.second)
    {
        return false;
    }

    // If second elements are the same, sort by first element in descending order
    return p1.first > p2.first;
}

void explainAlogrithms()
{
    // int a[] = {8, 2, 6, 1, 7, 4, 3, 5};
    int a[] = {1, 55, 89, 67, 99, 2, 778, 33};
    vector<int> v;
    v.push_back(12);
    v.push_back(56);
    v.push_back(669);
    v.push_back(2);

    int n = sizeof(a) / sizeof(a[0]);

    // sort(a, a+n);
    // sort(a+2, a+4);
    sort(a, a + n, greater<int>());
    sort(v.begin(), v.end());

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;

    cout << "Sorted Vector: ";
    for (auto oslp : v)
    {
        cout << oslp << " ";
    }
    cout << endl;

    pair<int, int> parr[] = {{5, 6}, {3, 4}, {7, 8}, {1, 2}};

    cout << "Before sorting: ";
    for (const auto &p : parr)
    {
        cout << "(" << p.first << ", " << p.second << ") ";
    }
    cout << endl;

    sort(begin(parr), end(parr), comp); // Use begin() and end() functions for arrays

    cout << "After sorting: ";
    for (const auto &p : parr)
    {
        cout << "(" << p.first << ", " << p.second << ") ";
    }
    cout << endl;

    int num = 3;
    int cnt = __builtin_popcount(num);
    cout << "Number of set bits in " << num << ": " << cnt << endl;

    long long num1 = 726784795847968;
    int cnt1 = __builtin_popcountll(num1);
    cout << "Number of set bits in " << num1 << ": " << cnt1 << endl;

    string s = "123";
    do
    {
        cout <<"Permutation string: "<< s << endl;
    } while (next_permutation(s.begin(), s.end()));


    int max = *max_element(a, a+n);
    cout << "Max in array: " << a << ": " << max << endl;

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
    // explainDeque();
    // explainQueue();
    // explainPriorityQueue();
    // explainSet();
    // explainMultiSet();
    // explainUnorderedSet();
    // explainMap();
    // explainMultiMap();
    // explainUnorderedMap();
    explainAlogrithms();

    return 0;
}