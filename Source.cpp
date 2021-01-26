#include <iostream>

using namespace std;



struct Node
{
    int i;
    Node* pLeft;
    Node* pRight;

    Node(int iIn) : i(iIn), pLeft(nullptr), pRight(nullptr) {}
};

void printArray(int ints[], int len);
int theTotalSize = 0;
bool finishedCounter = false;



void printPathsRecur(Node* node, int path[], int pathLen)
{
    if (node == NULL)
        return;

    /* append this node to the path array */
    path[pathLen] = node->i;
    pathLen++;

    /* it's a leaf, so print the path that led to here */
    if (node->pLeft == NULL && node->pRight == NULL)
    {
        if (finishedCounter == false)
        {
            printArray(path, pathLen);
        }
    }
    else
    {
        /* otherwise try both subtrees */
        printPathsRecur(node->pLeft, path, pathLen);
        printPathsRecur(node->pRight, path, pathLen);
    }
}

void printArray(int ints[], int len)
{
    int i;
    int theCounter = 0;


    if (finishedCounter == false)
    {
        for (i = 0; i < len; i++)
        {
            theCounter += ints[i];
            cout << ints[i] << " ";
            if (theCounter == theTotalSize)
            {
                finishedCounter = true;
            }

        }
    }
}


int rootToLeafSum(Node* root)
{
    if (root == nullptr) {

        return 0;

    }

    int left = rootToLeafSum(root->pLeft);

    int right = rootToLeafSum(root->pRight);


    return (left > right ? left : right) + root->i;
}

void main()
{
    Node* sortedArrayRootPointer = nullptr;



    theTotalSize = rootToLeafSum(sortedArrayRootPointer);

    int path[1000];

    cout << "Branch with the largest sum is: ";

    printPathsRecur(sortedArrayRootPointer, path, 0);

    cout << "-> SUM = " << theTotalSize << endl;

}