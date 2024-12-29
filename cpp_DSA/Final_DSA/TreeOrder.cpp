#include <iostream>
#include "TreeNode.cpp"
using namespace std;

void preorder(TreeNode<int>* treeNode)
{
    if (treeNode != nullptr)
    {
        cout << *(treeNode->getInfo()) << " ";
        preorder(treeNode->getLeft());
        preorder(treeNode->getRight());
    }
}

void inorder(TreeNode<int>* treeNode)
{
    if (treeNode != nullptr)
    {
        inorder(treeNode->getLeft());
        cout << *(treeNode->getInfo()) << " ";
        inorder(treeNode->getRight());
    }
}

void postorder(TreeNode<int>* treeNode)
{
    if (treeNode != nullptr)
    {
        postorder(treeNode->getLeft());
        postorder(treeNode->getRight());
        cout << *(treeNode->getInfo()) << " ";
    }
}

int main() {
    int data1 = 1, data2 = 2, data3 = 3, data4 = 4, data5 = 5, data6 = 6, data7 = 7;
    TreeNode<int>* root = new TreeNode<int>(&data1);
    root->setLeft(new TreeNode<int>(&data2));
    root->setRight(new TreeNode<int>(&data3));
    root->getLeft()->setLeft(new TreeNode<int>(&data4));
    root->getLeft()->setRight(new TreeNode<int>(&data5));
    root->getRight()->setLeft(new TreeNode<int>(&data6));
    root->getRight()->setRight(new TreeNode<int>(&data7));

    cout << "preorder" << endl;
    preorder(root);
    cout << endl << "inorder" << endl;
    inorder(root);
    cout << endl << "postorder" << endl;
    postorder(root);

    return 0;
}
