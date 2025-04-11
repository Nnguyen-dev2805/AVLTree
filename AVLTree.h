/*
    MSSV:23110273
    Name: Truong Nhat Nguyen
*/

// Header File
#pragma once
#include <bits/stdc++.h>
using namespace std;

template <typename T>
class AVLTree
{
private:
    struct Node
    {
        T data;
        int height;
        Node *left, *right;
        Node(T value)
        {
            data = value;
            height = 1;
            left = right = nullptr;
        }
    };

    Node *root;

    // Get height of node
    int getHeight(Node *node)
    {
        return node ? node->height : 0;
    }

    // Update height of node
    void updateHeight(Node *node)
    {
        if (node)
        {
            node->height = 1 + max(getHeight(node->left), getHeight(node->right));
        }
    }

    // Balance Factor
    int getBalanceFactor(Node *node)
    {
        return node ? getHeight(node->left) - getHeight(node->right) : 0;
    }

    // Rotate Right
    Node *rotateRight(Node *node)
    {
        Node *newRoot = node->left;
        Node *cur = newRoot->right;
        newRoot->right = node;
        node->left = cur;

        updateHeight(node);
        updateHeight(newRoot);

        return newRoot;
    }

    // Rotate Left
    Node *rotateLeft(Node *node)
    {
        Node *newRoot = node->right;
        Node *cur = newRoot->left;
        newRoot->left = node;
        node->right = cur;

        updateHeight(node);
        updateHeight(newRoot);

        return newRoot;
    }

    // Insert newNode
    Node *insert(Node *node, T value)
    {
        // if AVL Tree is empty
        if (!node)
        {
            return new Node(value);
        }

        // if AVL Tree is not empty
        if (value < node->data)
        {
            node->left = insert(node->left, value);
        }
        else if (value > node->data)
        {
            node->right = insert(node->right, value);
        }
        else
        {
            // Equal keys are not allowed in AVL
            return node;
        }

        updateHeight(node);

        // Calculate balance with defference between left and right hand sides
        int balance = getBalanceFactor(node);

        // Left Left Case
        if (balance > 1 && value < node->left->data)
        {
            return rotateRight(node);
        }

        // Right Right Case
        if (balance < -1 && value > node->right->data)
        {
            return rotateLeft(node);
        }

        // Left Right Case
        if (balance > 1 && value > node->left->data)
        {
            node->left = rotateLeft(node->left);
            return rotateRight(node);
        }

        // Right Left Case
        if (balance < -1 && value < node->right->data)
        {
            node->right = rotateRight(node->right);
            return rotateLeft(node);
        }
        return node;
    }

    // Min value node in right subtree
    Node *minValueNode(Node *node)
    {
        Node *current = node;
        while (current->right != nullptr)
        {
            current = current->left;
        }
        return current;
    }

    // delete Node
    Node *deleteNode(Node *node, T value)
    {

        // if AVL Tree is empty
        if (node == nullptr)
        {
            return node;
        }

        // if AVL Tree is not empty
        if (value < node->data)
        {
            node->left = deleteNode(node->left, value);
        }
        else if (value > node->data)
        {
            node->right = deleteNode(node->right, value);
        }
        // After finding the value
        else
        {
            // node with only one child or no child
            if (node->left == nullptr || node->right == nullptr)
            {
                Node *cur = node->left ? node->left : node->right;

                // No child case
                if (cur == nullptr)
                {
                    cur = node;
                    node = nullptr;
                }
                // One child case
                else
                {
                    *node = *cur;
                }
                free(cur); // Free memory
            }
            // node with two child
            else
            {
                Node *cur = minValueNode(node->right);
                node->data = cur->data;
                // Delete the inorder successor
                node->right = deleteNode(node->right, cur->data);
            }
        }
        // If the tree had only one node then return
        if (node == nullptr)
        {
            return node;
        }

        updateHeight(node);

        // Calculate balance with defference between left and right hand sides
        int balance = getBalanceFactor(node);

        // Left Left Case
        if (balance > 1 && value < node->left->data)
        {
            return rotateRight(node);
        }

        // Right Right Case
        if (balance < -1 && value > node->right->data)
        {
            return rotateLeft(node);
        }

        // Left Right Case
        if (balance > 1 && value > node->left->data)
        {
            node->left = rotateLeft(node->left);
            return rotateRight(node);
        }

        // Right Left Case
        if (balance < -1 && value < node->right->data)
        {
            node->right = rotateRight(node->right);
            return rotateLeft(node);
        }
        return node;
    }

    // Search Node
    Node *searchUtil(Node *node, T value)
    {
        Node *cur = node;
        while (cur != nullptr)
        {
            if (cur->data == value)
                return cur;
            else if (cur->data < value)
                cur = cur->right;
            else
                cur = cur->left;
        }
        return nullptr;
    }

    // Get Heigt Tree
    int heightTree(Node *node)
    {
        if (node == nullptr)
            return 0;
        int h1 = heightTree(node->right);
        int h2 = heightTree(node->left);
        return 1 + max(h1, h2);
    }

    // Count Node Brand : Node have one child
    int countBranchTree(Node *node)
    {
        if (node == nullptr)
            return 0;
        int cnt1 = countBranchTree(node->right);
        int cnt2 = countBranchTree(node->left);
        if (node->right != nullptr || node->left != nullptr)
        {
            return 1 + cnt1 + cnt2;
        }
        return cnt1 + cnt2;
    }

    // Count Node Leaf : Node have no child
    int countLeafNode(Node *node)
    {
        if (node == nullptr)
            return 0;
        if (node->right == nullptr && node->left == nullptr)
        {
            return 1;
        }
        return countLeafNode(node->right) + countLeafNode(node->left);
    }

    // Count node have value even
    int countEven(Node *node)
    {
        if (node == nullptr)
            return 0;
        int count = (node->data % 2 == 0);
        return count + countEven(node->left) + countEven(node->right);
    }

    // Sum of node in Tree
    T sumTree(Node *node)
    {
        if (node == nullptr)
            return 0;
        return node->data + sumTree(node->left) + sumTree(node->right);
    }

    // Max value node in Tree
    T maxNode(Node *node)
    {
        if (node == nullptr)
        {
            return numeric_limits<T>::min();
        }
        while (node->right != nullptr)
        {
            node = node->right;
        }
        return node->data;
    }

    // Min value node in Tree
    T minNode(Node *node)
    {
        if (node == nullptr)
        {
            return numeric_limits<T>::max();
        }
        while (node->left != nullptr)
        {
            node = node->left;
        }
        return node->data;
    }

    // Max negative value node in Tree
    T findMaxNegative(Node *node)
    {
        if (node == nullptr)
            return numeric_limits<T>::min();
        T maxNeg = (node->data < 0) ? node->data : numeric_limits<T>::min();
        T maxLeft = findMaxNegative(node->left);
        T maxRight = findMaxNegative(node->right);
        return max({maxNeg, maxLeft, maxRight});
    }

    // Count different node in Tree
    void countElement(Node *node, set<T> &st)
    {
        if (node == nullptr)
            return;
        st.insert(node->data);
        countElement(node->left, st);
        countElement(node->right, st);
    }

    // Frequency node in Tree
    void freqElement(Node *node, map<T, int> &mp)
    {
        if (node == nullptr)
            return;
        mp[node->data]++;
        freqElement(node->left, mp);
        freqElement(node->right, mp);
    }

    // Display Pre Order Method
    void preOrder(Node *node)
    {
        if (node)
        {
            cout << node->data << " ";
            preOrder(node->left);
            preOrder(node->right);
        }
    }

    // Display In Order Method
    void inOrder(Node *node)
    {
        if (node)
        {
            preOrder(node->left);
            cout << node->data << " ";
            preOrder(node->right);
        }
    }

    // Display Post Order Method
    void postOrder(Node *node)
    {
        if (node)
        {
            preOrder(node->left);
            preOrder(node->right);
            cout << node->data << " ";
        }
    }

public:
    AVLTree()
    {
        root = nullptr;
    }
    
    bool isEmptyTree()
    {
        return root == nullptr;
    }

    void insert(T value)
    {
        root = insert(root, value);
    }

    void remove(T value)
    {
        root = deleteNode(root, value);
    }

    bool search(T value)
    {
        return searchUtil(root, value) != nullptr;
    }

    int HighTree()
    {
        return heightTree(root);
    }

    int countBranch()
    {
        return countBranchTree(root);
    }

    int countLeaf()
    {
        return countLeafNode(root);
    }

    int countEvenNode()
    {
        return countEven(root);
    }

    T SumOfTree()
    {
        return sumTree(root);
    }

    T findMax()
    {
        return maxNode(root);
    }

    T findMin()
    {
        return minNode(root);
    }

    T MaxNegative()
    {
        return findMaxNegative(root);
    }

    int countNode()
    {
        set<T> st;
        countElement(root, st);
        return st.size();
    }

    void freqNode()
    {
        map<T, int> mp;
        freqElement(root, mp);
        cout << "Frequency of distinct values in the tree: " << endl;
        for (auto x : mp)
        {
            cout << x.first << ": " << x.second << endl;
        }
    }

    void preOrder()
    {
        preOrder(root);
        cout << endl;
    }

    void inOrder()
    {
        inOrder(root);
        cout << endl;
    }

    void postOrder()
    {
        preOrder(root);
        cout << endl;
    }
};