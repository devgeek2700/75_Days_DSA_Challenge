// LFU Cache --> least frequently used 
class LFUCache { // TC -->O(1)
private:
    int capacity, minFreq;
    unordered_map<int, int> keyToVal;
    unordered_map<int, int> keyToFreq;
    unordered_map<int, list<int>> freqToList;
    unordered_map<int, list<int>::iterator> keyToIter;

    void updateFrequency(int key) {
        int freq = keyToFreq[key];
        keyToFreq[key] = freq + 1;

        freqToList[freq].erase(keyToIter[key]);
        if (freqToList[freq].empty()) {
            freqToList.erase(freq);
            if (minFreq == freq) {
                minFreq++;
            }
        }

        freqToList[freq + 1].push_back(key);
        keyToIter[key] = --freqToList[freq + 1].end();
    }

public:
    LFUCache(int capacity) {
        this->capacity = capacity;
        minFreq = 0;
    }

    int get(int key) {
        if (keyToVal.find(key) == keyToVal.end()) {
            return -1;
        }
        updateFrequency(key);
        return keyToVal[key];
    }

    void put(int key, int value) {
        if (capacity <= 0) {
            return;
        }

        if (keyToVal.find(key) != keyToVal.end()) {
            keyToVal[key] = value;
            updateFrequency(key);
            return;
        }

        if (keyToVal.size() >= capacity) {
            int evictKey = freqToList[minFreq].front();
            freqToList[minFreq].pop_front();
            if (freqToList[minFreq].empty()) {
                freqToList.erase(minFreq);
            }

            keyToVal.erase(evictKey);
            keyToFreq.erase(evictKey);
            keyToIter.erase(evictKey);
        }

        keyToVal[key] = value;
        keyToFreq[key] = 1;
        minFreq = 1;
        freqToList[1].push_back(key);
        keyToIter[key] = --freqToList[1].end();
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

    vector<int> varr = {4, 2, 3, 3, 6};
    // vector<vector<int>> matrix = {{0, 0, 1, 0}, {0, 0, 1, 0}, {0, 0, 0, 0}, {0, 0, 1, 0}};

    // string str = "10200";
    int k = 3;
    int n = 4;

    // cout << "string is: " << str << endl;

    cout << "Display N: " << n << endl;
    // cout << "Display Element: ";
    // for (int i = 0; i < varr.size(); i++)
    // {
    //     cout << varr[i] << " ";
    // }
    // cout << endl;

    // cout << "Display matrix: " << endl;
    // for (int i = 0; i < matrix.size(); i++)
    // {
    //     for (int j = 0; j < matrix[0].size(); j++)
    //     {
    //         cout << matrix[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // cout << endl;

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

    // int resmin = sumSubarrayMins(varr);
    // cout << "Sum of Subarray Minimums: " << resmin << endl;

    // int resmax = sumSubarrayMaxs(varr);
    // cout << "Sum of Subarray Maximum: " << resmax << endl;

    // int ans = minimumSum(varr, varr.size());
    // cout << " Minimum Sum Subarray: " << ans << endl;

    // cout << "Asteroid Collision: ";
    // vector<int> collidingAsteroidsans = collidingAsteroids(varr);
    // for (int i = 0; i < collidingAsteroidsans.size(); i++)
    // {
    //     cout << collidingAsteroidsans[i] << " ";
    // }
    // cout << endl;

    // int rangeSumans = rangeSum(varr);
    // cout << "Subarray Range Sum: " << rangeSumans << endl;

    // string removeKDigitsAns = removeKDigits(str, k);
    // cout << "Remove K Digits: " << removeKDigitsAns << endl;

    // int largestRectangleAns = largestRectangle(varr);
    // cout << "Largest rectangle in a histogram: " << largestRectangleAns << endl;

    // int maximalRectangleAns = maximalRectangle(matrix);
    // cout << "Maximal Rectangle: " << maximalRectangleAns << endl;

    // cout << "Maximum In Sliding Windows Of Size K: ";
    // vector<int> slidingWindowMaximumAns = slidingWindowMaximum(varr, k);
    // for (int i = 0; i < slidingWindowMaximumAns.size(); i++)
    // {
    //     cout << slidingWindowMaximumAns[i] << " ";
    // }
    // cout << endl;

    // cout << "Online Stock Span: ";
    // vector<int> findSpansAns = findSpans(varr);
    // for (int i = 0; i < findSpansAns.size(); i++)
    // {
    //     cout << findSpansAns[i] << " ";
    // }
    // cout << endl;

    // int findCelebrityAns = findCelebrity(n);
    // cout << "The Celebrity Problem: " << findCelebrityAns << endl;

    //  LRU Cache Implementation

    // LRUCache cache(3);
    // cout << "LRU Cache Implementation:" << endl;
    // cache.put(1, 1);
    // cache.put(2, 56);
    // cache.put(3, 89);
    // cout << "cache at 2: " << cache.get(2) << endl; // returns 2
    // cache.put(4, 49);
    // cout << "cache at 1: " << cache.get(1) << endl;  // returns -1 (1 was removed)
    // cout << "cache at 3: " << cache.get(3) << endl;  // returns 3
    // cout << "cache at 24: " << cache.get(4) << endl; // returns 4

    LFUCache cache(3);
    cout << "LFU Cache Implementation:" << endl;
    cache.put(1, 1);
    cache.put(2, 56);
    cache.put(3, 89);
    cout << "cache at 2: " << cache.get(2) << endl; // returns 56
    cache.put(4, 49);
    cout << "cache at 1: " << cache.get(1) << endl;  // returns -1 (1 was removed)
    cout << "cache at 3: " << cache.get(3) << endl;  // returns 89
    cout << "cache at 4: " << cache.get(4) << endl; // returns 49


    return 0;
}