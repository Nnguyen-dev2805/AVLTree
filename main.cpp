/*
    MSSV:23110273
    Name: Truong Nhat Nguyen
*/

// Main File
#include <iostream>
#include "AVLTree.h"
using namespace std;

void Menu()
{
    cout << "--------------------------------" << endl;
    cout << "Operations on AVL Tree" << endl;
    cout << "--------------------------------" << endl;
    cout << "1.Check Tree Empty" << endl;
    cout << "2.Insert new node to the Tree" << endl;
    cout << "3.Delete node in the Tree" << endl;
    cout << "4.Search node in the Tree" << endl;
    cout << "5.Print Tree with PreOder Method" << endl;
    cout << "6.Print Tree with InOder Method" << endl;
    cout << "7.Print Tree with PostOder Method" << endl;
    cout << "8.Height of Tree" << endl;
    cout << "9.Count Node Branch in Tree" << endl;
    cout << "10.Count Node Leaf in Tree" << endl;
    cout << "11.Count Node with value even in Tree" << endl;
    cout << "12.The sum of value node in Tree" << endl;
    cout << "13.Max value node and Min value node in Tree" << endl;
    cout << "14.Max negative node in Tree" << endl;
    cout << "15.Count different value node in Tree" << endl;
    cout << "16.Frequency node in Tree" << endl;
    cout << "0.Exit" << endl;
}
int main()
{
    AVLTree<int> tree;
    int ok, choice;
    Menu();
    do
    {
        cout << "Which option do you want to choice?" << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            if (tree.isEmptyTree())
            {
                cout << "Tree is Empty" << endl;
            }
            else
            {
                cout << "Tree is no Empty" << endl;
            }
            break;
        }
        case 2:
        {
            int n;
            cout << "Enter value node you want to insert: ";
            cin >> n;
            tree.insert(n);
            break;
        }
        case 3:
        {
            int n;
            cout << "Enter value node you want to delete: ";
            cin >> n;
            tree.remove(n);
            break;
        }
        case 4:
        {
            int n;
            cout << "Enter value node you want to search: ";
            cin >> n;
            cout << (tree.search(n) ? "Found" : "Not found") << endl;
            break;
        }
        case 5:
        {
            tree.preOrder();
            break;
        }
        case 6:
        {
            tree.inOrder();
            break;
        }
        case 7:
        {
            tree.postOrder();
            break;
        }
        case 8:
        {
            cout << "Height Tree: " << tree.HighTree() << endl;
            break;
        }
        case 9:
        {
            cout << "Branch in Tree: " << tree.countBranch() << endl;
            break;
        }
        case 10:
        {
            cout << "Leaf Node in Tree: " << tree.countLeaf() << endl;
            break;
        }
        case 11:
        {
            cout << "Number of Node with value even: " << tree.countEvenNode() << endl;
            break;
        }
        case 12:
        {
            cout << "Sum of node in Tree: " << tree.SumOfTree() << endl;
            break;
        }
        case 13:
        {
            if (tree.findMax() == INT_MIN)
            {
                cout << "Tree is Empty" << endl;
            }
            else
            {
                cout << "Max value node in Tree: " << tree.findMax() << endl;
                cout << "Min value node in Tree: " << tree.findMin() << endl;
            }
            break;
        }
        case 14:
        {
            if (tree.MaxNegative() == INT_MIN)
            {
                cout << "Tree is Empty" << endl;
            }
            else
            {
                cout << "Max value negative node in Tree: " << tree.MaxNegative() << endl;
            }
            break;
        }
        case 15:
        {
            cout << "Number of distinct values in the Tree: " << tree.countNode() << endl;
            break;
        }
        case 16:
        {
            tree.freqNode();
            break;
        }
        }
        cout << "Do you want to continue? 1:Yes 0:No" << endl;
        cin >> ok;
    } while (ok != 0);
}