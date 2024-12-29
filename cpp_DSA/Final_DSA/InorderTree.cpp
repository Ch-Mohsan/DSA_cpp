#include <iostream>
#include <stack>
#include<queue>
#include "TreeNode.cpp"
using namespace std;

void inorder(TreeNode<int>* root) {
    if (root == NULL) {
        return;
    }
    stack<TreeNode<int>*> s;
    TreeNode<int>* curr = root;
    while (!s.empty() || curr != nullptr) {
        while (curr != nullptr) {
            s.push(curr);
            curr = curr->getLeft();
        }
        if (!s.empty()) {
            curr = s.top();
            s.pop();
            cout << curr->getInfo() << " ";
            curr = curr->getRight();
        }
    }
}

void preorder(TreeNode<int>*root){

 queue<TreeNode<int>*> q;
 q.push(root);
 while(!q.empty()){
    int curr=q.size();
    while(curr>0){
        TreeNode<int>*temp=q.front();
        q.pop();
        cout<<temp->getInfo()<<" ";
        if(temp->getLeft()!=nullptr){
            q.push(temp->getLeft());
        }
        if(temp->getRight()!=nullptr){
            q.push(temp->getRight());
        }
        curr--;
    }
 }
}

void postorder(TreeNode<int>* root) {
    if (root == nullptr) {
        return;
    }
    stack<TreeNode<int>*> s;
    TreeNode<int>* curr = root;
    TreeNode<int>* prevs = nullptr;

    while (!s.empty() || curr != nullptr) {
        if (curr != nullptr) {
            s.push(curr);
            curr = curr->getLeft();
        } else {
            TreeNode<int>* peekNode = s.top();

            // If the current node has a right child and it's not the last visited node,
            // move to the right subtree
            if (peekNode->getRight() != nullptr && prevs != peekNode->getRight()) {
                curr = peekNode->getRight();
            } else {
                // If the current node doesn't have a right child or it's the last visited node,
                // visit the current node
                cout << peekNode->getInfo() << " ";
                prevs = peekNode;
                s.pop();
            }
        }
    }
}
void insert(TreeNode<int>* root, int* info) {
    TreeNode<int>* node = new TreeNode<int>(info);
    TreeNode<int>* p, * q;
    p = q = root;
    while (*info != *(p->getInfo()) && q != NULL) {
        p = q;
        if (*info < *(p->getInfo()))
            q = p->getLeft();
        else
            q = p->getRight();
    }
    
    if (*info == *(p->getInfo())) {
        cout << "attempt to insert duplicate: " << *info << endl;
        delete node;
    }
    else if (*info < *(p->getInfo()))
        p->setLeft(node);
    else
        p->setRight(node);
}

int main(int argc, char *argv[]) {
    int x[] = { 14, 15, 4, 9, 7, 18, 3, 5, 16, 4, 20, 17, 9, 14, 5, -1 };
    TreeNode<int>* root = new TreeNode<int>();
    root->setInfo(&x[0]);
    for (int i = 1; x[i] > 0; i++) {
        insert(root, &x[i]);
    }
    
    cout << endl;
    inorder(root);
    cout << endl;
 preorder(root);  
 cout << endl;
 postorder(root); 
    return 0;
}