#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    // constructor like
    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

Node *newNode(int data)
{
    Node *node = new Node(data);
    return node;
}

// Binary Tree Representation

void create_tree(Node *root0, vector<int> &vec)
{
    root0->left = newNode(vec[1]);
    root0->right = newNode(vec[2]);

    root0->left->left = newNode(vec[3]);
    root0->left->right = newNode(vec[4]);

    root0->right->left = newNode(vec[5]);
    root0->right->right = newNode(vec[6]);
}

// maximum number of nodes
// 2^(i-1)Nodes

int countNodes(int i)
{
    int maxNodes = pow(2, (i - 1));
    return maxNodes;
}

// Traversals
// BFS and DFS
// BFS --> Level Order Traversal
// DFS
// -- Preorder(left -> root -> right)
// -- Inorder(left -> root -> right)
// --Postorder(left -> right -> root)

//  Recursion Binary Tree Preorder Traversal
vector<int> preorderTraversal(Node *root)
{
    vector<int> preOrderdata;

    if (root == NULL)
    {
        return preOrderdata;
    }

    preOrderdata.push_back(root->data);

    vector<int> leftSideData = preorderTraversal(root->left);
    preOrderdata.insert(preOrderdata.end(), leftSideData.begin(), leftSideData.end());

    vector<int> RightSideData = preorderTraversal(root->right);
    preOrderdata.insert(preOrderdata.end(), RightSideData.begin(), RightSideData.end());

    return preOrderdata;
}

// Recursion Binary Tree Inorder Traversal
vector<int> inorderTraversalRecursive(Node *root)
{
    vector<int> inOrderData;

    if (root == NULL)
    {
        return inOrderData;
    }

    vector<int> leftSideData = inorderTraversalRecursive(root->left);
    inOrderData.insert(inOrderData.end(), leftSideData.begin(), leftSideData.end());

    inOrderData.push_back(root->data);

    vector<int> RightSideData = inorderTraversalRecursive(root->right);
    inOrderData.insert(inOrderData.end(), RightSideData.begin(), RightSideData.end());

    return inOrderData;
}

// Recursion Binary Tree Postorder Traversal
vector<int> postorderTraversalRecursive(Node *root)
{
    vector<int> postOrderData;

    if (root == NULL)
    {
        return postOrderData;
    }

    vector<int> leftSideData = postorderTraversalRecursive(root->left);
    postOrderData.insert(postOrderData.end(), leftSideData.begin(), leftSideData.end());

    vector<int> RightSideData = postorderTraversalRecursive(root->right);
    postOrderData.insert(postOrderData.end(), RightSideData.begin(), RightSideData.end());

    postOrderData.push_back(root->data);

    return postOrderData;
}

// Binary Tree Level Order Traversal

vector<vector<int>> levelOrder(Node *root)
{
    vector<vector<int>> levelOrderData;

    if (root == NULL)
    {
        return levelOrderData;
    }

    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        int size = q.size();

        vector<int> Currlevel;

        for (int i = 0; i < size; i++)
        {
            Node *CurrNode = q.front();
            q.pop();
            Currlevel.push_back(CurrNode->data);

            if (CurrNode->left != NULL)
            {
                q.push(CurrNode->left);
            }

            if (CurrNode->right != NULL)
            {
                q.push(CurrNode->right);
            }
        }
        levelOrderData.push_back(Currlevel);
    }
    return levelOrderData;
}

//  Iterative Binary Tree Preorder Traversal
// stack --> right, left
vector<int> preorderTraversalIterative(Node *root)
{
    vector<int> preOrderData;

    if (root == NULL)
    {
        return preOrderData;
    }

    stack<Node *> st;
    st.push(root);

    while (!st.empty())
    {
        root = st.top();
        st.pop();
        preOrderData.push_back(root->data);

        if (root->right != NULL)
        {
            st.push(root->right);
        }

        if (root->left != NULL)
        {
            st.push(root->left);
        }
    }
    return preOrderData;
}

//  Iterative Binary Tree Inorder Traversal
vector<int> inorderTraversalIterative(Node *root)
{
    stack<Node *> st;
    vector<int> inOrderData;
    Node *curNode = root;

    if (root == NULL)
    {
        return inOrderData;
    }

    while (!st.empty())
    {
        if (curNode != NULL)
        {
            st.push(curNode);
            curNode = curNode->left;
        }
        else
        {
            if (st.empty())
            {
                break;
            }
            curNode = st.top();
            st.pop();
            inOrderData.push_back(curNode->data);
            curNode = curNode->right;
        }
    }
    return inOrderData;
}

//  Iterative Binary Tree Postorder Traversal --> using 2 stacks
vector<int> postorderTraversalIterativeTwoStacks(Node *root)
{
    stack<Node *> st1;
    stack<Node *> st2;
    vector<int> PostOrderData;
    Node *curNode = root;

    if (root == NULL)
    {
        return PostOrderData;
    }

    st1.push(root);

    while (!st1.empty())
    {
        root = st1.top();
        st1.pop();

        st2.push(root);

        if (root->left != NULL)
        {
            st1.push(root->left);
        }

        if (root->right != NULL)
        {
            st1.push(root->right);
        }
    }

    while (!st2.empty())
    {
        PostOrderData.push_back(st2.top()->data);
        st2.pop();
    }
    return PostOrderData;
}

//  Iterative Binary Tree Postorder Traversal --> using 1 stack
vector<int> postorderTraversalIterativeOneStack(Node *root)
{
}

// Preorder Inorder Postorder Traversals in One Traversal
vector<int> AllTraservalOrder(Node *root)
{
    stack<pair<Node *, int>> st;
    st.push({root, 1});
    vector<int> preOrderData, inOrderData, postOrderData;

    if (root == NULL)
    {
        return preOrderData, inOrderData, postOrderData;
    }

    while (!st.empty())
    {
        auto it = st.top();
        st.pop();

        if (it.second == 1)
        {
            preOrderData.push_back(it.first->data);
            it.second++;
            st.push(it);

            if (it.first->left != NULL)
            {
                st.push({it.first->left, 1});
            }
        }
        else if (it.second == 2)
        {
            inOrderData.push_back(it.first->data);
            it.second++;
            st.push(it);

            if (it.first->right != NULL)
            {
                st.push({it.first->right, 1});
            }
        }
        else
        {
            postOrderData.push_back(it.first->data);
        }
    }
    return preOrderData, inOrderData, postOrderData;
}

int main()
{
    struct Node *root = new Node(1);
    // root->left = new Node(2);
    // root->right = new Node(3);
    // root->left->right = new Node(4);
    // root->left->left = new Node(5);

    // Print tree in level-order fashion
    // cout << "     " << root->data << endl; // Level 1
    // cout << "    /  \\" << endl;
    // cout << "   " << root->left->data << "    " << root->right->data << endl; // Level 2
    // cout << "  / \\" << endl;
    // cout << " " << root->left->left->data << "   " << root->left->right->data << endl; // Level 3

    // vector<int> vec = {1, 2, 3, 4, 5, 6, 7};
    // Node *root0 = newNode(vec[0]);
    // create_tree(root0, vec);

    // cout << "       " << root0->data << endl; // Level 1
    // cout << "     /   \\" << endl;
    // cout << "    " << root0->left->data << "     " << root0->right->data << endl; // Level 2
    // cout << "   / \\   / \\" << endl;
    // cout << "  " << root0->left->left->data << "   " << root0->left->right->data << " " << root0->right->left->data << "   " << root0->right->right->data << endl; // Level 3

    // cout << "Maximum number of nodes in a binary tree of height: " << countNodes(5) << endl;

    // vector<int> vec = {1, 2, 3, 4, 5, nullptr, 8, nullptr, nullptr, 6, 7, 9};

    // vector<int> preOrderdata = preorderTraversal(root);
    // for (int i = 0; i < preOrderdata.size(); i++)
    // {
    //     cout << preOrderdata[i] << " ";
    // }

    return 0;
}