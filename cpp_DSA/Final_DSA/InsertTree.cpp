#include <iostream>
#include "Tnode.cpp"
using namespace std;

void insert(TreeNode<int>* root, int* info) {
    TreeNode<int>* node = new TreeNode<int>(info);
    TreeNode<int>* p;
    TreeNode<int>* q;
    p = q = root;
    while (*info != *(p->getInfo()) && q != NULL) {
        if (*info < *(p->getInfo())) {
            p = q;
            q = p->getLeft();
        } else {
            p = q;
            q = p->getRight();
        }
    }
    if (*info == *(p->getInfo())) {
        cout << "try to add duplicate";
        // delete node;
        return;
    } else if (*info < *(p->getInfo())) {
        p->setLeft(node);
    } else {
        p->setRight(node);
    }
}

int main() {
    int x[] = {14, 15, 4, 9, 7, 18, 3, 5, 16, 4, 20, 17, 914, 5, -1};
    TreeNode<int>* root = new TreeNode<int>();
    root->setInfo(&x[0]);
    for (int i = 1; x[i] > 0; i++) {
        insert(root, &x[i]);
    }
    return 0;
}
